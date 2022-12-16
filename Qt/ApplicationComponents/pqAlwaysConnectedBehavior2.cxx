#include "pqAlwaysConnectedBehavior2.h"

// b #include "pqObjectBuilder.h"
#include "pqPVApplicationCore2.h"
// b #include "pqServer.h"
// b #include "pqServerManagerModel.h"
#include "vtkNetworkAccessManager2.h"

#include <cassert>

//-----------------------------------------------------------------------------
pqAlwaysConnectedBehavior::pqAlwaysConnectedBehavior(QObject* parentObject)
  : Superclass(parentObject)
  // b , DefaultServer("builtin:")
{
  auto core = pqPVApplicationCore::instance();
  assert(core != nullptr);

  // check for valid server when application becomes ready.
  this->connect(core, SIGNAL(clientEnvironmentDone()), SLOT(serverCheck()));

  // check for valid server after disconnect.
  // b pqServerManagerModel* smmodel = core->getServerManagerModel();
  this->Timer.setSingleShot(true);
  this->Timer.setInterval(0);
  this->connect(&this->Timer, SIGNAL(timeout()), SLOT(serverCheck()));
  // b this->Timer.connect(smmodel, SIGNAL(finishedRemovingServer()), SLOT(start()));

  this->serverCheck();
}

//-----------------------------------------------------------------------------
pqAlwaysConnectedBehavior::~pqAlwaysConnectedBehavior() = default;

//-----------------------------------------------------------------------------
void pqAlwaysConnectedBehavior::serverCheck()
{
  pqPVApplicationCore* core = pqPVApplicationCore::instance();
  /* b
  if (core->getServerManagerModel()->getNumberOfItems<pqServer*>() != 0)
  {
    return;
  }
  if (core->getObjectBuilder()->waitingForConnection())
  {
    // Try again later, we are waiting for server to connect.
    this->Timer.start();
    return;
  }

  core->getObjectBuilder()->createServer(this->DefaultServer);
  */
}
