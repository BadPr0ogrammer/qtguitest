
#ifndef PQWIDGETS_EXPORT_H
#define PQWIDGETS_EXPORT_H

#ifdef PQWIDGETS_STATIC_DEFINE
#  define PQWIDGETS_EXPORT
#  define PQWIDGETS_NO_EXPORT
#else
#  ifndef PQWIDGETS_EXPORT
#    ifdef pqWidgets_EXPORTS
        /* We are building this library */
#      define PQWIDGETS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define PQWIDGETS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef PQWIDGETS_NO_EXPORT
#    define PQWIDGETS_NO_EXPORT 
#  endif
#endif

#ifndef PQWIDGETS_DEPRECATED
#  define PQWIDGETS_DEPRECATED __declspec(deprecated)
#endif

#ifndef PQWIDGETS_DEPRECATED_EXPORT
#  define PQWIDGETS_DEPRECATED_EXPORT PQWIDGETS_EXPORT PQWIDGETS_DEPRECATED
#endif

#ifndef PQWIDGETS_DEPRECATED_NO_EXPORT
#  define PQWIDGETS_DEPRECATED_NO_EXPORT PQWIDGETS_NO_EXPORT PQWIDGETS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PQWIDGETS_NO_DEPRECATED
#    define PQWIDGETS_NO_DEPRECATED
#  endif
#endif

#endif /* PQWIDGETS_EXPORT_H */
