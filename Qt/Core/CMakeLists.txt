target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/pqApplicationCore2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqApplicationCore2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqCoreInit2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqCoreInit2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqCoreUtilities2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqCoreUtilities2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqMainWindowEventManager2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqMainWindowEventManager2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqOutputPort2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqOutputPort2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqOutputWidget.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqOutputWidget.ui 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqOutputWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPipelineSource2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqPipelineSource2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqProxy2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqProxy2.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqRepresentation2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqRepresentation2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pqServerManagerModelItem2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqServerManagerModelItem2.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/pqTimeKeeper2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/pqTimeKeeper2.h
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(qtguitest PUBLIC Resources/pqCore.qrc)