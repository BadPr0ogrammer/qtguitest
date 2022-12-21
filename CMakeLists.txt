cmake_minimum_required(VERSION 3.12...3.16 FATAL_ERROR)
project(qtguitest)

set(CMAKE_BUILD_TYPE Debug)

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

set(BUILD_SHARED_LIBS ON)

set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Qt5_DIR "${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/share/cmake/Qt5")
set(qt_xmlpatterns_executable "${PROJECT_SOURCE_DIR}/../vcpkg/installed/x64-windows/tools/qt5-xmlpatterns/bin/xmlpatterns.exe")

include_directories(
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/vtkkwiml"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/vtksys"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/vtkqttesting"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/pvpythonmodules"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/vtkpythonmodules"
	"${PROJECT_SOURCE_DIR}/include/paraview-5.11/vtkprotobuf/src"
)

find_package(Qt5 REQUIRED GLOBAL COMPONENTS Core Widgets)

add_compile_definitions(PARAVIEW_USE_PYTHON)
set(Python_ROOT     "${PROJECT_SOURCE_DIR}/../Python311" CACHE PATH "..." FORCE)
include_directories("${PROJECT_SOURCE_DIR}/../Python311/include")
find_package(PythonLibs REQUIRED)

set(CMAKE_AUTOMOC 1)
set(CMAKE_AUTOUIC 1)
set(CMAKE_AUTORCC 1)

add_executable(qtguitest main.cpp)

add_compile_definitions(PQPYTHON_STATIC_DEFINE)
add_compile_definitions(PQAPPLICATIONCOMPONENTS_STATIC_DEFINE)
add_compile_definitions(PQCOMPONENTS_STATIC_DEFINE)
add_compile_definitions(PQCORE_STATIC_DEFINE)
add_compile_definitions(PQWIDGETS_STATIC_DEFINE)
add_compile_definitions(VTKCOMMONCORE_STATIC_DEFINE)
add_compile_definitions(VTKPVVTKEXTENSIONSCORE_STATIC_DEFINE)
add_compile_definitions(VTKGUISUPPORTQT_STATIC_DEFINE)
add_compile_definitions(VTKPYTHONINTERPRETER_STATIC_DEFINE)
add_compile_definitions(VTKWRAPPINGPYTHONCORE_STATIC_DEFINE)
add_compile_definitions(VTKREMOTINGCORE_STATIC_DEFINE)
add_compile_definitions(VTKCOMMONMISC_STATIC_DEFINE)
add_compile_definitions(VTKREMOTINGSERVERMANAGER_STATIC_DEFINE)

add_compile_definitions(VTK_MODULE_ENABLE_ParaView_pqPython)

add_subdirectory(include)
add_subdirectory(Clients)
add_subdirectory(Qt)
add_subdirectory(VTK)
add_subdirectory(VTKExtensions)
add_subdirectory(Remoting)

# target_sources(qtguitest PUBLIC ${RCC_SOURCES})

target_link_libraries(qtguitest
    PRIVATE
    Qt5::Core
    Qt5::Widgets
    "${PROJECT_SOURCE_DIR}/../ParaView-v5.11.0/out/install/x64-Debug/lib/vtksys-pv5.11d.lib"
    "${PROJECT_SOURCE_DIR}/../Python311/libs/python311_d.lib"
)
