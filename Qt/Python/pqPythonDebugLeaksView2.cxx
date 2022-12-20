// Include vtkPython.h first to avoid python??_d.lib not found linking error on
// Windows debug builds.
#include "vtkPython.h"

#include "pqPythonDebugLeaksView2.h"
#include "pqPythonShell.h"
// b #include "vtkPythonUtil.h"
#include "vtkQtDebugLeaksModel2.h"
#include "vtkSmartPyObject2.h"

//-----------------------------------------------------------------------------
namespace
{

PyObject* consoleContext(pqPythonShell* shell)
{
  return shell ? static_cast<PyObject*>(shell->consoleLocals()) : nullptr;
}
};

//-----------------------------------------------------------------------------
pqPythonDebugLeaksView::pqPythonDebugLeaksView(QWidget* p)
  : vtkQtDebugLeaksView(p)
{
}

//-----------------------------------------------------------------------------
pqPythonDebugLeaksView::~pqPythonDebugLeaksView() = default;

//-----------------------------------------------------------------------------
void pqPythonDebugLeaksView::setShell(pqPythonShell* shell)
{
  this->Shell = shell;
}

//-----------------------------------------------------------------------------
pqPythonShell* pqPythonDebugLeaksView::shell() const
{
  return this->Shell;
}

//-----------------------------------------------------------------------------
void pqPythonDebugLeaksView::onObjectDoubleClicked(vtkObjectBase* object)
{
  this->addObjectToPython(object);
}

//-----------------------------------------------------------------------------
void pqPythonDebugLeaksView::onClassNameDoubleClicked(const QString& className)
{
  this->addObjectsToPython(this->model()->getObjects(className));
}

//-----------------------------------------------------------------------------
void pqPythonDebugLeaksView::addObjectToPython(vtkObjectBase* object)
{
  if (auto context = consoleContext(this->shell()))
  {
    // b vtkSmartPyObject pyObj(vtkPythonUtil::GetObjectFromPointer(object));
    // b PyDict_SetItemString(context, "obj", pyObj);
  }
}

//-----------------------------------------------------------------------------
void pqPythonDebugLeaksView::addObjectsToPython(const QList<vtkObjectBase*>& objects)
{
  if (auto context = consoleContext(this->shell()))
  {
    vtkSmartPyObject pyListObj(PyList_New(objects.size()));
    for (int i = 0; i < objects.size(); ++i)
    {
      // b PyObject* pyObj = vtkPythonUtil::GetObjectFromPointer(objects[i]);
      // b PyList_SET_ITEM(pyListObj.GetPointer(), i, pyObj);
    }
    PyDict_SetItemString(context, "objs", pyListObj);
  }
}
