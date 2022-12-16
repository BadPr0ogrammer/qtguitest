target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqConsoleWidget.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqConsoleWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqSetName2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqSetName2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqWidgetsInit2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqWidgetsInit2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqQtDeprecated2.h 
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
