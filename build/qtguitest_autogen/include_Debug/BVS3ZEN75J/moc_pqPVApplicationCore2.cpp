/****************************************************************************
** Meta object code from reading C++ file 'pqPVApplicationCore2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/ApplicationComponents/pqPVApplicationCore2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqPVApplicationCore2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqPVApplicationCore_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqPVApplicationCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqPVApplicationCore_t qt_meta_stringdata_pqPVApplicationCore = {
    {
QT_MOC_LITERAL(0, 0, 19), // "pqPVApplicationCore"
QT_MOC_LITERAL(1, 20, 22), // "aboutToShowQuickLaunch"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 12), // "triggerApply"
QT_MOC_LITERAL(4, 57, 13), // "applyPipeline"
QT_MOC_LITERAL(5, 71, 11), // "quickLaunch"
QT_MOC_LITERAL(6, 83, 11) // "startSearch"

    },
    "pqPVApplicationCore\0aboutToShowQuickLaunch\0"
    "\0triggerApply\0applyPipeline\0quickLaunch\0"
    "startSearch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqPVApplicationCore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pqPVApplicationCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqPVApplicationCore *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aboutToShowQuickLaunch(); break;
        case 1: _t->triggerApply(); break;
        case 2: _t->applyPipeline(); break;
        case 3: _t->quickLaunch(); break;
        case 4: _t->startSearch(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pqPVApplicationCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPVApplicationCore::aboutToShowQuickLaunch)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pqPVApplicationCore::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPVApplicationCore::triggerApply)) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject pqPVApplicationCore::staticMetaObject = { {
    QMetaObject::SuperData::link<pqApplicationCore::staticMetaObject>(),
    qt_meta_stringdata_pqPVApplicationCore.data,
    qt_meta_data_pqPVApplicationCore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqPVApplicationCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqPVApplicationCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqPVApplicationCore.stringdata0))
        return static_cast<void*>(this);
    return pqApplicationCore::qt_metacast(_clname);
}

int pqPVApplicationCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = pqApplicationCore::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void pqPVApplicationCore::aboutToShowQuickLaunch()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pqPVApplicationCore::triggerApply()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
