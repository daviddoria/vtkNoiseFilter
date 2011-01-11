#include "vtkNoiseFilter.h"

#include "vtkObjectFactory.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkInformationVector.h"
#include "vtkInformation.h"

#include "vtkMath.h"
#include "vtkPolyData.h"
#include "vtkSmartPointer.h"

vtkStandardNewMacro(vtkNoiseFilter);

int vtkNoiseFilter::RequestData(
  vtkInformation *vtkNotUsed(request),
  vtkInformationVector **inputVector,
  vtkInformationVector *outputVector)
{
  // get the input and ouptut
  vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
  vtkPolyData *input = vtkPolyData::SafeDownCast(
      inInfo->Get(vtkDataObject::DATA_OBJECT()));

  vtkInformation *outInfo = outputVector->GetInformationObject(0);
  vtkPolyData *output = vtkPolyData::SafeDownCast(
		  outInfo->Get(vtkDataObject::DATA_OBJECT()));

  vtkMath::RandomSeed(time(NULL));

  output->ShallowCopy(input);

  vtkSmartPointer<vtkPoints> newPoints =
      vtkSmartPointer<vtkPoints>::New();

  for(vtkIdType i = 0; i < output->GetNumberOfPoints(); i++)
    {
    double p[3];
    output->GetPoint(i,p);
    for(int v = 0; v < 3; v++)
      {
      double a = vtkMath::Random(-this->NoiseVariance,this->NoiseVariance);
      p[v] = p[v] + a;
      }
    newPoints->InsertNextPoint(p);
    }

  output->SetPoints(newPoints);

  return 1;
}
