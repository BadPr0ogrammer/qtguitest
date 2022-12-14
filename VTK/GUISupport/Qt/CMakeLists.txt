target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksView.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksView.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksModel.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkQtDebugLeaksModel.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
