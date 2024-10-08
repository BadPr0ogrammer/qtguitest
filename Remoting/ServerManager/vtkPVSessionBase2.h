/**
 * @class   vtkPVSessionBase
 *
 * Abstract class used to provide the main implementation of the ParaView
 * session methods for the following classes: vtkSMSession,
 *                                            vtkSMSessionClient,
 *                                            vtkSMSessionServer
 */

#ifndef vtkPVSessionBase_h
#define vtkPVSessionBase_h

#include "vtkPVSession2.h"
#include "vtkRemotingServerManagerModule.h" //needed for exports
// b #include "vtkSMMessageMinimal.h"            // needed for vtkSMMessage

class vtkCollection;
/* b 
class vtkClientServerStream;
class vtkSIObject;
class vtkPVInformation;
class vtkPVServerInformation;
class vtkSIProxyDefinitionManager;
class vtkPVSessionCore;
*/
class VTKREMOTINGSERVERMANAGER_EXPORT vtkPVSessionBase : public vtkPVSession
{
public:
  vtkTypeMacro(vtkPVSessionBase, vtkPVSession);
  // b void PrintSelf(ostream& os, vtkIndent indent) override;

  enum EventIds
  {
    RegisterRemoteObjectEvent = 1234,
    UnRegisterRemoteObjectEvent = 4321,
    ProcessingRemoteEnd = 2143,
    ConnectionLost = 6789
  };

  //---------------------------------------------------------------------------
  // Superclass Implementations
  //---------------------------------------------------------------------------

  /**
   * Returns a ServerFlags indicate the nature of the current processes. e.g. if
   * the current processes acts as a data-server and a render-server, it returns
   * DATA_SERVER | RENDER_SERVER. The implementation provided is suitable for
   * server processes such as pvserver, pvdataserver (both root and satellites).
   */
  ServerFlags GetProcessRoles() override;

  /**
   * vtkPVServerInformation is an information-object that provides information
   * about the server processes. These include server-side capabilities as well
   * as server-side command line arguments e.g. tile-display parameters. Use
   * this method to obtain the server-side information.
   * Overridden to provide support for non-remote-server case. We simply read
   * the local process information and return it.
   */
  // b vtkPVServerInformation* GetServerInformation() override;

  /**
   * This is socket connection, if any to communicate between the data-server
   * and render-server nodes. Forwarded for vtkPVSessionCore.
   */
  // b vtkMPIMToNSocketConnection* GetMPIMToNSocketConnection() override;

  //---------------------------------------------------------------------------
  // Remote communication API. This API is used for communication in the
  // CLIENT -> SERVER(s) direction.
  //---------------------------------------------------------------------------

  /**
   * Push the state message.
   */
  // b virtual void PushState(vtkSMMessage* msg);

  /**
   * Pull the state message.
   */
  // b virtual void PullState(vtkSMMessage* msg);

  /**
   * Execute a command on the given processes. Use GetLastResult() to obtain the
   * last result after the command stream is evaluated. Once can set
   * \c ignore_errors to true, to ignore any interpreting errors.
   */
  // b virtual void ExecuteStream(vtkTypeUInt32 location, const vtkClientServerStream& stream, bool ignore_errors = false);

  /**
   * Returns the response of the ExecuteStream() call from the location. Note if
   * location refers to multiple processes, then the reply is only fetched from
   * the "closest" process.
   */
  // b virtual const vtkClientServerStream& GetLastResult(vtkTypeUInt32 location);

  /**
   * Gather information about an object referred by the \c globalid.
   * \c location identifies the processes to gather the information from.
   */
  // b virtual bool GatherInformation(vtkTypeUInt32 location, vtkPVInformation* information, vtkTypeUInt32 globalid);

  //---------------------------------------------------------------------------
  // Remote communication API. This API is used for communication in the
  // SERVER -> CLIENT direction. Since satellite nodes cannot communicate with
  // the client, these methods have no effect on the satellite nodes and must
  // only the called on the root-nodes for the server processes.
  // If these methods are called on a process acting as a client, then it is
  // processed on that process immediately, as appropriate.
  //---------------------------------------------------------------------------

  /**
   * Sends the message to all clients.
   */
  // b virtual void NotifyAllClients(const vtkSMMessage*) = 0;

  /**
   * Sends the message to all but the active client-session.
   */
  // b virtual void NotifyOtherClients(const vtkSMMessage*) = 0;

  //---------------------------------------------------------------------------
  // API dealing with/forwarded to vtkPVSessionCore dealing with SIObjects and
  // SMObjects.
  //---------------------------------------------------------------------------

  //@{
  /**
   * Provides access to the session core.
   */
  // b vtkGetObjectMacro(SessionCore, vtkPVSessionCore);
  //@}

  /**
   * Get the ProxyDefinitionManager.
   */
  // b vtkSIProxyDefinitionManager* GetProxyDefinitionManager();

  /**
   * Returns a vtkSIObject or subclass given its global id, if any.
   */
  // b vtkSIObject* GetSIObject(vtkTypeUInt32 globalid);

  /**
   * Unregister server side object. (SIObject)
   */
  // b virtual void UnRegisterSIObject(vtkSMMessage* msg);

  /**
   * Register server side object. (SIObject)
   */
  // b virtual void RegisterSIObject(vtkSMMessage* msg);

  /**
   * Return a vtkSMRemoteObject given its global id if any otherwise return nullptr;
   */
  vtkObject* GetRemoteObject(vtkTypeUInt32 globalid);

  /**
   * Allow the user to fill its vtkCollection with all RemoteObject
   * This could be useful when you want to hold a reference to them to
   * prevent any deletion across several method call.
   */
  // b virtual void GetAllRemoteObjects(vtkCollection* collection);

  //---------------------------------------------------------------------------
  // API for GlobalId management
  //---------------------------------------------------------------------------

  /**
   * Provides the next available identifier. This implementation works locally.
   * without any code distribution. To support the distributed architecture
   * the vtkSMSessionClient override those method to call them on the DATA_SERVER
   * vtkPVSessionBase instance.
   */
  // b virtual vtkTypeUInt32 GetNextGlobalUniqueIdentifier();

  /**
   * Return the first Id of the requested chunk.
   * 1 = ReverveNextIdChunk(10); | Reserved ids [1,2,3,4,5,6,7,8,9,10]
   * 11 = ReverveNextIdChunk(10);| Reserved ids [11,12,13,14,15,16,17,18,19,20]
   * b = a + 10;
   */
  // b virtual vtkTypeUInt32 GetNextChunkGlobalUniqueIdentifier(vtkTypeUInt32 chunkSize);

  /**
   * This property is used to discard ignore_synchronization proxy property
   * when we load protobuf states.
   * Therefore, if we load any camera state while that property is true, this
   * won't affect the proxy/property state at all. It will simply remain the same.
   */
  // b virtual bool IsProcessingRemoteNotification();

  /**
   * Update internal session core in order to use the one used in another session
   */
  // b virtual void UseSessionCoreOf(vtkPVSessionBase* other);

protected:
  vtkPVSessionBase();
  // b vtkPVSessionBase(vtkPVSessionCore* coreToUse);
  // b ~vtkPVSessionBase() override;

  //@{
  /**
   * Method used to migrate from one Session type to another by keeping the same
   * vtkPVSessionCore
   */
  // b vtkPVSessionCore* GetSessionCore() const;
  // b void SetSessionCore(vtkPVSessionCore*);
  //@}

  //@{
  /**
   * Should be called to begin/end receiving progresses on this session.
   * Overridden to relay to the server(s).
   */
  // b void PrepareProgressInternal() override;
  // b void CleanupPendingProgressInternal() override;
  //@}

  friend class vtkSMRemoteObject;
  friend class vtkSMSessionProxyManager;
  friend class vtkSMLiveInsituLinkProxy; // Needed to get access to vtkPVCatalystSessionCore

  //@{
  /**
   * Methods used to monitor if we are currently processing a server notification
   * Only vtkSMSessionClient use the flag to disable ignore_synchronization
   * properties from being updated.
   */
  // b virtual bool StartProcessingRemoteNotification();
  // b virtual void StopProcessingRemoteNotification(bool previousValue);
  bool ProcessingRemoteNotification;
  //@}

  /**
   * Register a remote object
   */
  void RegisterRemoteObject(vtkTypeUInt32 globalid, vtkTypeUInt32 location, vtkObject* obj);

  /**
   * Unregister a remote object
   */
  void UnRegisterRemoteObject(vtkTypeUInt32 globalid, vtkTypeUInt32 location);

  // b vtkPVSessionCore* SessionCore;

private:
  vtkPVSessionBase(const vtkPVSessionBase&) = delete;
  void operator=(const vtkPVSessionBase&) = delete;

  // Shared constructor method
  // b void InitSessionBase(vtkPVSessionCore* coreToUse);

  // b vtkPVServerInformation* LocalServerInformation;
  unsigned long ActivateObserverTag;
  unsigned long DesactivateObserverTag;
};

#endif
