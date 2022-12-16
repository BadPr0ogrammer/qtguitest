#ifndef pqComponentsInit_h
#define pqComponentsInit_h

#include "pqComponentsModule2.h"

/**
 * pqComponentsInit() is for initializing QT resources. When pqComponents is built
 * as a static library, linkers may drop out entire object
 * files such as files generated by rcc. Client apps can call to use Qt
 * resources outside PV.
 */

PQCOMPONENTS_EXPORT void pqComponentsInit();

#endif
