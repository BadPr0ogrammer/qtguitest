#include "vtkOverrideInformation2.h"

#include "vtkObjectFactory2.h"

vtkStandardNewMacro(vtkOverrideInformation);
vtkCxxSetObjectMacro(vtkOverrideInformation, ObjectFactory, vtkObjectFactory);

vtkOverrideInformation::vtkOverrideInformation()
{
  this->ClassOverrideName = nullptr;
  this->ClassOverrideWithName = nullptr;
  this->Description = nullptr;
  this->ObjectFactory = nullptr;
}

vtkOverrideInformation::~vtkOverrideInformation()
{
  delete[] this->ClassOverrideName;
  delete[] this->ClassOverrideWithName;
  delete[] this->Description;
  if (this->ObjectFactory)
  {
    this->ObjectFactory->Delete();
  }
}

void vtkOverrideInformation::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Override: ";
  if (this->ClassOverrideName && this->ClassOverrideWithName && this->Description)
  {
    os << this->ClassOverrideName << "\nWith: " << this->ClassOverrideWithName
       << "\nDescription: " << this->Description;
  }
  else
  {
    os << "(none)\n";
  }

  os << indent << "From Factory:\n";
  if (this->ObjectFactory)
  {
    this->ObjectFactory->PrintSelf(os, indent.GetNextIndent());
  }
  else
  {
    vtkIndent n = indent.GetNextIndent();
    os << n << "(none)\n";
  }
}
