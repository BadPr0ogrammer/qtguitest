#ifndef pqApplicationCore_h
#define pqApplicationCore_h

#include "pqCoreModule.h"
#include "vtkParaViewDeprecation2.h" // for PARAVIEW_DEPRECATED_IN_5_10_0
#include "vtkSmartPointer.h"        // for vtkSmartPointer
#include <QObject>
#include <QPointer>
#include <exception> // for std::exception
/*
class pqPipelineSource;
class pqPluginManager;
class pqProgressManager;
class pqRecentlyUsedResourcesList;
class pqTestUtility;
class QHelpEngine;
class QStringList;
class vtkSMProxyLocator;
class vtkSMStateLoader;
class vtkCLIOptions;
class pqLinksModel;
class pqOptions;
class pqUndoStack;
class pqObjectBuilder;
class pqServerConfigurationCollection;
class pqServerManagerModel;
class pqServerManagerObserver;
class pqInterfaceTracker;
*/
class QApplication;
class pqMainWindowEventManager;
class pqServer;
class pqServerResource;
class vtkPVXMLElement;
class pqSettings;


class PQCORE_EXPORT pqApplicationCoreExitCode : public std::exception
{
  int Code = 0;

public:
  pqApplicationCoreExitCode(int ecode)
    : Code(ecode)
  {
  }
  int code() const { return this->Code; }
};

/**
 * This class is the crux of the ParaView application. It creates
 * and manages various managers which are necessary for the ParaView-based
 * client to work with the ServerManager.
 * For clients based of the pqCore library,
 * simply instantiate this pqApplicationCore after QApplication initialization
 * and then create your main window etc. like a standard Qt application. You can then
 * use the facilities provided by pqCore such as the pqObjectBuilder,
 * pqUndoStack etc. in your application. After that point.
 */
class PQCORE_EXPORT pqApplicationCore : public QObject
{
  Q_OBJECT
  typedef QObject Superclass;

public:
  // Get the global instance for the pqApplicationCore.
  static pqApplicationCore* instance();

  /**
   * Initializes the ParaView application engine. `vtkCLIOptions` may be provide
   * if the application wants to customize command line argument processing. By
   * default all standard ParaView-specific command line arguments will be
   * supported. To avoid that, simply pass `addStandardArgs=false`.
   *
   * @note This constructor may raise `pqApplicationCoreExitCode` exception
   * if the initialization process was short circuited and the application should
   * simply quit.
   *
   * @note If `options` is nullptr, an vtkCLIOptions instance will be
   * created and used. It is also setup to accept extra / unknown arguments
   * without raising errors.
   */
  pqApplicationCore(int& argc, char** argv, // b vtkCLIOptions* options = nullptr,
    bool addStandardArgs = true, QObject* parent = nullptr);

  ///@{
  /**
   * @deprecated in ParaView 5.10. pqOptions has been replaced by vtkCLIOptions
   * based command line parsing.
   */
  PARAVIEW_DEPRECATED_IN_5_10_0("Replaced by `vtkCLIOptions` APIs")
  // b pqApplicationCore(int& argc, char** argv, pqOptions* options, QObject* parent = nullptr);
  PARAVIEW_DEPRECATED_IN_5_10_0("Replaced by `vtkCLIOptions` APIs")
  // b pqOptions* getOptions() const;
  ///@}

  /**
   * Get the Object Builder. Object Buider must be used
   * to create complex objects such as sources, filters,
   * readers, views, displays etc.
   */
  // b pqObjectBuilder* getObjectBuilder() const { return this->ObjectBuilder; }

  /**
   * Set/Get the application's central undo stack. By default no undo stack is
   * provided. Applications must set on up as required.
   */
  // b void setUndoStack(pqUndoStack* stack);
  // b pqUndoStack* getUndoStack() const { return this->UndoStack; }

  /**
   * Custom Applications may need use various "managers"
   * All such manager can be registered with the pqApplicationCore
   * so that that can be used by other components of the
   * application. Registering with pqApplicationCore gives easy
   * access to these managers from the application code. Note
   * that custom applications are not required to register managers.
   * However certain optional components of the pqCore may
   * expect some managers.
   * Only one manager can be registered for a \c function.
   */
  void registerManager(const QString& function, QObject* manager);

  /**
   * Returns a manager for a particular function, if any.
   */
  //. \sa registerManager
  QObject* manager(const QString& function);

  /**
   * Unregisters a manager for a particular function, if any.
   */
  void unRegisterManager(const QString& function);

  /**
   * provides access to the help engine. The engine is created the first time
   * this method is called.
   */
  // b QHelpEngine* helpEngine();

  /**
   * QHelpEngine doesn't like filenames in resource space. This method creates
   * a temporary file for the resource and registers that with the QHelpEngine.
   */
  void registerDocumentation(const QString& filename);

  /**
   * ServerManagerObserver observer the vtkSMProxyManager
   * for changes to the server manager and fires signals on
   * certain actions such as registeration/unregistration of proxies
   * etc. Returns the ServerManagerObserver used by the application.
   */
  // b pqServerManagerObserver* getServerManagerObserver() { return this->ServerManagerObserver; }

  /**
   * ServerManagerModel is the representation of the ServerManager
   * using pqServerManagerModelItem subclasses. It makes it possible to
   * explore the ServerManager with ease by separating proxies based
   * on their functionality/type.
   */
   // b pqServerManagerModel* getServerManagerModel() const { return this->ServerManagerModel; }

  /**
   * Locates the interface tracker for the application. pqInterfaceTracker is
   * used to locate all interface implementations typically loaded from
   * plugins.
   */
   // b pqInterfaceTracker* interfaceTracker() const { return this->InterfaceTracker; }

  /**
   * pqLinksModel is the model used to keep track of proxy/property links
   * maintained by vtkSMProxyManager.
   * TODO: It may be worthwhile to investigate if we even need a global
   * pqLinksModel. All the information is already available in
   * vtkSMProxyManager.
   */
  // b pqLinksModel* getLinksModel() const { return this->LinksModel; }

  /**
   * pqMainWindowManager manages signals called for main window events.
   */
  pqMainWindowEventManager* getMainWindowEventManager() const
  {
    return this->MainWindowEventManager;
  }

  /**
   * pqPluginManager manages all functionality associated with loading plugins.
   */
  // b pqPluginManager* getPluginManager() const { return this->PluginManager; }

  /**
   * ProgressManager is the manager that streamlines progress.
   */
  // b pqProgressManager* getProgressManager() const { return this->ProgressManager; }

  /**
   * Provides access to the test utility.
   */
  // b virtual pqTestUtility* testUtility();

  /**
   * Returns the set of recently-used resources i.e. data files and state
   * files.
   */
  // b pqRecentlyUsedResourcesList& recentlyUsedResources();

  /**
   * Returns the collection of server configurations known. Server
   * configurations have information about connecting to different servers.
   */
   // b pqServerConfigurationCollection& serverConfigurations();

  /**
   * Get the application settings.
   */
  pqSettings* settings();

  /**
   * Clears the settings. Since various UI components that only
   * read settings at creation time may get out of sync, it's best
   * to warn the user to restart the application.
   *
   * Any changes made to pqSettings after calling this method will be lost and
   * will not get restored. If that's not desired, see `QSettings::clear`.
   */
  void clearSettings();

  /**
   * Save the ServerManager state to a XML element.
   */
  // b vtkPVXMLElement* saveState();

  /**
   * Save the ServerManager state to a file.
   * Return true if the operation succeeded otherwise return false.
   */
  bool saveState(const QString& filename);

  /**
   * Loads the ServerManager state. Emits the signal
   * stateLoaded() on loading state successfully.
   */
  // b void loadState(vtkPVXMLElement* root, pqServer* server, vtkSMStateLoader* loader = nullptr);

  /**
   * Load state xml from a file. The filename can be a Qt resource file,
   * besides regular filesystem files (refer to QFile documentation for more
   * information on Qt resource system).
   */
  // b void loadState(const char* filename, pqServer* server, vtkSMStateLoader* loader = nullptr);

  /**
   * Loads state from an in-memory buffer.
   */
  // b void loadStateFromString(
    // b const char* xmlcontents, pqServer* server, vtkSMStateLoader* loader = nullptr);

  // b void clearViewsForLoadingState(pqServer* server);

  /**
   * Same as loadState() except that it doesn't clear the current visualization
   * state.
   */
  //b void loadStateIncremental(
    // b vtkPVXMLElement* root, pqServer* server, vtkSMStateLoader* loader = nullptr);
  // b void loadStateIncremental(
    // b const QString& filename, pqServer* server, vtkSMStateLoader* loader = nullptr);

  /**
   * Set the loading state flag
   */
  void setLoadingState(bool value) { this->LoadingState = value; };

  /**
   * Check to see if its in the process of loading a state
   * Reliance on this flag is chimerical since we cannot set this ivar when
   * state file is being loaded from python shell.
   */
  bool isLoadingState() { return this->LoadingState; };

  /**
   * returns the active server is any.
   */
   pqServer* getActiveServer() const;

  /**
   * Destructor.
   */
  ~pqApplicationCore() override;

  /**
   * INTERNAL. Do not use.
   */
  void _paraview_client_environment_complete();

public Q_SLOTS: // NOLINT(readability-redundant-access-specifiers)

  /**
   * Applications calls this to ensure that any cleanup is performed correctly.
   */
  // b void prepareForQuit();

  /**
   * Calls QCoreApplication::quit().
   */
  // b void quit();

  ///@{
  /**
   * Load configuration xml. This results in firing of the loadXML() signal
   * which different components that support configuration catch and process to
   * update their behavior.
   * This also update available readers and writers.
   */
  // b void loadConfiguration(const QString& filename);
  // b void loadConfigurationXML(const char* xmldata);
  ///@}

  /**
   * Update the available readers and writers using the factories
   */
  // b void updateAvailableReadersAndWriters();

  /**
   * Renders all windows
   */
  // b void render();

Q_SIGNALS:
  /**
   * Fired before a state xml is being loaded. One can add slots for this signal
   * and modify the fired xml-element as part of pre-processing before
   * attempting to load the state xml. Note that never attempt to connect to
   * signal in a delayed fashion i.e using Qt::QueuedConnection etc. since the
   * \c root will be destroyed.
   */
  // b void aboutToLoadState(vtkPVXMLElement* root);

  /**
   * Fired when a state file is loaded successfully.
   * GUI components that may have state saved in the XML state file must listen
   * to this signal and handle process the XML to update their state.
   */
  // b void stateLoaded(vtkPVXMLElement* root, vtkSMProxyLocator* locator);

  /**
   * Fired to save state xml. Components that need to save XML state should
   * listen to this signal and add their XML elements to the root. DO NOT MODIFY
   * THE ROOT besides adding new children.
   */
  // b void stateSaved(vtkPVXMLElement* root);

  /**
   * Fired when the undo stack is set.
   */
  // b void undoStackChanged(pqUndoStack*);

  /**
   * Fired on loadConfiguration().
   */
  // b void loadXML(vtkPVXMLElement*);

  /**
   * Fired when the filter menu state needs to be manually updated
   */
  void forceFilterMenuRefresh();

  /**
   * Fired when master changed. true if current user is master, false otherwise.
   */
  void updateMasterEnableState(bool);

  /**
   * Fired when the ParaView Client infrastructure has completed setting up the
   * environment.
   */
  void clientEnvironmentDone();

protected Q_SLOTS:
  // b void onStateLoaded(vtkPVXMLElement* root, vtkSMProxyLocator* locator);
  // b void onStateSaved(vtkPVXMLElement* root);
  // b void onHelpEngineWarning(const QString&);

private Q_SLOTS:
  /**
   * called when vtkPVGeneralSettings::GetInstance() fired
   * `vtkCommand::ModifiedEvent`. We update pqDoubleLineEdit's global precision
   * settings.
   */
  // b void generalSettingsChanged();

protected:
  bool LoadingState;
  
  pqMainWindowEventManager* MainWindowEventManager; 
  pqSettings* Settings;
  /* b
  pqServerManagerModel* ServerManagerModel;
  pqServerManagerObserver* ServerManagerObserver;
  pqServerConfigurationCollection* ServerConfigurations;
  pqInterfaceTracker* InterfaceTracker;
  pqObjectBuilder* ObjectBuilder;
  PARAVIEW_DEPRECATED_IN_5_10_0("Replaced by `vtkCLIOptions` APIs")
  vtkSmartPointer<pqOptions> Options;
  PARAVIEW_DEPRECATED_IN_5_10_0("Replaced by `vtkCLIOptions` APIs")
  void setOptions(pqOptions* options);
  pqLinksModel* LinksModel;
  pqPluginManager* PluginManager;
  pqProgressManager* ProgressManager;
  pqUndoStack* UndoStack;
  pqRecentlyUsedResourcesList* RecentlyUsedResourcesList;
  QHelpEngine* HelpEngine;
  QPointer<pqTestUtility> TestUtility;
  */
private:
  Q_DISABLE_COPY(pqApplicationCore)

  class pqInternals;
  pqInternals* Internal;
  static pqApplicationCore* Instance;
  void constructor();
};

#endif
