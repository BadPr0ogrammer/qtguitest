#include "vtkSMObject.h"

#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkSMObject);
//---------------------------------------------------------------------------
vtkSMObject::vtkSMObject() = default;

//---------------------------------------------------------------------------
vtkSMObject::~vtkSMObject() = default;

//---------------------------------------------------------------------------
void vtkSMObject::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
