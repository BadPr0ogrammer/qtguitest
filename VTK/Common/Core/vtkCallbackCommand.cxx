#include "vtkCallbackCommand.h"

//----------------------------------------------------------------
vtkCallbackCommand::vtkCallbackCommand()
{
  this->ClientData = nullptr;
  this->Callback = nullptr;
  this->ClientDataDeleteCallback = nullptr;
  this->AbortFlagOnExecute = 0;
}

//----------------------------------------------------------------
vtkCallbackCommand::~vtkCallbackCommand()
{
  if (this->ClientDataDeleteCallback)
  {
    this->ClientDataDeleteCallback(this->ClientData);
  }
}

//----------------------------------------------------------------
void vtkCallbackCommand::Execute(vtkObject* caller, unsigned long event, void* callData)
{
  if (this->Callback)
  {
    this->Callback(caller, event, this->ClientData, callData);
    if (this->AbortFlagOnExecute)
    {
      this->AbortFlagOn();
    }
  }
}
