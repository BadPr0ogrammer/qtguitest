/****************************************************************************
** Meta object code from reading C++ file 'pqPropertyWidget2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/Components/pqPropertyWidget2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqPropertyWidget2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqPropertyWidget_t {
    QByteArrayData data[6];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqPropertyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqPropertyWidget_t qt_meta_stringdata_pqPropertyWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "pqPropertyWidget"
QT_MOC_LITERAL(1, 17, 15), // "changeAvailable"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "changeFinished"
QT_MOC_LITERAL(4, 49, 15), // "restartRequired"
QT_MOC_LITERAL(5, 65, 17) // "onChangeAvailable"

    },
    "pqPropertyWidget\0changeAvailable\0\0"
    "changeFinished\0restartRequired\0"
    "onChangeAvailable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqPropertyWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void pqPropertyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqPropertyWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeAvailable(); break;
        case 1: _t->changeFinished(); break;
        case 2: _t->restartRequired(); break;
        case 3: _t->onChangeAvailable(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pqPropertyWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPropertyWidget::changeAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pqPropertyWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPropertyWidget::changeFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pqPropertyWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqPropertyWidget::restartRequired)) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject pqPropertyWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_pqPropertyWidget.data,
    qt_meta_data_pqPropertyWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqPropertyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqPropertyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqPropertyWidget.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int pqPropertyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void pqPropertyWidget::changeAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pqPropertyWidget::changeFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void pqPropertyWidget::restartRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
