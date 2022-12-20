/****************************************************************************
** Meta object code from reading C++ file 'pqApplicationCore2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/Core/pqApplicationCore2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqApplicationCore2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqApplicationCore_t {
    QByteArrayData data[5];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqApplicationCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqApplicationCore_t qt_meta_stringdata_pqApplicationCore = {
    {
QT_MOC_LITERAL(0, 0, 17), // "pqApplicationCore"
QT_MOC_LITERAL(1, 18, 22), // "forceFilterMenuRefresh"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 23), // "updateMasterEnableState"
QT_MOC_LITERAL(4, 66, 21) // "clientEnvironmentDone"

    },
    "pqApplicationCore\0forceFilterMenuRefresh\0"
    "\0updateMasterEnableState\0clientEnvironmentDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqApplicationCore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       4,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void pqApplicationCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqApplicationCore *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->forceFilterMenuRefresh(); break;
        case 1: _t->updateMasterEnableState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->clientEnvironmentDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pqApplicationCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqApplicationCore::forceFilterMenuRefresh)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pqApplicationCore::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqApplicationCore::updateMasterEnableState)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pqApplicationCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqApplicationCore::clientEnvironmentDone)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pqApplicationCore::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_pqApplicationCore.data,
    qt_meta_data_pqApplicationCore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqApplicationCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqApplicationCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqApplicationCore.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pqApplicationCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void pqApplicationCore::forceFilterMenuRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pqApplicationCore::updateMasterEnableState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pqApplicationCore::clientEnvironmentDone()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
