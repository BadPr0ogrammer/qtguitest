
#ifndef VTKREMOTINGSETTINGS_EXPORT_H
#define VTKREMOTINGSETTINGS_EXPORT_H

#ifdef VTKREMOTINGSETTINGS_STATIC_DEFINE
#  define VTKREMOTINGSETTINGS_EXPORT
#  define VTKREMOTINGSETTINGS_NO_EXPORT
#else
#  ifndef VTKREMOTINGSETTINGS_EXPORT
#    ifdef RemotingSettings_EXPORTS
        /* We are building this library */
#      define VTKREMOTINGSETTINGS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKREMOTINGSETTINGS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKREMOTINGSETTINGS_NO_EXPORT
#    define VTKREMOTINGSETTINGS_NO_EXPORT 
#  endif
#endif

#ifndef VTKREMOTINGSETTINGS_DEPRECATED
#  define VTKREMOTINGSETTINGS_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKREMOTINGSETTINGS_DEPRECATED_EXPORT
#  define VTKREMOTINGSETTINGS_DEPRECATED_EXPORT VTKREMOTINGSETTINGS_EXPORT VTKREMOTINGSETTINGS_DEPRECATED
#endif

#ifndef VTKREMOTINGSETTINGS_DEPRECATED_NO_EXPORT
#  define VTKREMOTINGSETTINGS_DEPRECATED_NO_EXPORT VTKREMOTINGSETTINGS_NO_EXPORT VTKREMOTINGSETTINGS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKREMOTINGSETTINGS_NO_DEPRECATED
#    define VTKREMOTINGSETTINGS_NO_DEPRECATED
#  endif
#endif

#endif /* VTKREMOTINGSETTINGS_EXPORT_H */
