target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkSmartPyObject.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkSmartPyObject.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
