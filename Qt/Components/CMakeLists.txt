target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqComponentsInit2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqComponentsInit2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPipelineBrowserWidget.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPipelineBrowserWidget.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
