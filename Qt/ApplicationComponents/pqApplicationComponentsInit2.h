#ifndef pqApplicationComponentsInit_h
#define pqApplicationComponentsInit_h

#include "pqApplicationComponentsModule.h"

/**
 * pqApplicationComponentsInit() is for initializing QT resources. When pqApplicationComponents
 * is built as a static library, linkers may drop out entire object
 * files such as files generated by rcc. Client apps can call to use Qt
 * resources outside PV.
 */

PQAPPLICATIONCOMPONENTS_EXPORT void pqApplicationComponentsInit();

#endif
