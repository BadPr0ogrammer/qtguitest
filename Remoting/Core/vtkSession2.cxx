#include "vtkSession2.h"

#include "vtkObjectFactory.h"

// b #include "vtkProcessModule.h"

//----------------------------------------------------------------------------
vtkSession::vtkSession() = default;

//----------------------------------------------------------------------------
vtkSession::~vtkSession() = default;

//----------------------------------------------------------------------------
void vtkSession::Activate()
{
    /* b
  if (vtkProcessModule* pm = vtkProcessModule::GetProcessModule())
  {
    pm->PushActiveSession(this);
  }*/
}

//----------------------------------------------------------------------------
void vtkSession::DeActivate()
{
    /* b
  if (vtkProcessModule* pm = vtkProcessModule::GetProcessModule())
  {
    pm->PopActiveSession(this);
  }*/
}
/* b
//----------------------------------------------------------------------------
void vtkSession::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
*/