target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPVApplicationCore.cxx    
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPVApplicationCore.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqApplicationComponentsInit.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqApplicationComponentsInit.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
