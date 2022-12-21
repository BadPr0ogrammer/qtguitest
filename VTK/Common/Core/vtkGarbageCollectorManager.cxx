#include "vtkGarbageCollectorManager.h"

#include "vtkGarbageCollector.h"

// Must NOT be initialized.  Default initialization to zero is
// necessary.
static unsigned int vtkGarbageCollectorManagerCount;

vtkGarbageCollectorManager::vtkGarbageCollectorManager()
{
  if (++vtkGarbageCollectorManagerCount == 1)
  {
    vtkGarbageCollector::ClassInitialize();
  }
}

vtkGarbageCollectorManager::~vtkGarbageCollectorManager()
{
  if (--vtkGarbageCollectorManagerCount == 0)
  {
    vtkGarbageCollector::ClassFinalize();
  }
}
