#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include "VoronoiGenerator.h"
#include "SliceProcessor.h"
#include "PCAAnalyzer.h"

int main() {
    // 生成Voronoi图
    VoronoiGenerator voronoiGen;
    auto voronoiData = voronoiGen.GenerateVoronoi();

    // 任意剖切Voronoi图
    SliceProcessor slicer;
    auto slicedData = slicer.CutVoronoi(voronoiData);

    // PCA分析Voronoi区域
    PCAAnalyzer pcaAnalyzer;
    pcaAnalyzer.Analyze(slicedData);

    // 可视化结果
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(voronoiGen.GetActor());
    renderer->AddActor(slicer.GetSliceActor());
    renderer->AddActor(pcaAnalyzer.GetPCAActors());

    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(renderWindow);
    renderWindow->Render();
    interactor->Start();

    return 0;
}
