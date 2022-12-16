#ifndef pqAlwaysConnectedBehavior_h
#define pqAlwaysConnectedBehavior_h

#include <QObject>

#include "pqApplicationComponentsModule2.h"
#include "pqTimer2.h"

/**
 * @ingroup Behaviors
 * pqAlwaysConnectedBehavior ensures that the client always remains connected
 * to a server.
 */
class PQAPPLICATIONCOMPONENTS_EXPORT pqAlwaysConnectedBehavior : public QObject
{
  Q_OBJECT
  typedef QObject Superclass;

public:
  pqAlwaysConnectedBehavior(QObject* parent = nullptr);
  ~pqAlwaysConnectedBehavior() override;

  /**
   * Get/Set the default server resource to connect to.
   */
  // b void setDefaultServer(const pqServerResource& resource) { this->DefaultServer = resource; }
  // b const pqServerResource& defaultServer() const { return this->DefaultServer; }

protected Q_SLOTS:
  void serverCheck();

protected: // NOLINT(readability-redundant-access-specifiers)
  // b pqServerResource DefaultServer;
  pqTimer Timer;

private:
  Q_DISABLE_COPY(pqAlwaysConnectedBehavior)
};

#endif
