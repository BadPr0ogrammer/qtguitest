/****************************************************************************
** Meta object code from reading C++ file 'pqOutputPort2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/Core/pqOutputPort2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqOutputPort2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqOutputPort_t {
    QByteArrayData data[10];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqOutputPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqOutputPort_t qt_meta_stringdata_pqOutputPort = {
    {
QT_MOC_LITERAL(0, 0, 12), // "pqOutputPort"
QT_MOC_LITERAL(1, 13, 15), // "connectionAdded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "pqOutputPort*"
QT_MOC_LITERAL(4, 44, 4), // "port"
QT_MOC_LITERAL(5, 49, 17), // "pqPipelineSource*"
QT_MOC_LITERAL(6, 67, 8), // "consumer"
QT_MOC_LITERAL(7, 76, 18), // "preConnectionAdded"
QT_MOC_LITERAL(8, 95, 17), // "connectionRemoved"
QT_MOC_LITERAL(9, 113, 20) // "preConnectionRemoved"

    },
    "pqOutputPort\0connectionAdded\0\0"
    "pqOutputPort*\0port\0pqPipelineSource*\0"
    "consumer\0preConnectionAdded\0"
    "connectionRemoved\0preConnectionRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqOutputPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       7,    2,   39,    2, 0x06 /* Public */,
       8,    2,   44,    2, 0x06 /* Public */,
       9,    2,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void pqOutputPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqOutputPort *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectionAdded((*reinterpret_cast< pqOutputPort*(*)>(_a[1])),(*reinterpret_cast< pqPipelineSource*(*)>(_a[2]))); break;
        case 1: _t->preConnectionAdded((*reinterpret_cast< pqOutputPort*(*)>(_a[1])),(*reinterpret_cast< pqPipelineSource*(*)>(_a[2]))); break;
        case 2: _t->connectionRemoved((*reinterpret_cast< pqOutputPort*(*)>(_a[1])),(*reinterpret_cast< pqPipelineSource*(*)>(_a[2]))); break;
        case 3: _t->preConnectionRemoved((*reinterpret_cast< pqOutputPort*(*)>(_a[1])),(*reinterpret_cast< pqPipelineSource*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pqOutputPort* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pqOutputPort* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pqOutputPort* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< pqOutputPort* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pqOutputPort::*)(pqOutputPort * , pqPipelineSource * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqOutputPort::connectionAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pqOutputPort::*)(pqOutputPort * , pqPipelineSource * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqOutputPort::preConnectionAdded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pqOutputPort::*)(pqOutputPort * , pqPipelineSource * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqOutputPort::connectionRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (pqOutputPort::*)(pqOutputPort * , pqPipelineSource * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqOutputPort::preConnectionRemoved)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pqOutputPort::staticMetaObject = { {
    QMetaObject::SuperData::link<pqProxy::staticMetaObject>(),
    qt_meta_stringdata_pqOutputPort.data,
    qt_meta_data_pqOutputPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqOutputPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqOutputPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqOutputPort.stringdata0))
        return static_cast<void*>(this);
    return pqProxy::qt_metacast(_clname);
}

int pqOutputPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = pqProxy::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void pqOutputPort::connectionAdded(pqOutputPort * _t1, pqPipelineSource * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pqOutputPort::preConnectionAdded(pqOutputPort * _t1, pqPipelineSource * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pqOutputPort::connectionRemoved(pqOutputPort * _t1, pqPipelineSource * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pqOutputPort::preConnectionRemoved(pqOutputPort * _t1, pqPipelineSource * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
