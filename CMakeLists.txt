cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(qtguitest)

cmake_policy(SET CMP0091 NEW)

include(GNUInstallDirs)
if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
endif ()
if (NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
endif ()
if (NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
endif ()

set(CMAKE_BUILD_TYPE Debug)
set(BUILD_SHARED_LIBS ON)

set(AUTOGEN_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/qtguitest_autogen/include)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_compile_definitions(PARAVIEW_USE_PYTHON)
add_compile_definitions(VTK_MODULE_ENABLE_ParaView_pqPython)

set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_POSITION_INDEPENDENT_CODE 1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
set(CMAKE_CXX_EXTENSIONS 0)

set (INCL_DIRS
	"${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/include/vtk-9.0"
    "${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/include/qt5" 
    "${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/include/qt5/QtCore" 
	"${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/include/qt5/QtWidgets" 
	"${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/include/qt5/QtGui"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/pvpythonmodules"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/vtkpythonmodules"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11"
	"${PROJECT_SOURCE_DIR}/Clients/ParaView"	    
	"${PROJECT_SOURCE_DIR}/Qt/ApplicationComponents" 
	"${PROJECT_SOURCE_DIR}/Qt/Components"
	"${PROJECT_SOURCE_DIR}/Qt/Core"
	"${PROJECT_SOURCE_DIR}/Qt/Python"
	"${PROJECT_SOURCE_DIR}/Qt/Widgets"
	"${PROJECT_SOURCE_DIR}/Remoting/Core"
	"${PROJECT_SOURCE_DIR}/Remoting/ServerManager"
	"${PROJECT_SOURCE_DIR}/VTKExtensions/Core"
	"${PROJECT_SOURCE_DIR}/ThirdParty/QtTesting/vtkqttesting"
)
include_directories(${INCL_DIRS})

set(Qt5_DIR "${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/share/cmake/Qt5")
set(qt_xmlpatterns_executable "${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/tools/qt5-xmlpatterns/bin/xmlpatterns.exe")

find_package(Qt5 REQUIRED GLOBAL COMPONENTS Core Widgets)

find_package(VTK REQUIRED)
#set(VTK_INCL_DIRS "C:/vcpkg/installed/x64-windows/include/vtk-9.0")

set(Python_ROOT     "${PROJECT_SOURCE_DIR}/../Python311" CACHE PATH "..." FORCE)
include_directories("${PROJECT_SOURCE_DIR}/../Python311/include")
find_package(PythonLibs REQUIRED)

add_compile_definitions(VTK_ALL_NEW_OBJECT_FACTORY)

add_compile_definitions(PQAPPLICATIONCOMPONENTS_STATIC_DEFINE)
add_compile_definitions(PQCOMPONENTS_STATIC_DEFINE)
add_compile_definitions(PQCORE_STATIC_DEFINE)
add_compile_definitions(PQWIDGETS_STATIC_DEFINE)
add_compile_definitions(PQPYTHON_STATIC_DEFINE)

add_compile_definitions(VTKPVVTKEXTENSIONSCORE_STATIC_DEFINE)
add_compile_definitions(VTKREMOTINGCORE_STATIC_DEFINE)
add_compile_definitions(VTKREMOTINGSERVERMANAGER_STATIC_DEFINE)

#add_compile_definitions(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP)
#set(_CRT_USE_WINAPI_FAMILY_DESKTOP_APP 1)

add_executable(qtguitest main.cpp)

add_library(vtkqttesting STATIC)
target_include_directories(vtkqttesting PRIVATE ${INCL_DIRS})

add_library(pqApplicationComponents2 STATIC)
target_include_directories(pqApplicationComponents2 PRIVATE ${INCL_DIRS})

add_library(pqComponents2 STATIC)
target_include_directories(pqComponents2 PRIVATE ${INCL_DIRS})

add_library(pqCore2 STATIC)
target_include_directories(pqCore2 PRIVATE ${INCL_DIRS})

add_library(pqWidgets2 STATIC)
target_include_directories(pqWidgets2 PRIVATE ${INCL_DIRS})

add_library(pqPython2 STATIC)
target_include_directories(pqPython2 PRIVATE ${INCL_DIRS})

add_library(RemotingCore2 STATIC)
target_include_directories(RemotingCore2 PRIVATE ${INCL_DIRS})

add_library(RemotingServerManager2 STATIC)
target_include_directories(RemotingServerManager2 PRIVATE ${INCL_DIRS})

add_library(VTKExtensionsCore2 STATIC)
target_include_directories(VTKExtensionsCore2 PRIVATE ${INCL_DIRS})

add_subdirectory(include)
add_subdirectory(Clients)
add_subdirectory(Qt)
add_subdirectory(VTKExtensions)
add_subdirectory(Remoting)
add_subdirectory(ThirdParty)

target_link_libraries(qtguitest
    PRIVATE
	vtkqttesting
    Qt5::Core
    Qt5::Widgets
	VTK::CommonCore
	VTK::GUISupportQt
	VTK::PythonInterpreter
	VTK::WrappingPythonCore
	pqApplicationComponents2
	pqComponents2
	pqCore2
	pqWidgets2
	pqPython2
	RemotingCore2
	RemotingServerManager2
	VTKExtensionsCore2
    "${PROJECT_SOURCE_DIR}/../ParaView-v5.11.0/out/install/x64-Debug/lib/vtksys-pv5.11d.lib"
    "${PROJECT_SOURCE_DIR}/../Python311/libs/python311_d.lib"
)
