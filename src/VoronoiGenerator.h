#ifndef VORONOI_GENERATOR_H
#define VORONOI_GENERATOR_H

#include <vtkSmartPointer.h>
#include <vtkActor.h>
#include <vtkPolyData.h>

class VoronoiGenerator {
public:
    vtkSmartPointer<vtkPolyData> GenerateVoronoi();
    vtkSmartPointer<vtkActor> GetActor();

private:
    vtkSmartPointer<vtkActor> voronoiActor;
};

#endif
