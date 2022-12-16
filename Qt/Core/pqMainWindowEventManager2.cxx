#include "pqMainWindowEventManager2.h"

#include <QCloseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QShowEvent>

//-----------------------------------------------------------------------------
pqMainWindowEventManager::pqMainWindowEventManager(QObject* parentObject)
  : Superclass(parentObject)
{
}

//-----------------------------------------------------------------------------
pqMainWindowEventManager::~pqMainWindowEventManager() = default;

//-----------------------------------------------------------------------------
void pqMainWindowEventManager::closeEvent(QCloseEvent* event)
{
  Q_EMIT this->close(event);
}

//-----------------------------------------------------------------------------
void pqMainWindowEventManager::showEvent(QShowEvent* event)
{
  Q_EMIT this->show(event);
}

//-----------------------------------------------------------------------------
void pqMainWindowEventManager::dragEnterEvent(QDragEnterEvent* event)
{
  Q_EMIT this->dragEnter(event);
}

//-----------------------------------------------------------------------------
void pqMainWindowEventManager::dropEvent(QDropEvent* event)
{
  Q_EMIT this->drop(event);
}
