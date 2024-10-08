#ifndef pqPVApplicationCore_h
#define pqPVApplicationCore_h

#include "pqApplicationCore2.h"

#include "pqApplicationComponentsModule.h" // for exports

#include "vtkParaViewDeprecation2.h"        // for PARAVIEW_DEPRECATED_IN_5_10_0
#include <QList>
#include <QPointer>

/* b 
class pqAnimationManager;
class pqSelectionManager;
class pqTestUtility;
*/
class pqPythonManager;
class QMenu;
class QWidget;

/**
 * pqPVApplicationCore is the application code used by ParaView-based
 * applications that use more of ParaView's functionality than that provided by
 * pqApplicationCore such as the the selection manager, animation  manager etc.
 */
class PQAPPLICATIONCOMPONENTS_EXPORT pqPVApplicationCore : public pqApplicationCore
{
  Q_OBJECT
  typedef pqApplicationCore Superclass;

public:
  pqPVApplicationCore(int& argc, char** argv, // b vtkCLIOptions* options = nullptr,
    bool addStandardArgs = true, QObject* parent = nullptr);
  ~pqPVApplicationCore() override;

  /**
   * @deprecated in ParaView 5.10.
   */
  PARAVIEW_DEPRECATED_IN_5_10_0("Use the `vtkCLIOptions` overload")
  pqPVApplicationCore(int& argc, char** argv 
      // b , pqOptions* options
      );

  /**
   * Returns the pqPVApplicationCore instance. If no pqPVApplicationCore has been
   * created then return nullptr.
   */
  static pqPVApplicationCore* instance()
  {
    return qobject_cast<pqPVApplicationCore*>(Superclass::instance());
  }

  /**
   * Provides access to the selection manager. Selection manager provides
   * access to the ParaView wide data selection mechanism. This must not be
   * confused with the active-object selection.
   */
  // b pqSelectionManager* selectionManager() const;

  /**
   * Provides access to the animation manager. Animation manager helps with the
   */
  // animation subsystem -- saving movies, creating scenes etc.
  // b pqAnimationManager* animationManager() const;

  /**
   * Provides access to the test utility.
   */
  // b pqTestUtility* testUtility() override;

  /**
   * Provides access to the python manager. This is non-nullptr only when paraview
   * is compiled with python support i.e. PARAVIEW_USE_PYTHON is ON.
   */
  pqPythonManager* pythonManager() const;

  /**
   * ParaView provides a mechanism to trigger menu actions using a quick-launch
   * dialog. Applications can register menus action from which should be
   * launch-able from the quick-launch dialog. Typical candidates are the
   * sources menu, filters menu etc.
   */
  virtual void registerForQuicklaunch(QWidget*);

  // b void loadStateFromPythonFile(const QString& filename, pqServer* server);

public Q_SLOTS: // NOLINT(readability-redundant-access-specifiers)
  /**
   * A useful slot to trigger an apply on the pipeline.
   * This is just emitting a signal usually caught by a pqApplyBehavior.
   */
  void applyPipeline();

  /**
   * Pops-up the quick launch dialog.
   */
  void quickLaunch();

  /**
   * Pops-up the search dialog if the focused widget is
   * QAsbstractItemView type.
   */
  void startSearch();

Q_SIGNALS:
  /**
   * Emitted whenever the quickLaunch dialog is about to show.  This can be used
   * to update the menu items (QActions) that will be shown in the quick-launch
   * dialog.
   */
  void aboutToShowQuickLaunch();

  void triggerApply();

protected:
  /**
   * Override event filter in order to catch file association mechanism
   */
  bool eventFilter(QObject* obj, QEvent* event) override;

  /* b 
  QPointer<pqSelectionManager> SelectionManager;
  QPointer<pqAnimationManager> AnimationManager;
  */
  pqPythonManager* PythonManager;
  QList<QPointer<QWidget>> QuickLaunchMenus;

private:
  Q_DISABLE_COPY(pqPVApplicationCore)
};

#endif
