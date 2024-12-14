#include "VoronoiGenerator.h"
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <itkDanielssonDistanceMapImageFilter.h>
#include <itkImageToVTKImageFilter.h>
#include <vtkPolyDataMapper.h>

vtkSmartPointer<vtkPolyData> VoronoiGenerator::GenerateVoronoi() {
    // 创建随机点
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (int i = 0; i < 10; ++i) {
        points->InsertNextPoint(rand() % 100, rand() % 100, rand() % 100);
    }

    // Voronoi生成逻辑省略...
    // 转换为vtkPolyData
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);
    return polyData;
}

vtkSmartPointer<vtkActor> VoronoiGenerator::GetActor() {
    // 创建映射和渲染器
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(this->GenerateVoronoi());

    voronoiActor = vtkSmartPointer<vtkActor>::New();
    voronoiActor->SetMapper(mapper);
    return voronoiActor;
}
