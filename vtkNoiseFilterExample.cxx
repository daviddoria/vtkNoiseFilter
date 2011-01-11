#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkPlaneSource.h>
#include <vtkXMLPolyDataWriter.h>

#include "vtkNoiseFilter.h"

int main (int argc, char *argv[])
{
  vtkSmartPointer<vtkPolyData> input;

  /*
  vtkSmartPointer<vtkSphereSource> sphereSource =
      vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();
  input = sphereSource->GetOutput();
  */

  vtkSmartPointer<vtkPlaneSource> planeSource =
    vtkSmartPointer<vtkPlaneSource>::New();
  planeSource->SetXResolution(10);
  planeSource->SetYResolution(10);
  planeSource->Update();

  {
  vtkSmartPointer<vtkXMLPolyDataWriter> writer =
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName("input.vtp");
  writer->SetInputConnection(planeSource->GetOutputPort());
  writer->Write();
  }

  vtkSmartPointer<vtkNoiseFilter> noiseFilter =
    vtkSmartPointer<vtkNoiseFilter>::New();
  noiseFilter->SetInputConnection(planeSource->GetOutputPort());
  noiseFilter->SetNoiseVariance(0.05);
  noiseFilter->Update();

  {
  vtkSmartPointer<vtkXMLPolyDataWriter> writer =
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName("output.vtp");
  writer->SetInputConnection(noiseFilter->GetOutputPort());
  writer->Write();
  }

  return EXIT_SUCCESS;
}
