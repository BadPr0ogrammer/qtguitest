
#ifndef PQCORE_EXPORT_H
#define PQCORE_EXPORT_H

#ifdef PQCORE_STATIC_DEFINE
#  define PQCORE_EXPORT
#  define PQCORE_NO_EXPORT
#else
#  ifndef PQCORE_EXPORT
#    ifdef pqCore_EXPORTS
        /* We are building this library */
#      define PQCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQCORE_NO_EXPORT
#    define PQCORE_NO_EXPORT 
#  endif
#endif

#ifndef PQCORE_DEPRECATED
#  define PQCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef PQCORE_DEPRECATED_EXPORT
#  define PQCORE_DEPRECATED_EXPORT PQCORE_EXPORT PQCORE_DEPRECATED
#endif

#ifndef PQCORE_DEPRECATED_NO_EXPORT
#  define PQCORE_DEPRECATED_NO_EXPORT PQCORE_NO_EXPORT PQCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PQCORE_NO_DEPRECATED
#    define PQCORE_NO_DEPRECATED
#  endif
#endif

#endif /* PQCORE_EXPORT_H */
