/****************************************************************************
** Meta object code from reading C++ file 'pqPythonManager2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Qt/Python/pqPythonManager2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pqPythonManager2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pqPythonManager_t {
    QByteArrayData data[12];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pqPythonManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pqPythonManager_t qt_meta_stringdata_pqPythonManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "pqPythonManager"
QT_MOC_LITERAL(1, 16, 11), // "executeCode"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "code"
QT_MOC_LITERAL(4, 34, 19), // "QVector<QByteArray>"
QT_MOC_LITERAL(5, 54, 8), // "pre_push"
QT_MOC_LITERAL(6, 63, 9), // "post_push"
QT_MOC_LITERAL(7, 73, 13), // "executeScript"
QT_MOC_LITERAL(8, 87, 8), // "filename"
QT_MOC_LITERAL(9, 96, 22), // "executeScriptAndRender"
QT_MOC_LITERAL(10, 119, 9), // "editMacro"
QT_MOC_LITERAL(11, 129, 8) // "fileName"

    },
    "pqPythonManager\0executeCode\0\0code\0"
    "QVector<QByteArray>\0pre_push\0post_push\0"
    "executeScript\0filename\0executeScriptAndRender\0"
    "editMacro\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pqPythonManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x0a /* Public */,
       1,    2,   51,    2, 0x2a /* Public | MethodCloned */,
       1,    1,   56,    2, 0x2a /* Public | MethodCloned */,
       7,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      10,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void pqPythonManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pqPythonManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->executeCode((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[3]))); break;
        case 1: _t->executeCode((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QVector<QByteArray>(*)>(_a[2]))); break;
        case 2: _t->executeCode((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->executeScript((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->executeScriptAndRender((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->editMacro((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QByteArray> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pqPythonManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_pqPythonManager.data,
    qt_meta_data_pqPythonManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pqPythonManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pqPythonManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pqPythonManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int pqPythonManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
