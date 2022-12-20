#include "pqPropertyWidgetDecorator2.h"

#include "pqApplicationCore2.h"
#include "pqPropertyWidget2.h"
#include "pqPropertyWidgetDecorator2.h"
#include "vtkPVLogger2.h"
#include "vtkPVXMLElement2.h"
/* b
#include "pqInterfaceTracker2.h"
#include "pqPropertyWidgetInterface2.h"
*/
#include <cassert>
#include <QDebug>

//-----------------------------------------------------------------------------
pqPropertyWidgetDecorator::pqPropertyWidgetDecorator(
  vtkPVXMLElement* xmlConfig, pqPropertyWidget* parentObject)
  : Superclass(parentObject)
  , XML(xmlConfig)
{
  assert(parentObject);
  parentObject->addDecorator(this);
}

//-----------------------------------------------------------------------------
pqPropertyWidgetDecorator::~pqPropertyWidgetDecorator()
{
  if (auto* pwdg = this->parentWidget())
  {
    pwdg->removeDecorator(this);
  }
}

//-----------------------------------------------------------------------------
pqPropertyWidgetDecorator* pqPropertyWidgetDecorator::create(
  vtkPVXMLElement* xmlconfig, pqPropertyWidget* prnt)
{
  if (xmlconfig == nullptr || strcmp(xmlconfig->GetName(), "PropertyWidgetDecorator") != 0 ||
    xmlconfig->GetAttribute("type") == nullptr)
  {
    qWarning("Invalid xml config specified. Cannot create a decorator.");
    return nullptr;
  }

  /* b auto tracker = pqApplicationCore::instance()->interfaceTracker();
  auto interfaces = tracker->interfaces<pqPropertyWidgetInterface*>();

  const QString type = xmlconfig->GetAttribute("type");
  for (auto* anInterface : interfaces)
  {
    if (pqPropertyWidgetDecorator* decorator =
          anInterface->createWidgetDecorator(type, xmlconfig, prnt))
    {
      vtkVLogF(PARAVIEW_LOG_APPLICATION_VERBOSITY(), "created decorator `%s`",
        decorator->metaObject()->className());
      return decorator;
    }
  }
  qWarning() << "Cannot create decorator of type " << type;
  */
  return nullptr;
}

//-----------------------------------------------------------------------------
vtkPVXMLElement* pqPropertyWidgetDecorator::xml() const
{
  return this->XML.GetPointer();
}

//-----------------------------------------------------------------------------
pqPropertyWidget* pqPropertyWidgetDecorator::parentWidget() const
{
  return qobject_cast<pqPropertyWidget*>(this->parent());
}
