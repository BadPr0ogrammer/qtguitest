#include "vtkVersion.h"
#include "vtkObjectFactory.h"
#include "vtkVersionFull.h"

vtkStandardNewMacro(vtkVersion);

void vtkVersion::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

const char* vtkVersion::GetVTKVersionFull()
{
  // Since VTK_VERSION_FULL changes with every commit, it is kept out of the
  // header file to avoid excessive rebuilds.
  return VTK_VERSION_FULL;
}

const char* GetVTKVersion()
{
  return vtkVersion::GetVTKVersion();
}
