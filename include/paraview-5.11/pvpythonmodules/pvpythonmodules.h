#ifndef pvpythonmodules_h
#define pvpythonmodules_h
#include "vtkpythonmodules.h"
#if PY_VERSION_HEX < 0x03000000
#define PY_APPEND_INIT(module) PyImport_AppendInittab("." #module, init ## module)
#define PY_IMPORT(module) init ## module();
#else
#define PY_APPEND_INIT(module) PyImport_AppendInittab("." #module, PyInit_ ## module)
#define PY_IMPORT(module) { \
    PyObject* var_ ## module = PyInit_ ## module(); \
    PyDict_SetItemString(PyImport_GetModuleDict(), "." #module,var_ ## module); \
    Py_DECREF(var_ ## module); }
#endif

#define PY_APPEND_INIT_OR_IMPORT(module, do_import) \
  if (do_import) { PY_IMPORT(module); } else { PY_APPEND_INIT(module); }

static void pvpythonmodules_load() {
  vtkpythonmodules_load();
}
#undef PY_APPEND_INIT
#undef PY_IMPORT
#undef PY_APPEND_INIT_OR_IMPORT
#endif
