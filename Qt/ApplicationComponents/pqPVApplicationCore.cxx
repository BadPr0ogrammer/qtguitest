/*=========================================================================

   Program: ParaView
   Module:    pqPVApplicationCore.cxx

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/

// Hide PARAVIEW_DEPRECATED_IN_5_10_0() warnings for this class.
#define PARAVIEW_DEPRECATION_LEVEL 0

#include "pqPVApplicationCore.h"

// b #include "pqActiveObjects.h"
// b #include "pqAnimationManager.h"
#include "pqApplicationComponentsInit.h"
#include "pqApplicationCore.h"
// b #include "pqComponentsTestUtility.h"
// b #include "pqCoreConfiguration.h"
#include "pqCoreUtilities.h"
// b #include "pqItemViewSearchWidget.h"
// b #include "pqLoadDataReaction.h"
// b #include "pqPresetGroupsManager.h"
// b #include "pqPropertiesPanel.h"
// b #include "pqQuickLaunchDialog.h"
// b #include "pqSelectionManager.h"
#include "pqSetName.h"
// b #include "pqSpreadSheetViewModel.h"
#include "vtkPVLogger.h"
// b #include "vtkProcessModule.h"

#if VTK_MODULE_ENABLE_ParaView_pqPython
#include "pqPythonManager.h"
#endif

#include <QAbstractItemView>
#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QFileOpenEvent>
#include <QList>

//-----------------------------------------------------------------------------
pqPVApplicationCore::pqPVApplicationCore(int& argc, char** argv
    // b , pqOptions* options)
    )
  : pqPVApplicationCore(argc, argv, 
      // b static_cast<vtkCLIOptions*>(nullptr), 
      true, nullptr)
{
  // b this->setOptions(options);
}

//-----------------------------------------------------------------------------
pqPVApplicationCore::pqPVApplicationCore(int& argc, char** argv, // b vtkCLIOptions* options,
  bool addStandardArgs /*=true*/, QObject* parentObject /*=nullptr*/)
  : Superclass(argc, argv, // b options, 
      addStandardArgs, parentObject)
{
  // Initialize pqComponents resources, only for static builds.
#if !BUILD_SHARED_LIBS
  pqApplicationComponentsInit();
#endif
  // b this->AnimationManager = new pqAnimationManager(this);
  // b this->SelectionManager = new pqSelectionManager(this);

  // b pqApplicationCore::instance()->registerManager("SELECTION_MANAGER", this->SelectionManager);

  // b pqPresetGroupsManager* presetGroupManager = new pqPresetGroupsManager(this);
  // b bool loadedFromSettings = presetGroupManager->loadGroupsFromSettings();
  // If the groups could not be loaded from the settings, use the default groups
  /* b
  if (!loadedFromSettings)
  {
    QString groupString;
    QFile groupsFile(":pqWidgets/pqPresetGroups.json");

    if (!groupsFile.open(QIODevice::ReadOnly))
    {
      qWarning() << "Could not load preset group list.";
    }
    else
    {
      groupString = groupsFile.readAll();
    }
    groupsFile.close();

    presetGroupManager->loadGroups(groupString);
  }
  pqApplicationCore::instance()->registerManager("PRESET_GROUP_MANAGER", presetGroupManager);
  */
  this->PythonManager = nullptr;
#if VTK_MODULE_ENABLE_ParaView_pqPython
  this->PythonManager = new pqPythonManager(this);

// Ensure that whenever Python is initialized, we tell paraview.servermanager
// that is being done from the GUI.
#endif

  // b QObject::connect(&pqActiveObjects::instance(), SIGNAL(serverChanged(pqServer*)), this->AnimationManager, SLOT(onActiveServerChanged(pqServer*)));
}

//-----------------------------------------------------------------------------
pqPVApplicationCore::~pqPVApplicationCore()
{
  // b delete this->AnimationManager;
  // b delete this->SelectionManager;
#if VTK_MODULE_ENABLE_ParaView_pqPython
  delete this->PythonManager;
#endif
}

//-----------------------------------------------------------------------------
void pqPVApplicationCore::registerForQuicklaunch(QWidget* menu)
{
  if (menu)
  {
    this->QuickLaunchMenus.push_back(menu);
  }
}

//-----------------------------------------------------------------------------
void pqPVApplicationCore::quickLaunch()
{
  Q_EMIT this->aboutToShowQuickLaunch();
  if (!this->QuickLaunchMenus.empty())
  {
    
    /* b pqQuickLaunchDialog dialog(pqCoreUtilities::mainWidget());

    Q_FOREACH (QWidget* menu, this->QuickLaunchMenus)
    {
      if (menu)
      {
        // don't use QMenu::actions() since that includes only the top-level
        // actions.
        // --> BUT pqProxyGroupMenuManager in order to handle multi-server
        //         setting properly add actions into an internal widget so
        //         actions() should be used instead of findChildren()
        if (menu->findChildren<QAction*>().empty())
        {
          dialog.addActions(menu->actions());
        }
        else
        {
          dialog.addActions(menu->findChildren<QAction*>());
        }
      }
    }
    dialog.exec();
    if (dialog.quickApply())
    {
      this->applyPipeline();
    }
    */
  }
}

//-----------------------------------------------------------------------------
void pqPVApplicationCore::applyPipeline()
{
  Q_EMIT this->triggerApply();
}

//-----------------------------------------------------------------------------
void pqPVApplicationCore::startSearch()
{
  if (!QApplication::focusWidget())
  {
    return;
  }
  QAbstractItemView* focusItemView = qobject_cast<QAbstractItemView*>(QApplication::focusWidget());
  if (!focusItemView)
  {
    return;
  }
  // currently we don't support search on pqSpreadSheetViewModel
  /* b 
  if (qobject_cast<pqSpreadSheetViewModel*>(focusItemView->model()))
  {
    return;
  }

  pqItemViewSearchWidget* searchDialog = new pqItemViewSearchWidget(focusItemView);
  searchDialog->setAttribute(Qt::WA_DeleteOnClose, true);
  searchDialog->showSearchWidget();
  */
}
/* b
//-----------------------------------------------------------------------------
pqSelectionManager* pqPVApplicationCore::selectionManager() const
{
  return this->SelectionManager;
}

//-----------------------------------------------------------------------------
pqAnimationManager* pqPVApplicationCore::animationManager() const
{
  return this->AnimationManager;
}
*/
//-----------------------------------------------------------------------------
pqPythonManager* pqPVApplicationCore::pythonManager() const
{
#if VTK_MODULE_ENABLE_ParaView_pqPython
  return this->PythonManager;
#else
  return 0;
#endif
}

//-----------------------------------------------------------------------------
/* b
pqTestUtility* pqPVApplicationCore::testUtility()
{
  if (!this->TestUtility)
  {
    this->TestUtility = new pqComponentsTestUtility(this);
  }
  return this->TestUtility;
}
*/
//-----------------------------------------------------------------------------
bool pqPVApplicationCore::eventFilter(QObject* obj, QEvent* event_)
{
  if (event_->type() == QEvent::FileOpen)
  {
    QFileOpenEvent* fileEvent = static_cast<QFileOpenEvent*>(event_);
    if (!fileEvent->file().isEmpty())
    {
      QList<QString> files;
      files.append(fileEvent->file());
      /* b
      // If the application is already started just load the data
      if (vtkProcessModule::GetProcessModule()->GetSession())
      {
        // b pqLoadDataReaction::loadData(files);
      }
      else
      {
        // If the application has not yet started, treat it as a --data argument
        // to be processed after the application starts.
        pqCoreConfiguration::instance()->addDataFile(files[0].toUtf8().data());
      }
      */
    }
    return false;
  }
  else
  {
    // standard event processing
    return QObject::eventFilter(obj, event_);
  }
}

//-----------------------------------------------------------------------------
void pqPVApplicationCore::loadStateFromPythonFile(const QString& filename, pqServer* server)
{
#if VTK_MODULE_ENABLE_ParaView_pqPython
  pqPythonManager* pythonMgr = this->pythonManager();
  this->clearViewsForLoadingState(server);
  // comment in pqApplicationCore says this->LoadingState is unreliable, but it is still
  // necessary to avoid warning messages
  this->LoadingState = true;
  pythonMgr->executeScriptAndRender(filename);
  this->LoadingState = false;
#else
  // Avoid unused parameter warnings
  (void)filename;
  (void)server;
  qCritical() << "Cannot load a python state file since ParaView was not built with Python.";
#endif
}
