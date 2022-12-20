#include "pqPropertyWidget2.h"

#include "pqPropertiesPanel.h"
#include "pqPropertyWidgetDecorator2.h"
#include "pqTimer2.h"
#include "vtkPVXMLElement2.h"
#include "pqProxy2.h"
#include "vtkSMProperty2.h"
/* b
#include "pqUndoStack.h"
#include "pqView.h"
#include "vtkSMDocumentation.h"
#include "vtkSMDomain.h"
*/
//-----------------------------------------------------------------------------
pqPropertyWidget::pqPropertyWidget(vtkSMProxy* smProxy, 
    QWidget* parentObject)
  : QFrame(parentObject)
  , Proxy(smProxy)
  , Property(nullptr)
  , ChangeAvailableAsChangeFinished(true)
  , Selected(false)
  , Timer(new pqTimer())
{
  this->setFrameShape(QFrame::NoFrame);
  this->ShowLabel = true;
  /* b
  this->Links.setAutoUpdateVTKObjects(false);
  this->Links.setUseUncheckedProperties(true);

  this->connect(&this->Links, SIGNAL(qtWidgetChanged()), this, SIGNAL(changeAvailable()));
  */
  // This has to be a QueuedConnection otherwise changeFinished() gets fired
  // before changeAvailable() is handled by pqProxyWidget and see BUG #13029.
  this->Timer->setSingleShot(true);
  this->Timer->setInterval(0);
  this->Timer->connect(this, SIGNAL(changeAvailable()), SLOT(start()));
  this->connect(this->Timer.data(), SIGNAL(timeout()), SLOT(onChangeAvailable()));
}

//-----------------------------------------------------------------------------
pqPropertyWidget::~pqPropertyWidget()
{
  Q_FOREACH (pqPropertyWidgetDecorator* decorator, this->Decorators)
  {
    delete decorator;
  }

  this->Decorators.clear();
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::onChangeAvailable()
{
  if (this->ChangeAvailableAsChangeFinished)
  {
    Q_EMIT this->changeFinished();
  }
}
/* b
//-----------------------------------------------------------------------------
pqView* pqPropertyWidget::view() const
{
  return this->View;
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::setView(pqView* pqview)
{
  this->View = pqview;
  Q_EMIT this->viewChanged(pqview);
}
*/
//-----------------------------------------------------------------------------
vtkSMProxy* pqPropertyWidget::proxy() const
{
  return this->Proxy;
}

//-----------------------------------------------------------------------------
QString pqPropertyWidget::getTooltip(vtkSMProperty* smproperty)
{
    /* b
  if (smproperty && smproperty->GetDocumentation())
  {
    QString doc = pqProxy::rstToHtml(smproperty->GetDocumentation()->GetDescription()).c_str();
    doc = doc.trimmed();
    doc = doc.replace(QRegExp("\\s+"), " ");
    return QString("<html><head/><body><p align=\"justify\">%1</p></body></html>").arg(doc);
  }
  */
  return QString();
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::setProperty(vtkSMProperty* smproperty)
{
  this->Property = smproperty;
  this->setToolTip(pqPropertyWidget::getTooltip(smproperty));
  if ((smproperty->GetHints() &&
        smproperty->GetHints()->FindNestedElementByName("RestartRequired")))
  {
    this->connect(this, SIGNAL(changeAvailable()), SIGNAL(restartRequired()));
  }
}

//-----------------------------------------------------------------------------
vtkSMProperty* pqPropertyWidget::property() const
{
  return this->Property;
}

//-----------------------------------------------------------------------------
char* pqPropertyWidget::panelVisibility() const
{
  return this->Property->GetPanelVisibility();
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::setPanelVisibility(const char* vis)
{
  return this->Property->SetPanelVisibility(vis);
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::apply()
{
    /* b
  BEGIN_UNDO_SET("Property Changed");
  this->Links.accept();
  END_UNDO_SET();
  */
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::reset()
{
  // b this->Links.reset();
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::setShowLabel(bool isLabelVisible)
{
  this->ShowLabel = isLabelVisible;
}

//-----------------------------------------------------------------------------
bool pqPropertyWidget::showLabel() const
{
  return this->ShowLabel;
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::addPropertyLink(QObject* qobject, const char* qproperty, const char* qsignal,
  vtkSMProperty* smproperty, int smindex)
{
  // b this->Links.addPropertyLink(qobject, qproperty, qsignal, this->Proxy, smproperty, smindex);
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::addPropertyLink(QObject* qobject, const char* qproperty, const char* qsignal,
  vtkSMProxy* smproxy, vtkSMProperty* smproperty, int smindex)
{
  // b this->Links.addPropertyLink(qobject, qproperty, qsignal, smproxy, smproperty, smindex);
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::removePropertyLink(QObject* qobject, const char* qproperty,
  const char* qsignal, vtkSMProperty* smproperty, int smindex)
{
  // b this->Links.removePropertyLink(qobject, qproperty, qsignal, this->Proxy, smproperty, smindex);
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::removePropertyLink(QObject* qobject, const char* qproperty,
  const char* qsignal, vtkSMProxy* smproxy, vtkSMProperty* smproperty, int smindex)
{
  // b this->Links.removePropertyLink(qobject, qproperty, qsignal, smproxy, smproperty, smindex);
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::addDecorator(pqPropertyWidgetDecorator* decorator)
{
  if (!decorator || decorator->parent() != this)
  {
    qCritical("Either the decorator is NULL or has an invalid parent."
              "Please check the code.");
  }
  else
  {
    this->Decorators.push_back(decorator);
  }
}

//-----------------------------------------------------------------------------
void pqPropertyWidget::removeDecorator(pqPropertyWidgetDecorator* decorator)
{
  this->Decorators.removeAll(decorator);
}

//-----------------------------------------------------------------------------
int pqPropertyWidget::hintsWidgetHeightNumberOfRows(vtkPVXMLElement* hints, int defaultValue)
{
  if (vtkPVXMLElement* element = hints ? hints->FindNestedElementByName("WidgetHeight") : nullptr)
  {
    int rowCount = 0;
    if (element->GetScalarAttribute("number_of_rows", &rowCount))
    {
      return rowCount;
    }
  }
  return defaultValue;
}

bool pqPropertyWidget::isSingleRowItem() const
{
  return false;
}
