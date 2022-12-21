#include "pqComponentsInit2.h"
#include "pqCoreInit2.h"
#include "pqWidgetsInit2.h"
#include <QObject> // for Q_INIT_RESOURCE

void pqComponentsInit()
{
  // init dependents
  pqCoreInit();
  pqWidgetsInit();

  // init resources
  Q_INIT_RESOURCE(pqComponents);
}
