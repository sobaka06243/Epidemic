/****************************************************************************
** Meta object code from reading C++ file 'infectedball.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../infectedball.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infectedball.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InfectedBall_t {
    const uint offsetsAndSize[6];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_InfectedBall_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_InfectedBall_t qt_meta_stringdata_InfectedBall = {
    {
QT_MOC_LITERAL(0, 12), // "InfectedBall"
QT_MOC_LITERAL(13, 13), // "slot_timerOut"
QT_MOC_LITERAL(27, 0) // ""

    },
    "InfectedBall\0slot_timerOut\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfectedBall[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    0 /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void InfectedBall::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InfectedBall *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_timerOut(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject InfectedBall::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_InfectedBall.offsetsAndSize,
    qt_meta_data_InfectedBall,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_InfectedBall_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *InfectedBall::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfectedBall::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InfectedBall.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "BallItem"))
        return static_cast< BallItem*>(this);
    return QWidget::qt_metacast(_clname);
}

int InfectedBall::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
