#include "pqCoreInit2.h"
#include <QObject>
#include <QtPlugin>

void pqCoreInit()
{
  #if !BUILD_SHARED_LIBS
  // b Q_INIT_RESOURCE(pqCore);
  // b Q_INIT_RESOURCE(QtWidgets);
  #endif
}
