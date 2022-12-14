target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPVLogger.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPVLogger.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
