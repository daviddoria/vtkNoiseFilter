#ifndef __vtkNoiseFilter_h
#define __vtkNoiseFilter_h

#include "vtkPolyDataAlgorithm.h"

class vtkNoiseFilter : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro(vtkNoiseFilter,vtkPolyDataAlgorithm);
  static vtkNoiseFilter *New();

  vtkSetMacro(NoiseVariance, double);

protected:
  vtkNoiseFilter(){}
  ~vtkNoiseFilter(){}

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

private:
  vtkNoiseFilter(const vtkNoiseFilter&);  // Not implemented.
  void operator=(const vtkNoiseFilter&);  // Not implemented.

  double NoiseVariance;
};

#endif
