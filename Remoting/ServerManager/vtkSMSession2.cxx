// Hide PARAVIEW_DEPRECATED_IN_5_10_0() warnings for this class.
#define PARAVIEW_DEPRECATION_LEVEL 0

#include "vtkSMSession2.h"

#include "vtkCommand.h"
#include "vtkDebugLeaks.h"
#include "vtkLegacy.h"
#include "vtkObjectFactory.h"
#include "vtkWeakPointer.h"

#include "vtkSMProxy2.h"
/* b
#include "vtkSMProxyManager2.h"
#include "vtkSMSessionProxyManager2.h"
#include "vtkSMPropertyHelper2.h"
#include "vtkPVCatalystSessionCore.h"
#include "vtkPVServerInformation.h"
#include "vtkProcessModule.h"
#include "vtkReservedRemoteObjectIds.h"
#include "vtkSMDeserializerProtobuf.h"
#include "vtkSMMessage.h"
#include "vtkSMPluginManager.h"
#include "vtkSMProxyLocator.h"
#include "vtkSMSessionClient.h"
#include "vtkSMStateLocator.h"
#include "vtkSMUndoStackBuilder.h"
*/

#include <cassert>
#include <sstream>
#include <vtkNew.h>

vtkStandardNewMacro(vtkSMSession);
//----------------------------------------------------------------------------
vtkSMSession* vtkSMSession::New(vtkPVSessionBase* otherSession)
{
  // b return vtkSMSession::New(otherSession->GetSessionCore());
  return vtkSMSession::New();
}
//----------------------------------------------------------------------------
/* b
vtkSMSession* vtkSMSession::New(vtkPVSessionCore* otherSessionCore)
{
  vtkSMSession* session = new vtkSMSession(true, otherSessionCore);
  session->InitializeObjectBase();
  return session;
}
*/
//----------------------------------------------------------------------------
vtkSMSession::vtkSMSession(bool initialize_during_constructor) //=true,
  // b vtkPVSessionCore* preExistingSessionCore //=nullptr)
  : vtkPVSessionBase()//vtkPVSessionBase(preExistingSessionCore ? preExistingSessionCore : vtkPVSessionCore::New()
{
  /* b
  if (!preExistingSessionCore)
  {
    this->SessionCore->UnRegister(nullptr);
  }

  this->SessionProxyManager = nullptr;
  this->StateLocator = vtkSMStateLocator::New();

  // Create and setup deserializer for the local ProxyLocator
  vtkNew<vtkSMDeserializerProtobuf> deserializer;
  deserializer->SetStateLocator(this->StateLocator);

  // Create and setup proxy locator
  this->ProxyLocator = vtkSMProxyLocator::New();
  this->ProxyLocator->SetDeserializer(deserializer.GetPointer());
  this->ProxyLocator->UseSessionToLocateProxy(true);

  // don't set the session on ProxyLocator right now since the
  // SessionProxyManager is not setup until Initialize().
  // we will initialize it in this->Initialize().
  */
  if (initialize_during_constructor)
  {
    this->Initialize();
  }
}

//----------------------------------------------------------------------------
vtkSMSession::~vtkSMSession()
{
    /* b
  if (vtkSMProxyManager::IsInitialized())
  {
    vtkSMProxyManager::GetProxyManager()->GetPluginManager()->UnRegisterSession(this);
  }

  this->StateLocator->Delete();
  this->ProxyLocator->Delete();
  if (this->SessionProxyManager)
  {
    this->SessionProxyManager->Delete();
    this->SessionProxyManager = nullptr;
  }
  */
}

//----------------------------------------------------------------------------
vtkSMSession::ServerFlags vtkSMSession::GetProcessRoles()
{
  // b if (vtkProcessModule::GetProcessModule() && vtkProcessModule::GetProcessModule()->GetPartitionId() > 0 && !vtkProcessModule::GetProcessModule()->GetSymmetricMPIMode())
  {
    return vtkPVSession::SERVERS;
  }

  return vtkPVSession::CLIENT_AND_SERVERS;
}
/* b
//----------------------------------------------------------------------------
void vtkSMSession::PushState(vtkSMMessage* msg)
{
  // Manage Undo/Redo if possible
  this->UpdateStateHistory(msg);

  this->Superclass::PushState(msg);
}

//----------------------------------------------------------------------------
void vtkSMSession::UpdateStateHistory(vtkSMMessage* msg)
{
  // check is global-undo-stack builder is set.
  vtkSMUndoStackBuilder* usb = vtkSMProxyManager::GetProxyManager()->GetUndoStackBuilder();

  if (usb == nullptr || (this->GetProcessRoles() & vtkPVSession::CLIENT) == 0)
  {
    return;
  }

  vtkTypeUInt32 globalId = msg->global_id();
  vtkSMRemoteObject* remoteObj = vtkSMRemoteObject::SafeDownCast(this->GetRemoteObject(globalId));

  if (remoteObj && !remoteObj->IsPrototype() && remoteObj->GetFullState())
  {
    vtkSMMessage newState;
    newState.CopyFrom(*remoteObj->GetFullState());

    // Need to provide id/location as the full state may not have them yet
    newState.set_global_id(globalId);
    newState.set_location(msg->location());

    // Store state in cache
    vtkSMMessage oldState;
    bool createAction = !this->StateLocator->FindState(globalId, &oldState,
      // We want only a local lookup => false 
false);

    // This is a filtering Hack, I don't like it. :-(
    if (newState.GetExtension(ProxyState::xml_name) != "Camera")
    {
      this->StateLocator->RegisterState(&newState);
    }

    // Propagate to undo stack builder if possible
    if (createAction)
    {
      usb->OnCreateObject(this, &newState);
    }
    else if (oldState.SerializeAsString() != newState.SerializeAsString())
    {
      // Update
      usb->OnStateChange(this, globalId, &oldState, &newState);
    }
  }
}
*/
//----------------------------------------------------------------------------
void vtkSMSession::Initialize()
{
  // b assert(this->SessionProxyManager == nullptr);

  // Remember, although vtkSMSession is always only created on the client side,
  // in batch mode, vtkSMSession is created on all nodes.

  // All these initializations need to be done on all nodes in symmetric-batch
  // mode. In non-symmetric-batch mode. Which means we are a CLIENT,
  // so if we are not then we stop the initialisation here !
  if (!(this->GetProcessRoles() & vtkPVSession::CLIENT))
  {
    return;
  }

  // Initialize the proxy manager.
  // this updates proxy definitions if we are connected to a remote server.
  // b this->SessionProxyManager = vtkSMSessionProxyManager::New(this);
  // b this->ProxyLocator->SetSession(this);

  // Initialize the plugin manager.
  // b vtkSMProxyManager::GetProxyManager()->GetPluginManager()->RegisterSession(this);
}

//----------------------------------------------------------------------------
int vtkSMSession::GetNumberOfProcesses(vtkTypeUInt32 servers)
{
  (void)servers;
  // b return vtkProcessModule::GetProcessModule()->GetNumberOfLocalPartitions();
  return 0;
}

//----------------------------------------------------------------------------
bool vtkSMSession::IsMPIInitialized(vtkTypeUInt32)
{
  // b return vtkProcessModule::GetProcessModule()->IsMPIInitialized();
    return 0;
}
/* b
//----------------------------------------------------------------------------
void vtkSMSession::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
*/
//----------------------------------------------------------------------------
void vtkSMSession::Disconnect(vtkSMSession* session)
{
  if (!session)
  {
    return;
  }

  if (session->IsMultiClients())
  {
    // Ensure that the session no longer sends state updates to the server-side.
    // This is critical to ensure we don't mess up the collaboration state.
    session->PreDisconnection();
  }

  // Unregister all proxies.
  // b session->GetSessionProxyManager()->UnRegisterProxies();

  // b vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
  // b pm->UnRegisterSession(session);
  // Although I'd like to have this check, when Disconnect() is called from
  // Python, we have 1 reference that gets cleared with the Python call returns.
  // if (session != nullptr)
  //  {
  //  vtkGenericWarningMacro(
  //    "vtkSMSession wasn't destroyed after UnRegisterSession. "
  //    "This indicates a development problem. Please notify the "
  //    "developers.");
  //  }
}

//----------------------------------------------------------------------------
void vtkSMSession::Disconnect(vtkIdType sid)
{
  // b vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
  // b vtkWeakPointer<vtkSMSession> session = vtkSMSession::SafeDownCast(pm->GetSession(sid));
  // b if (!session)
  {
    vtkGenericWarningMacro("Failed to locate session " << sid << ". Cannot disconnect.");
    return;
  }

  // b vtkSMSession::Disconnect(session);
}

//----------------------------------------------------------------------------
vtkIdType vtkSMSession::ConnectToSelf()
{
  // b vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
  vtkSMSession* session = vtkSMSession::New();
  // b const vtkIdType sid = pm->RegisterSession(session);
  session->Delete();
  // b return sid;
  return 0;
}

//----------------------------------------------------------------------------
vtkIdType vtkSMSession::ConnectToCatalyst()
{
  // b vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
  vtkIdType sid = 0;
  // b vtkNew<vtkPVCatalystSessionCore> sessionCore;
  vtkSMSession* session = vtkSMSession::New();// b sessionCore.GetPointer());
  // b sid = pm->RegisterSession(session);
  session->Delete();
  return sid;
}
/* b
//----------------------------------------------------------------------------
vtkIdType vtkSMSession::ConnectToRemote(const char* hostname, int port, int timeout,
  bool (*callback)(), vtkNetworkAccessManager::ConnectionResult& result)
{
  std::ostringstream sname;
  sname << "cs://" << hostname << ":" << port;
  vtkSMSessionClient* session = vtkSMSessionClient::New();

  vtkIdType sid = 0;
  if (session->Connect(sname.str().c_str(), timeout, callback, result))
  {
    vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
    sid = pm->RegisterSession(session);
  }
  session->Delete();
  return sid;
}
*/
//----------------------------------------------------------------------------
vtkIdType vtkSMSession::ConnectToRemote(const char* dshost, int dsport, const char* rshost,
  int rsport, int timeout, bool (*callback)(), vtkNetworkAccessManager::ConnectionResult& result)
{
    /* b
  std::ostringstream sname;
  sname << "cdsrs://" << dshost << ":" << dsport << "/" << rshost << ":" << rsport;
  vtkSMSessionClient* session = vtkSMSessionClient::New();
  vtkIdType sid = 0;
  if (session->Connect(sname.str().c_str(), timeout, callback, result))
  {
    vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
    sid = pm->RegisterSession(session);
  }
  session->Delete();
  return sid;
  */
    return 0;
}

//----------------------------------------------------------------------------
vtkIdType vtkSMSession::ReverseConnectToRemote(
  int port, int timeout, bool (*callback)(), vtkNetworkAccessManager::ConnectionResult& result)
{
  return vtkSMSession::ReverseConnectToRemote(port, -1, timeout, callback, result);
}

//----------------------------------------------------------------------------
vtkIdType vtkSMSession::ReverseConnectToRemote(int dsport, int rsport, int timeout,
  bool (*callback)(), vtkNetworkAccessManager::ConnectionResult& result)
{
    /* b
  std::ostringstream sname;
  if (rsport <= -1)
  {
    sname << "csrc://localhost:" << dsport;
  }
  else
  {
    sname << "cdsrsrc://localhost:" << dsport << "/localhost:" << rsport;
  }

  vtkSMSessionClient* session = vtkSMSessionClient::New();
  vtkIdType sid = 0;
  if (session->Connect(sname.str().c_str(), timeout, callback, result))
  {
    vtkProcessModule* pm = vtkProcessModule::GetProcessModule();
    sid = pm->RegisterSession(session);
  }
  session->Delete();
  return sid;
  */
    return 0;
}
//----------------------------------------------------------------------------
unsigned int vtkSMSession::GetRenderClientMode()
{
    /* b
  if (this->GetController(vtkPVSession::DATA_SERVER_ROOT) != this->GetController(vtkPVSession::RENDER_SERVER_ROOT))
  {
    // when the two controller are different, we have a separate render-server
    // and data-server session.
    return vtkSMSession::RENDERING_SPLIT;
  }
  */
  return vtkSMSession::RENDERING_UNIFIED;
}
/* b
//----------------------------------------------------------------------------
void vtkSMSession::ProcessNotification(const vtkSMMessage* message)
{
  vtkTypeUInt32 id = message->global_id();

  // Find the object for whom this message is meant.
  vtkSMRemoteObject* remoteObj = vtkSMRemoteObject::SafeDownCast(this->GetRemoteObject(id));

  // cout << "##########     Server notification    ##########" << endl;
  // cout << id << " = " << remoteObj << "(" << (remoteObj?
  //    remoteObj->GetClassName() : "null") << ")" << endl;
  // state.PrintDebugString();
  // cout << "###################################################" << endl;

  // ProcessingRemoteNotification = true prevent
  // "ignore_synchronization" properties to be loaded...
  // Therefore camera properties won't be shared
  // (I don't understand this comment, but copying it from the original code).
  if (remoteObj)
  {
    bool previousValue = this->StartProcessingRemoteNotification();
    remoteObj->EnableLocalPushOnly();
    remoteObj->LoadState(message, this->GetProxyLocator());

    vtkSMProxy* proxy = vtkSMProxy::SafeDownCast(remoteObj);
    if (proxy)
    {
      proxy->UpdateVTKObjects();
    }

    remoteObj->DisableLocalPushOnly();
    this->StopProcessingRemoteNotification(previousValue);
  }
}
*/
//----------------------------------------------------------------------------
bool vtkSMSession::GetIsAutoMPI() const
{
  VTK_LEGACY_BODY(vtkMyClass::GetIsAutoMPI, "ParaView 5.10");
  return false;
}
