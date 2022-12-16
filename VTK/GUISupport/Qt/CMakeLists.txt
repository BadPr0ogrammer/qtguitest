target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksView2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksView2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksModel2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksModel2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkEventQtSlotConnect2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkEventQtSlotConnect2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtConnection2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtConnection2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/QVTKWin32Header2.h 
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
