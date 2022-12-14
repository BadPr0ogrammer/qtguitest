target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqConsoleWidget.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqConsoleWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqSetName.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqSetName.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqWidgetsInit.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqWidgetsInit.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqClickableLabel.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqClickableLabel.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
