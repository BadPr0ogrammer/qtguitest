/****************************************************************************
** Meta object code from reading C++ file 'pqPythonFileIO2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/Python/pqPythonFileIO2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqPythonFileIO2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqPythonFileIO_t {
    QByteArrayData data[12];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqPythonFileIO_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqPythonFileIO_t qt_meta_stringdata_pqPythonFileIO = {
    {
QT_MOC_LITERAL(0, 0, 14), // "pqPythonFileIO"
QT_MOC_LITERAL(1, 15, 12), // "bufferErased"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "fileOpened"
QT_MOC_LITERAL(4, 40, 9), // "fileSaved"
QT_MOC_LITERAL(5, 50, 14), // "contentChanged"
QT_MOC_LITERAL(6, 65, 11), // "setModified"
QT_MOC_LITERAL(7, 77, 8), // "modified"
QT_MOC_LITERAL(8, 86, 4), // "save"
QT_MOC_LITERAL(9, 91, 6), // "saveAs"
QT_MOC_LITERAL(10, 98, 11), // "saveAsMacro"
QT_MOC_LITERAL(11, 110, 12) // "saveAsScript"

    },
    "pqPythonFileIO\0bufferErased\0\0fileOpened\0"
    "fileSaved\0contentChanged\0setModified\0"
    "modified\0save\0saveAs\0saveAsMacro\0"
    "saveAsScript"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqPythonFileIO[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       4,    1,   63,    2, 0x06 /* Public */,
       5,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   67,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void pqPythonFileIO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqPythonFileIO *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bufferErased(); break;
        case 1: _t->fileOpened((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->fileSaved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->contentChanged(); break;
        case 4: _t->setModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->saveAsMacro();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->saveAsScript();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pqPythonFileIO::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPythonFileIO::bufferErased)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pqPythonFileIO::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPythonFileIO::fileOpened)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pqPythonFileIO::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPythonFileIO::fileSaved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (pqPythonFileIO::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPythonFileIO::contentChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pqPythonFileIO::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_pqPythonFileIO.data,
    qt_meta_data_pqPythonFileIO,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqPythonFileIO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqPythonFileIO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqPythonFileIO.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pqPythonFileIO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void pqPythonFileIO::bufferErased()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pqPythonFileIO::fileOpened(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pqPythonFileIO::fileSaved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pqPythonFileIO::contentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
