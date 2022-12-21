#include "vtkStringOutputWindow.h"
#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkStringOutputWindow);

vtkStringOutputWindow::vtkStringOutputWindow()
{
  this->OStream.str("");
  this->OStream.clear();
}

vtkStringOutputWindow::~vtkStringOutputWindow() = default;

void vtkStringOutputWindow::Initialize()
{
  this->OStream.str("");
  this->OStream.clear();
}

void vtkStringOutputWindow::DisplayText(const char* text)
{
  if (!text)
  {
    return;
  }

  this->OStream << text << endl;
}

void vtkStringOutputWindow::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
