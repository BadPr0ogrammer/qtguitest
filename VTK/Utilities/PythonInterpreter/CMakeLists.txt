target_sources(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInteractiveInterpreter2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInteractiveInterpreter2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInterpreter2.cxx 
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonInterpreter2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vtkPythonStdStreamCaptureHelper2.h 
)

target_include_directories(qtguitest
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
