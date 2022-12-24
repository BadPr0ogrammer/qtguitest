#include "pqCoreInit2.h"

#include <QObject>
#include <QtPlugin>

void pqCoreInit()
{
  #if !BUILD_SHARED_LIBS
  Q_INIT_RESOURCE(pqCore);
  Q_INIT_RESOURCE(QtWidgets);
  #endif
}
