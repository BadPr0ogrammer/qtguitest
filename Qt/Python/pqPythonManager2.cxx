// Include vtkPython.h first to avoid python??_d.lib not found linking error on
// Windows debug builds.
#include <vtkPython2.h>

#include "pqPythonManager2.h"

#include "pqApplicationCore2.h"
#include "pqCoreUtilities2.h"
// b #include "pqObjectBuilder2.h"
#include "pqPythonMacroSupervisor2.h"
#include "pqPythonScriptEditor2.h"
// b #include "pqServer.h"
// b #include "pqServerManagerModel.h"
#include "vtkCommand2.h"
#include "vtkNew2.h"
#include "vtkObjectFactory2.h"
#include "vtkOutputWindow2.h"
#include "vtkPythonInteractiveInterpreter2.h"
#include "vtkPythonInterpreter2.h"
#include "vtkSmartPointer2.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QLayout>
#include <QMainWindow>
#include <QSplitter>
#include <QStatusBar>
#include <QTextStream>
#include <sstream>

//-----------------------------------------------------------------------------
struct pqPythonManager::pqInternal
{
  QPointer<pqPythonMacroSupervisor> MacroSupervisor;
};

//-----------------------------------------------------------------------------
class pqPythonManagerOutputWindow : public vtkOutputWindow
{
  std::ostringstream TextStream;
  std::ostringstream ErrorStream;

public:
  static pqPythonManagerOutputWindow* New();
  vtkTypeMacro(pqPythonManagerOutputWindow, vtkOutputWindow);

  void DisplayText(const char* txt) override { this->TextStream << txt; }

  void DisplayErrorText(const char* txt) override { this->ErrorStream << txt; }

  std::string text() const { return this->TextStream.str(); }
  std::string errorText() const { return this->ErrorStream.str(); }

private:
  pqPythonManagerOutputWindow() = default;
  ~pqPythonManagerOutputWindow() override = default;

  pqPythonManagerOutputWindow(const pqPythonManagerOutputWindow&) = delete;
  void operator=(const pqPythonManagerOutputWindow&) = delete;
};
vtkStandardNewMacro(pqPythonManagerOutputWindow);

//-----------------------------------------------------------------------------
class pqPythonManagerRawInputHelper
{
public:
  void rawInput(vtkObject*, unsigned long, void* calldata)
  {
    std::string* strData = reinterpret_cast<std::string*>(calldata);
    bool ok;
    QString inputText = QInputDialog::getText(pqCoreUtilities::mainWidget(),
      QCoreApplication::translate("pqPythonManager", "Enter Input requested by Python"),
      QCoreApplication::translate("pqPythonManager", "Input: "), QLineEdit::Normal, QString(), &ok);
    if (ok)
    {
      *strData = inputText.toStdString();
    }
  }
};
//-----------------------------------------------------------------------------
pqPythonManager::pqPythonManager(QObject* _parent /*=null*/)
  : QObject(_parent)
{
  this->Internal = new pqInternal;
  pqApplicationCore* core = pqApplicationCore::instance();
  // b core->registerManager("PYTHON_MANAGER", this);

  // Create an instance of the macro supervisor
  this->Internal->MacroSupervisor = new pqPythonMacroSupervisor(this);
  this->connect(this->Internal->MacroSupervisor, SIGNAL(executeScriptRequested(const QString&)),
    SLOT(executeScriptAndRender(const QString&)));

  // Listen the signal when a macro wants to be edited
  QObject::connect(this->Internal->MacroSupervisor, SIGNAL(onEditMacro(const QString&)), this,
    SLOT(editMacro(const QString&)));
}

//-----------------------------------------------------------------------------
pqPythonManager::~pqPythonManager()
{
  // b pqApplicationCore::instance()->unRegisterManager("PYTHON_MANAGER");
  delete this->Internal;
}

//-----------------------------------------------------------------------------
bool pqPythonManager::initializeInterpreter()
{
  return vtkPythonInterpreter::Initialize();
}

//-----------------------------------------------------------------------------
bool pqPythonManager::interpreterIsInitialized()
{
  return vtkPythonInterpreter::IsInitialized();
}

//-----------------------------------------------------------------------------
void pqPythonManager::addWidgetForRunMacros(QWidget* widget)
{
  this->Internal->MacroSupervisor->addWidgetForRunMacros(widget);
}
//-----------------------------------------------------------------------------
void pqPythonManager::addWidgetForEditMacros(QWidget* widget)
{
  this->Internal->MacroSupervisor->addWidgetForEditMacros(widget);
}
//-----------------------------------------------------------------------------
void pqPythonManager::addWidgetForDeleteMacros(QWidget* widget)
{
  this->Internal->MacroSupervisor->addWidgetForDeleteMacros(widget);
}

//-----------------------------------------------------------------------------
void pqPythonManager::executeCode(
  const QByteArray& code, const QVector<QByteArray>& pre_push, const QVector<QByteArray>& post_push)
{
  pqPythonManagerRawInputHelper helper;

  // we capture messages from the script so that when the end up on the
  // terminal they are grouped as single message, otherwise they get split at
  // each "\n" since that how Python sends those messages over to us.
  vtkNew<pqPythonManagerOutputWindow> owindow;
  vtkSmartPointer<vtkOutputWindow> old = vtkOutputWindow::GetInstance();
  vtkOutputWindow::SetInstance(owindow);
  const bool prevCapture = vtkPythonInterpreter::GetCaptureStdin();
  vtkPythonInterpreter::SetCaptureStdin(true);

  vtkNew<vtkPythonInteractiveInterpreter> interp;
  interp->AddObserver(vtkCommand::UpdateEvent, &helper, &pqPythonManagerRawInputHelper::rawInput);
  for (const auto& instr : pre_push)
  {
    interp->Push(instr.data());
  }
  interp->RunStringWithConsoleLocals(code.data());
  for (const auto& instr : post_push)
  {
    interp->Push(instr.data());
  }
  vtkPythonInterpreter::SetCaptureStdin(prevCapture);
  vtkOutputWindow::SetInstance(old);
  interp->RemoveObservers(vtkCommand::UpdateEvent);

  auto txt = owindow->text();
  if (!txt.empty())
  {
    vtkOutputWindowDisplayText(txt.c_str());
  }

  auto errorText = owindow->errorText();
  if (!errorText.empty())
  {
    vtkOutputWindowDisplayErrorText(errorText.c_str());
  }
}

//-----------------------------------------------------------------------------
void pqPythonManager::executeScript(const QString& filename)
{
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly))
  {
    const QByteArray code = file.readAll();
    const QVector<QByteArray> pre_cmd = { "import sys",
      QString("__file__ = r'%1'").arg(filename).toUtf8() };
    const QVector<QByteArray> post_cmd = { "del __file__" };
    this->executeCode(code, pre_cmd, post_cmd);
  }
  else
  {
    qWarning() << "Error opening '" << filename << "'.";
  }
}

//-----------------------------------------------------------------------------
void pqPythonManager::executeScriptAndRender(const QString& filename)
{
  this->executeScript(filename);
  // b pqApplicationCore::instance()->render();
}

//----------------------------------------------------------------------------
void pqPythonManager::updateMacroList()
{
  this->Internal->MacroSupervisor->updateMacroList();
}

//----------------------------------------------------------------------------
void pqPythonManager::addMacro(const QString& fileName)
{
  QString userMacroDir = pqCoreUtilities::getParaViewUserDirectory() + "/Macros";
  QDir dir;
  dir.setPath(userMacroDir);
  // Copy macro file to user directory
  if (!dir.exists(userMacroDir) && !dir.mkpath(userMacroDir))
  {
    qWarning() << "Could not create user Macro directory:" << userMacroDir;
    return;
  }

  QString expectedFilePath = userMacroDir + "/" + QFileInfo(fileName).fileName();
  expectedFilePath = pqCoreUtilities::getNoneExistingFileName(expectedFilePath);

  QFile::copy(fileName, expectedFilePath);

  // Register the inner one
  this->Internal->MacroSupervisor->addMacro(expectedFilePath);
}
//----------------------------------------------------------------------------
void pqPythonManager::editMacro(const QString& fileName)
{
  pqPythonScriptEditor* pyEditor = pqPythonScriptEditor::getUniqueInstance();

  pyEditor->setPythonManager(this);
  pyEditor->show();
  pyEditor->raise();
  pyEditor->activateWindow();
  pyEditor->open(fileName);
}
