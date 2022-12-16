
#ifndef PQCOMPONENTS_EXPORT_H
#define PQCOMPONENTS_EXPORT_H

#ifdef PQCOMPONENTS_STATIC_DEFINE
#  define PQCOMPONENTS_EXPORT
#  define PQCOMPONENTS_NO_EXPORT
#else
#  ifndef PQCOMPONENTS_EXPORT
#    ifdef pqComponents_EXPORTS
        /* We are building this library */
#      define PQCOMPONENTS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQCOMPONENTS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQCOMPONENTS_NO_EXPORT
#    define PQCOMPONENTS_NO_EXPORT 
#  endif
#endif

#ifndef PQCOMPONENTS_DEPRECATED
#  define PQCOMPONENTS_DEPRECATED __declspec(deprecated)
#endif

#ifndef PQCOMPONENTS_DEPRECATED_EXPORT
#  define PQCOMPONENTS_DEPRECATED_EXPORT PQCOMPONENTS_EXPORT PQCOMPONENTS_DEPRECATED
#endif

#ifndef PQCOMPONENTS_DEPRECATED_NO_EXPORT
#  define PQCOMPONENTS_DEPRECATED_NO_EXPORT PQCOMPONENTS_NO_EXPORT PQCOMPONENTS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PQCOMPONENTS_NO_DEPRECATED
#    define PQCOMPONENTS_NO_DEPRECATED
#  endif
#endif

#endif /* PQCOMPONENTS_EXPORT_H */
