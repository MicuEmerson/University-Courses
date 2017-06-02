/****************************************************************************
** Meta object code from reading C++ file 'myclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myClass_t {
    QByteArrayData data[12];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myClass_t qt_meta_stringdata_myClass = {
    {
QT_MOC_LITERAL(0, 0, 7), // "myClass"
QT_MOC_LITERAL(1, 8, 8), // "sortting"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 8), // "repoInit"
QT_MOC_LITERAL(4, 27, 10), // "addNewCoat"
QT_MOC_LITERAL(5, 38, 10), // "deleteCoat"
QT_MOC_LITERAL(6, 49, 10), // "updateCoat"
QT_MOC_LITERAL(7, 60, 6), // "filter"
QT_MOC_LITERAL(8, 67, 10), // "filterSize"
QT_MOC_LITERAL(9, 78, 8), // "addToBag"
QT_MOC_LITERAL(10, 87, 8), // "seePhoto"
QT_MOC_LITERAL(11, 96, 13) // "seeBagContent"

    },
    "myClass\0sortting\0\0repoInit\0addNewCoat\0"
    "deleteCoat\0updateCoat\0filter\0filterSize\0"
    "addToBag\0seePhoto\0seeBagContent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myClass *_t = static_cast<myClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sortting(); break;
        case 1: _t->repoInit(); break;
        case 2: _t->addNewCoat(); break;
        case 3: _t->deleteCoat(); break;
        case 4: _t->updateCoat(); break;
        case 5: _t->filter(); break;
        case 6: _t->filterSize(); break;
        case 7: _t->addToBag(); break;
        case 8: _t->seePhoto(); break;
        case 9: _t->seeBagContent(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject myClass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myClass.data,
      qt_meta_data_myClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myClass.stringdata0))
        return static_cast<void*>(const_cast< myClass*>(this));
    return QWidget::qt_metacast(_clname);
}

int myClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
