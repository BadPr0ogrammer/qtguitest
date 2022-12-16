#include "pqApplicationComponentsInit2.h"

#include "pqComponentsInit2.h"
#include <QObject> // for Q_INIT_RESOURCE
#include <QtPlugin>

void pqApplicationComponentsInit()
{
  // init dependents
  pqComponentsInit();

  // init resources
  // b Q_INIT_RESOURCE(pqApplicationComponents);
}
