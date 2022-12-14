target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqComponentsInit.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqComponentsInit.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
