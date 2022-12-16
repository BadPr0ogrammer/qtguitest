target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkResourceFileLocator2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkResourceFileLocator2.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
