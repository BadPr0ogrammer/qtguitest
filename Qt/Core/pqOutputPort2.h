#ifndef pqOutputPort_h
#define pqOutputPort_h

#include "pqCoreModule.h"
#include "pqProxy2.h"

class pqPipelineSource;
/* b
class vtkSMSourceProxy;
class vtkPVDataInformation;
class pqDataRepresentation;
class pqServer;
class pqView;
class vtkPVTemporalDataInformation;
class vtkSMOutputPort;
*/
/**
 * pqOutputPort is a server manager model item for an output port of any
 * pqPipelineSource item. This makes it possible to refer to a particular
 * output port in the server manager model. The pqPipelineSource keeps
 * references to all its output ports. The only way to access pqOutputPort
 * items is through the pqPipelineSource. One can obtain the pqPipelineSource
 * item from a pqOutputPort using getSource().
 * Once the outputs can be named, we will change this class to use output port
 * names instead of numbers.
 */
class PQCORE_EXPORT pqOutputPort : public pqProxy
{
  Q_OBJECT
  typedef pqProxy Superclass;

public:
  pqOutputPort(pqPipelineSource* source, int portno);
  ~pqOutputPort() override;

  /**
   * Returns the vtkSMOutputPort proxy for this port.
   */
  // b vtkSMOutputPort* getOutputPortProxy() const;

  /**
   * Returns the pqPipelineSource whose output port this is.
   */
  pqPipelineSource* getSource() const { return this->Source; }

  /**
   * Return the vtkSMSourceProxy for the source.
   */
  // b vtkSMSourceProxy* getSourceProxy() const;

  /**
   * Returns the server connection on which this output port exists.
   */
  // b pqServer* getServer() const;

  /**
   * Returns the port number of the output port which this item represents.
   */
  int getPortNumber() const { return this->PortNumber; }

  /**
   * Returns the port name for this output port.
   */
  QString getPortName() const;

  /**
   * Returns the number of consumers connected to this output port.
   */
  int getNumberOfConsumers() const;

  /**
   * Get the consumer at a particular index on this output port.
   */
  pqPipelineSource* getConsumer(int index) const;

  /**
   * Returns a list of consumers.
   */
  QList<pqPipelineSource*> getConsumers() const;

  /**
   * Returns a list of representations for this output port in the given view.
   * If view == nullptr, returns all representations of this port.
   */
  // b QList<pqDataRepresentation*> getRepresentations(pqView* view) const;

  /**
   * Returns the first representation for this output port in the given view.
   * If view is nullptr, returns 0.
   */
  // b pqDataRepresentation* getRepresentation(pqView* view) const;

  /**
   * Returns a list of render modules in which this output port
   * has representations added (the representations may not be visible).
   */
  // b QList<pqView*> getViews() const;

  /**
   * Returns the current data information at this output port.
   * This does not update the pipeline, it simply returns the data information
   * for data currently present on the output port on the server.
   */
  // b vtkPVDataInformation* getDataInformation() const;

  /**
   * Returns rank-specific data information.
   */
  // b vtkPVDataInformation* getRankDataInformation(int rank) const;

  /**
   * Collects data information over time. This can potentially be a very slow
   * process, so use with caution.
   */
  // b vtkPVTemporalDataInformation* getTemporalDataInformation();

  /**
   * Returns the current data information for the selected data from this
   * output port.
   *
   * \c es_port is the output port from the internal vtkPVExtractSelection
   * proxy.
   *
   */
  // b vtkPVDataInformation* getSelectedDataInformation(int es_port = 0) const;

  /**
   * Returns the class name of the output data.
   */
  const char* getDataClassName() const;

  /**
   * Calls vtkSMSourceProxy::GetSelectionInput() on the underlying source
   * proxy.
   */
  // b vtkSMSourceProxy* getSelectionInput();

  /**
   * Calls vtkSMSourceProxy::GetSelectionInputPort() on the underlying source
   * proxy.
   */
  unsigned int getSelectionInputPort();

  /**
   * Set the selection input.
   */
  // b void setSelectionInput(vtkSMSourceProxy* src, int port);

  /**
   * Returns a user friendly name for this port.
   */
  QString prettyName() const;

public Q_SLOTS: // NOLINT(readability-redundant-access-specifiers)
  /**
   * This method updates all render modules to which all
   * representations for this source belong, if force is true, it for an
   * immediate render otherwise render on idle.
   */
  // b void renderAllViews(bool force = false);

Q_SIGNALS:
  /**
   * Fired when a connection is added between this output port and a consumer.
   */
  void connectionAdded(pqOutputPort* port, pqPipelineSource* consumer);
  void preConnectionAdded(pqOutputPort* port, pqPipelineSource* consumer);

  /**
   * Fired when a connection is removed between this output port and a consumer.
   */
  void connectionRemoved(pqOutputPort* port, pqPipelineSource* consumer);
  void preConnectionRemoved(pqOutputPort* port, pqPipelineSource* consumer);

  /**
   * fired when a representation is added.
   */
  // b void representationAdded(pqOutputPort* source, pqDataRepresentation* repr);

  /**
   * fired when a representation is removed.
   */
  // b void representationRemoved(pqOutputPort* source, pqDataRepresentation* repr);

  /**
   * Fired when the visbility of a representation for the source changes.
   * Also fired when representationAdded or representationRemoved is fired
   * since that too implies change in source visibility.
   */
  // b void visibilityChanged(pqOutputPort* source, pqDataRepresentation* repr);

protected Q_SLOTS:
  // b void onRepresentationVisibilityChanged();

protected: // NOLINT(readability-redundant-access-specifiers)
  friend class pqPipelineFilter;
  // b friend class pqDataRepresentation;

  /**
   * called by pqPipelineSource when the connections change.
   */
  void removeConsumer(pqPipelineSource*);
  void addConsumer(pqPipelineSource*);

  /**
   * Called by pqPipelineSource when the representations are added/removed.
   */
  // b void addRepresentation(pqDataRepresentation*);
  // b void removeRepresentation(pqDataRepresentation*);

  pqPipelineSource* Source;
  int PortNumber;

private:
  Q_DISABLE_COPY(pqOutputPort)

  class pqInternal;
  pqInternal* Internal;
};

#endif
