#include "vtkObjectFactoryCollection2.h"

#include "vtkDebugLeaks2.h"
#include "vtkObjectFactory2.h"

vtkObjectFactoryCollection* vtkObjectFactoryCollection::New()
{
  // Don't use the object factory macros. Creating an object factory here
  // will cause an infinite loop.
  vtkObjectFactoryCollection* ret = new vtkObjectFactoryCollection;
  ret->InitializeObjectBase();
  return ret;
}

void vtkObjectFactoryCollection::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
