target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInteractiveInterpreter.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInteractiveInterpreter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInterpreter.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInterpreter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonStdStreamCaptureHelper.h 
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
