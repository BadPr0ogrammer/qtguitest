#include "vtkPVSession2.h"

#include "vtkObjectFactory.h"
// b #include "vtkPVProgressHandler.h"
// b #include "vtkPVServerInformation.h"

//----------------------------------------------------------------------------
vtkPVSession::vtkPVSession()
{
    /* b
  this->ProgressHandler = vtkPVProgressHandler::New();
  this->ProgressHandler->SetSession(this); // not reference counted.
  */
  this->ProgressCount = 0;
  this->InCleanupPendingProgress = false;
}

//----------------------------------------------------------------------------
vtkPVSession::~vtkPVSession()
{
    /* b
  this->ProgressHandler->SetSession(nullptr);
  this->ProgressHandler->Delete();
  this->ProgressHandler = nullptr;
  */
}

//----------------------------------------------------------------------------
vtkPVSession::ServerFlags vtkPVSession::GetProcessRoles()
{
  return CLIENT_AND_SERVERS;
}
/* b
//----------------------------------------------------------------------------
vtkMultiProcessController* vtkPVSession::GetController(vtkPVSession::ServerFlags)
{
  return nullptr;
}
*/
//----------------------------------------------------------------------------
bool vtkPVSession::GetPendingProgress()
{
  return (this->InCleanupPendingProgress || this->ProgressCount > 0);
}

//----------------------------------------------------------------------------
void vtkPVSession::PrepareProgress()
{
  if (this->InCleanupPendingProgress)
  {
    return;
  }

  if (this->ProgressCount++ == 0)
  {
    this->PrepareProgressInternal();
  }
}

//----------------------------------------------------------------------------
void vtkPVSession::CleanupPendingProgress()
{
  if (this->InCleanupPendingProgress)
  {
    return;
  }

  this->InCleanupPendingProgress = true;
  if (--this->ProgressCount == 0)
  {
    // b this->CleanupPendingProgressInternal();
  }
  if (this->ProgressCount < 0)
  {
    vtkErrorMacro("PrepareProgress and CleanupPendingProgress mismatch!");
    this->ProgressCount = 0;
  }
  this->InCleanupPendingProgress = false;
}

//----------------------------------------------------------------------------
void vtkPVSession::PrepareProgressInternal()
{
  // b this->ProgressHandler->PrepareProgress();
}

//----------------------------------------------------------------------------
/* b
void vtkPVSession::CleanupPendingProgressInternal()
{
  // b this->ProgressHandler->CleanupPendingProgress();
}
*/
//-----------------------------------------------------------------------------
bool vtkPVSession::OnWrongTagEvent(vtkObject*, unsigned long, void* calldata)
{
  int tag = -1;
  int len = -1;
  const char* data = reinterpret_cast<const char*>(calldata);
  const char* ptr = data;
  memcpy(&tag, ptr, sizeof(tag));

  if (tag == vtkPVSession::EXCEPTION_EVENT_TAG)
  {
    ptr += sizeof(tag);
    memcpy(&len, ptr, sizeof(len));
    ptr += sizeof(len);
    vtkErrorMacro("Encountered Exception: " << ptr);
    // this->OnSocketError();
  }
  else
  {
    vtkErrorMacro("Internal ParaView Error: "
                  "Socket Communicator received wrong tag: "
      << tag);
    // Treat as a socket error.
    // this->OnSocketError();
  }
  return false;
}
/* b
//----------------------------------------------------------------------------
void vtkPVSession::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
*/
//----------------------------------------------------------------------------
bool vtkPVSession::IsMultiClients()
{
  // b return (this->GetServerInformation()->GetMultiClientsEnable() != 0);
    return false;
}
