#include "vtkStdString.h"

//------------------------------------------------------------------------------
ostream& operator<<(ostream& os, const vtkStdString& s)
{
  return os << s.c_str();
}
