#include "pqTimeKeeper2.h"

#include "vtkCommand.h"
#include "vtkNew.h"

#include "vtkEventQtSlotConnect.h"
#include "vtkSMProperty2.h"
// b #include "vtkSMPropertyHelper2.h"
#include "vtkSMProxy2.h"
// b #include "vtkSMTimeKeeperProxy2.h"

#include <QList>
#include <QtDebug>

#include <vector>
//-----------------------------------------------------------------------------
class pqTimeKeeper::pqInternals
{
public:
  vtkNew<vtkEventQtSlotConnect> VTKConnect;
};

//-----------------------------------------------------------------------------
pqTimeKeeper::pqTimeKeeper(const QString& group, const QString& name, vtkSMProxy* timekeeper,
  // b pqServer* server, 
  QObject* _parent /*=0*/)
  : pqProxy(group, name, timekeeper, 
  // b server, 
  _parent)
{
  this->Internals = new pqInternals();
  /* b
  this->Internals->VTKConnect->Connect(
    timekeeper->GetProperty("Time"), vtkCommand::ModifiedEvent, this, SIGNAL(timeChanged()));
  this->Internals->VTKConnect->Connect(timekeeper->GetProperty("TimestepValues"),
    vtkCommand::ModifiedEvent, this, SIGNAL(timeStepsChanged()));
  this->Internals->VTKConnect->Connect(timekeeper->GetProperty("TimestepValues"),
    vtkCommand::ModifiedEvent, this, SIGNAL(timeRangeChanged()));
  this->Internals->VTKConnect->Connect(timekeeper->GetProperty("TimeRange"),
    vtkCommand::ModifiedEvent, this, SIGNAL(timeRangeChanged()));
    */
}

//-----------------------------------------------------------------------------
pqTimeKeeper::~pqTimeKeeper()
{
  delete this->Internals;
}

//-----------------------------------------------------------------------------
QList<double> pqTimeKeeper::getTimeSteps() const
{
  /*
  vtkSMPropertyHelper helper(this->getProxy(), "TimestepValues");
  QList<double> list;
  for (unsigned int cc = 0; cc < helper.GetNumberOfElements(); cc++)
  {
    list.push_back(helper.GetAsDouble(cc));
  }
  return list;*/
    return QList<double>();
}

//-----------------------------------------------------------------------------
int pqTimeKeeper::getNumberOfTimeStepValues() const
{
  //return vtkSMPropertyHelper(this->getProxy(), "TimestepValues").GetNumberOfElements();
    return 0;
}

//-----------------------------------------------------------------------------
double pqTimeKeeper::getTimeStepValue(int index) const
{
  if (index < this->getNumberOfTimeStepValues())
  {
    // b return vtkSMPropertyHelper(this->getProxy(), "TimestepValues").GetAsDouble(index);
  }

  return 0.0;
}

//-----------------------------------------------------------------------------
int pqTimeKeeper::getTimeStepValueIndex(double time) const
{
  // b return vtkSMTimeKeeperProxy::GetLowerBoundTimeStepIndex(this->getProxy(), time);
    return  0;
}

//-----------------------------------------------------------------------------
QPair<double, double> pqTimeKeeper::getTimeRange() const
{
  // b vtkSMPropertyHelper helper(this->getProxy(), "TimeRange");
  // b return QPair<double, double>(helper.GetAsDouble(0), helper.GetAsDouble(1));
  return QPair<double, double>(0,0);
}

//-----------------------------------------------------------------------------
double pqTimeKeeper::getTime() const
{
  // b return vtkSMPropertyHelper(this->getProxy(), "Time").GetAsDouble(0);
  return 0;
}

//-----------------------------------------------------------------------------
void pqTimeKeeper::setTime(double time)
{
  // b vtkSMPropertyHelper(this->getProxy(), "Time").Set(time);
  // b this->getProxy()->UpdateVTKObjects();
}
