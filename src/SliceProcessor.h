#ifndef SLICE_PROCESSOR_H
#define SLICE_PROCESSOR_H

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkActor.h>

class SliceProcessor {
public:
    vtkSmartPointer<vtkPolyData> CutVoronoi(vtkSmartPointer<vtkPolyData> voronoiData);
    vtkSmartPointer<vtkActor> GetSliceActor();

private:
    vtkSmartPointer<vtkActor> sliceActor;
};

#endif
