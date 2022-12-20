#include "vtkSMRemoteObject2.h"

#include "vtkObjectFactory.h"
// b #include "vtkProcessModule2.h"
// b #include "vtkSMMessage2.h"
// b #include "vtkSMSession2.h"

#include <sstream>
#include <vtksys/SystemTools.hxx>

//----------------------------------------------------------------------------
vtkSMRemoteObject::vtkSMRemoteObject()
{
  this->GlobalID = 0;
  this->GlobalIDString = nullptr;
  this->Location = 0;
  // b this->Session = nullptr;
  this->Prototype = false;
  this->ClientOnlyLocationFlag = false;
}

//----------------------------------------------------------------------------
vtkSMRemoteObject::~vtkSMRemoteObject()
{
    /* b
  if (this->Session && this->GlobalID != 0)
  {
    this->Session->UnRegisterRemoteObject(this->GlobalID, this->Location);
  }
  this->SetSession(nullptr);
  delete[] this->GlobalIDString;
  this->GlobalIDString = nullptr;
  */
}
/* b
//----------------------------------------------------------------------------
void vtkSMRemoteObject::SetSession(vtkSMSession* session)
{
  this->Superclass::SetSession(session);
  // Register object if possible
  if (this->Session && this->GlobalID != 0)
  {
    this->Session->RegisterRemoteObject(this->GlobalID, this->Location, this);
  }
}
//----------------------------------------------------------------------------
void vtkSMRemoteObject::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "GlobalID: " << this->GlobalID << endl;
}
//---------------------------------------------------------------------------
bool vtkSMRemoteObject::HasGlobalID()
{
  return this->GlobalID != 0;
}
*/
//---------------------------------------------------------------------------
vtkTypeUInt32 vtkSMRemoteObject::GetGlobalID()
{
    /* b
  if (this->Session != nullptr && this->GlobalID == 0)
  {
    this->SetGlobalID(this->GetSession()->GetNextGlobalUniqueIdentifier());
  }
  */
  return this->GlobalID;
}
/*
//---------------------------------------------------------------------------
const char* vtkSMRemoteObject::GetGlobalIDAsString()
{
  if (!this->GlobalIDString)
  {
    std::ostringstream cname;
    cname << this->GetGlobalID();

    delete[] this->GlobalIDString;
    this->GlobalIDString = vtksys::SystemTools::DuplicateString(cname.str().c_str());
  }

  return this->GlobalIDString;
}

//---------------------------------------------------------------------------
void vtkSMRemoteObject::SetGlobalID(vtkTypeUInt32 guid)
{
  if (this->GlobalID == guid)
  {
    return;
  }

  if (this->GlobalID != 0)
  {
    vtkErrorMacro("GlobalID must NOT be changed once it has been assigned.\n"
                  "Try to set "
      << guid << " to replace the current " << this->GlobalID << " value.");
    abort();
  }

  // Keep new ID
  this->GlobalID = guid;

  // Register object if possible
  if (this->Session && this->GlobalID != 0)
  {
    this->Session->RegisterRemoteObject(this->GlobalID, this->Location, this);
  }
}

//---------------------------------------------------------------------------
void vtkSMRemoteObject::PushState(vtkSMMessage* msg)
{
  vtkTypeUInt32 filteredLocation = this->GetFilteredLocation();
  if (filteredLocation == 0)
  {
    return; // This object is a prototype and has no location
  }

  // Check if a GUID has been assigned to that object otherwise assign a new one
  vtkTypeUInt32 gid = this->GetGlobalID();
  msg->set_global_id(gid);
  msg->set_location(filteredLocation);
  if (this->GetSession())
  {
    this->GetSession()->PushState(msg);
  }
  else
  {
    // no session, nothing to do.
  }
}

//---------------------------------------------------------------------------
bool vtkSMRemoteObject::PullState(vtkSMMessage* msg)
{
  if (this->Location == 0)
  {
    return true; // This object is a prototype and has no location
  }

  msg->set_global_id(this->GlobalID);
  msg->set_location(this->Location);
  if (this->GetSession())
  {
    this->GetSession()->PullState(msg);
  }
  else
  {
    vtkErrorMacro("Attempting to PullState() on a " << this->GetClassName()
                                                    << " after the session has been destroyed.");
    return false;
  }
  return true; // Successful call
}

//---------------------------------------------------------------------------
void vtkSMRemoteObject::EnableLocalPushOnly()
{
  this->ClientOnlyLocationFlag = true;
}

//---------------------------------------------------------------------------
void vtkSMRemoteObject::DisableLocalPushOnly()
{
  this->ClientOnlyLocationFlag = false;
}

//---------------------------------------------------------------------------
vtkTypeUInt32 vtkSMRemoteObject::GetFilteredLocation()
{
  if (this->ClientOnlyLocationFlag)
  {
    return (this->Location & vtkPVSession::CLIENT);
  }
  else
  {
    return this->Location;
  }
}
//---------------------------------------------------------------------------
vtkClientServerStream& operator<<(vtkClientServerStream& stream, const SIOBJECT& manipulator)
{
  vtkClientServerStream substream;
  substream << vtkClientServerStream::Invoke
            << vtkClientServerID(1) // ID for the vtkSMSessionCore helper.
            << "GetSIObject" << manipulator.Reference->GetGlobalID() << vtkClientServerStream::End;
  stream << substream;
  return stream;
}
*/