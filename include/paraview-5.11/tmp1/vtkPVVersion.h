/*=========================================================================

  Program:   ParaView
  Module:    vtkPVVersion.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkPVVersion_h
#define vtkPVVersion_h

#define PARAVIEW_VERSION_MAJOR 5
#define PARAVIEW_VERSION_MINOR 11
#define PARAVIEW_VERSION_PATCH 0
#define PARAVIEW_VERSION "5.11"
#define PARAVIEW_VERSION_FULL "5.11.0"

#define PARAVIEW_VERSION_CHECK(major, minor, build)                                                     \
  (10000000000ULL * major + 100000000ULL * minor + build)
#define PARAVIEW_VERSION_NUMBER                                                                         \
  PARAVIEW_VERSION_CHECK(PARAVIEW_MAJOR_VERSION, PARAVIEW_MINOR_VERSION, PARAVIEW_BUILD_VERSION)

#endif
