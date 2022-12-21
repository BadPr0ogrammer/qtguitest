#include "vtkPVInformation2.h"

//----------------------------------------------------------------------------
vtkPVInformation::vtkPVInformation()
{
  this->RootOnly = 0;
}

//----------------------------------------------------------------------------
vtkPVInformation::~vtkPVInformation() = default;
/* b
//----------------------------------------------------------------------------
void vtkPVInformation::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "RootOnly: " << this->RootOnly << endl;
}
*/
//----------------------------------------------------------------------------
void vtkPVInformation::CopyFromObject(vtkObject*)
{
  vtkErrorMacro("CopyFromObject not implemented.");
}

//----------------------------------------------------------------------------
void vtkPVInformation::AddInformation(vtkPVInformation*)
{
  vtkErrorMacro("AddInformation not implemented.");
}
/* b
//----------------------------------------------------------------------------
void vtkPVInformation::CopyFromStream(const vtkClientServerStream*)
{
  vtkErrorMacro("CopyFromStream not implemented.");
}
*/