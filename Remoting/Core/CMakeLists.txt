target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkParaViewDeprecation2.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkNetworkAccessManager2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkNetworkAccessManager2.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
