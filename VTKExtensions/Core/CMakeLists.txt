target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPVLogger2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPVLogger2.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
