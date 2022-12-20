target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqApplicationComponentsInit2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqApplicationComponentsInit2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqParaViewBehaviors2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqParaViewBehaviors2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPVApplicationCore2.cxx    
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPVApplicationCore2.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
