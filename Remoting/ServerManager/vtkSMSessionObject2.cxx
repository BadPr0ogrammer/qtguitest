#include "vtkSMSessionObject2.h"

#include "vtkObjectFactory.h"

// b #include "vtkSMProxyManager2.h"
// b #include "vtkSMSession2.h"
// b #include "vtkSMSessionProxyManager.h"

//---------------------------------------------------------------------------
vtkSMSessionObject::vtkScopedMonitorProgress::vtkScopedMonitorProgress(vtkSMSessionObject* parent)
  : Parent(parent)
{
  /* b
  if (this->Parent && this->Parent->GetSession())
  {
    this->Parent->GetSession()->PrepareProgress();
  }*/
}

//---------------------------------------------------------------------------
vtkSMSessionObject::vtkScopedMonitorProgress::~vtkScopedMonitorProgress()
{
  /* b
  if (this->Parent && this->Parent->GetSession())
  {
    this->Parent->GetSession()->CleanupPendingProgress();
  }*/
}

vtkStandardNewMacro(vtkSMSessionObject);
//---------------------------------------------------------------------------
vtkSMSessionObject::vtkSMSessionObject() = default;

//---------------------------------------------------------------------------
vtkSMSessionObject::~vtkSMSessionObject() = default;

/* b
//----------------------------------------------------------------------------
vtkSMSessionProxyManager* vtkSMSessionObject::GetSessionProxyManager()
{
  return vtkSMProxyManager::GetProxyManager()->GetSessionProxyManager(this->Session);
}

//----------------------------------------------------------------------------
vtkSMSession* vtkSMSessionObject::GetSession()
{
  return this->Session;
}

//----------------------------------------------------------------------------
void vtkSMSessionObject::SetSession(vtkSMSession* session)
{
  if (this->Session != session)
  {
    this->Session = session;
    this->Modified();
  }
}

//---------------------------------------------------------------------------
void vtkSMSessionObject::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "Session: " << this->Session << endl;
}
*/