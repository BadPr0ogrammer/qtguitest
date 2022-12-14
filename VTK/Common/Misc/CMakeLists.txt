target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkResourceFileLocator.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkResourceFileLocator.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
