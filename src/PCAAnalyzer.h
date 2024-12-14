#ifndef PCA_ANALYZER_H
#define PCA_ANALYZER_H

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkPolyData.h>

class PCAAnalyzer {
public:
    void Analyze(vtkSmartPointer<vtkPolyData> slicedData);
    vtkSmartPointer<vtkActor> GetPCAActors();

private:
    vtkSmartPointer<vtkActor> pcaActor;
};

#endif
