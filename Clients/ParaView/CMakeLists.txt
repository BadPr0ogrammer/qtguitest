target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewMainWindow.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewMainWindow.ui    
    ${CMAKE_CURRENT_SOURCE_DIR}/ParaViewMainWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqparaviewInitializer.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqparaviewInitializer.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
