
#ifndef PQPYTHON_EXPORT_H
#define PQPYTHON_EXPORT_H

#ifdef PQPYTHON_STATIC_DEFINE
#  define PQPYTHON_EXPORT
#  define PQPYTHON_NO_EXPORT
#else
#  ifndef PQPYTHON_EXPORT
#    ifdef pqPython_EXPORTS
        /* We are building this library */
#      define PQPYTHON_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQPYTHON_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQPYTHON_NO_EXPORT
#    define PQPYTHON_NO_EXPORT 
#  endif
#endif

#ifndef PQPYTHON_DEPRECATED
#  define PQPYTHON_DEPRECATED __declspec(deprecated)
#endif

#ifndef PQPYTHON_DEPRECATED_EXPORT
#  define PQPYTHON_DEPRECATED_EXPORT PQPYTHON_EXPORT PQPYTHON_DEPRECATED
#endif

#ifndef PQPYTHON_DEPRECATED_NO_EXPORT
#  define PQPYTHON_DEPRECATED_NO_EXPORT PQPYTHON_NO_EXPORT PQPYTHON_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PQPYTHON_NO_DEPRECATED
#    define PQPYTHON_NO_DEPRECATED
#  endif
#endif

#endif /* PQPYTHON_EXPORT_H */
