/// \file pqServerManagerModelItem.cxx
/// \date 4/14/2006

#include "pqServerManagerModelItem2.h"

// ParaView includes.
#include "vtkEventQtSlotConnect2.h"

// Qt includes.

//-----------------------------------------------------------------------------
pqServerManagerModelItem::pqServerManagerModelItem(QObject* _parent /*=nullptr*/)
  : QObject(_parent)
{
  this->Connector = nullptr;
}

//-----------------------------------------------------------------------------
pqServerManagerModelItem::~pqServerManagerModelItem()
{
  if (this->Connector)
  {
    this->Connector->Delete();
    this->Connector = nullptr;
  }
}

//-----------------------------------------------------------------------------
vtkEventQtSlotConnect* pqServerManagerModelItem::getConnector()
{
  if (!this->Connector)
  {
    this->Connector = vtkEventQtSlotConnect::New();
  }

  return this->Connector;
}
