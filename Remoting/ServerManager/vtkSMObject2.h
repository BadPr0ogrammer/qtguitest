/**
 * @class   vtkSMObject
 * @brief   superclass for most server manager classes
 *
 * vtkSMObject is mostly to tag a class hierarchy that it belong to the
 * servermanager.
 */

#ifndef vtkSMObject_h
#define vtkSMObject_h

#include "vtkObject.h"
#include "vtkRemotingServerManagerModule.h" //needed for exports

class VTKREMOTINGSERVERMANAGER_EXPORT vtkSMObject : public vtkObject
{
public:
  static vtkSMObject* New();
  vtkTypeMacro(vtkSMObject, vtkObject);
  // b void PrintSelf(ostream& os, vtkIndent indent) override;

protected:
  vtkSMObject();
  ~vtkSMObject() override;

private:
  vtkSMObject(const vtkSMObject&) = delete;
  void operator=(const vtkSMObject&) = delete;
};

#endif
