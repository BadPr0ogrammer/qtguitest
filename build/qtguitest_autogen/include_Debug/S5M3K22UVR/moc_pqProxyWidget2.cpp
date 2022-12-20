/****************************************************************************
** Meta object code from reading C++ file 'pqProxyWidget2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/Components/pqProxyWidget2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqProxyWidget2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqProxyWidget_t {
    QByteArrayData data[25];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqProxyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqProxyWidget_t qt_meta_stringdata_pqProxyWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "pqProxyWidget"
QT_MOC_LITERAL(1, 14, 15), // "changeAvailable"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 14), // "changeFinished"
QT_MOC_LITERAL(4, 46, 15), // "restartRequired"
QT_MOC_LITERAL(5, 62, 13), // "filterWidgets"
QT_MOC_LITERAL(6, 76, 13), // "show_advanced"
QT_MOC_LITERAL(7, 90, 10), // "filterText"
QT_MOC_LITERAL(8, 101, 27), // "showLinkedInteractiveWidget"
QT_MOC_LITERAL(9, 129, 9), // "portIndex"
QT_MOC_LITERAL(10, 139, 4), // "show"
QT_MOC_LITERAL(11, 144, 5), // "apply"
QT_MOC_LITERAL(12, 150, 5), // "reset"
QT_MOC_LITERAL(13, 156, 11), // "updatePanel"
QT_MOC_LITERAL(14, 168, 15), // "restoreDefaults"
QT_MOC_LITERAL(15, 184, 14), // "saveAsDefaults"
QT_MOC_LITERAL(16, 199, 23), // "createWidgetForProperty"
QT_MOC_LITERAL(17, 223, 17), // "pqPropertyWidget*"
QT_MOC_LITERAL(18, 241, 14), // "vtkSMProperty*"
QT_MOC_LITERAL(19, 256, 8), // "property"
QT_MOC_LITERAL(20, 265, 11), // "vtkSMProxy*"
QT_MOC_LITERAL(21, 277, 5), // "proxy"
QT_MOC_LITERAL(22, 283, 8), // "QWidget*"
QT_MOC_LITERAL(23, 292, 9), // "parentObj"
QT_MOC_LITERAL(24, 302, 16) // "onChangeFinished"

    },
    "pqProxyWidget\0changeAvailable\0\0"
    "changeFinished\0restartRequired\0"
    "filterWidgets\0show_advanced\0filterText\0"
    "showLinkedInteractiveWidget\0portIndex\0"
    "show\0apply\0reset\0updatePanel\0"
    "restoreDefaults\0saveAsDefaults\0"
    "createWidgetForProperty\0pqPropertyWidget*\0"
    "vtkSMProperty*\0property\0vtkSMProxy*\0"
    "proxy\0QWidget*\0parentObj\0onChangeFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqProxyWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   87,    2, 0x0a /* Public */,
       5,    1,   92,    2, 0x2a /* Public | MethodCloned */,
       5,    0,   95,    2, 0x2a /* Public | MethodCloned */,
       8,    2,   96,    2, 0x0a /* Public */,
      11,    0,  101,    2, 0x0a /* Public */,
      12,    0,  102,    2, 0x0a /* Public */,
      13,    0,  103,    2, 0x0a /* Public */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,
      16,    3,  106,    2, 0x0a /* Public */,
      24,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::Bool, QMetaType::QString,    6,    7,
    QMetaType::Bool, QMetaType::Bool,    6,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    0x80000000 | 17, 0x80000000 | 18, 0x80000000 | 20, 0x80000000 | 22,   19,   21,   23,
    QMetaType::Void,

       0        // eod
};

void pqProxyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqProxyWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeAvailable(); break;
        case 1: _t->changeFinished(); break;
        case 2: _t->restartRequired(); break;
        case 3: { bool _r = _t->filterWidgets((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->filterWidgets((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->filterWidgets();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->showLinkedInteractiveWidget((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->apply(); break;
        case 8: _t->reset(); break;
        case 9: _t->updatePanel(); break;
        case 10: { bool _r = _t->restoreDefaults();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->saveAsDefaults(); break;
        case 12: { pqPropertyWidget* _r = _t->createWidgetForProperty((*reinterpret_cast< vtkSMProperty*(*)>(_a[1])),(*reinterpret_cast< vtkSMProxy*(*)>(_a[2])),(*reinterpret_cast< QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< pqPropertyWidget**>(_a[0]) = std::move(_r); }  break;
        case 13: _t->onChangeFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (pqProxyWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqProxyWidget::changeAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (pqProxyWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqProxyWidget::changeFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (pqProxyWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&pqProxyWidget::restartRequired)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pqProxyWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_pqProxyWidget.data,
    qt_meta_data_pqProxyWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqProxyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqProxyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqProxyWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int pqProxyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void pqProxyWidget::changeAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void pqProxyWidget::changeFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void pqProxyWidget::restartRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
