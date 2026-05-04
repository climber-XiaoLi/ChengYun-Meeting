/****************************************************************************
** Meta object code from reading C++ file 'ckernel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ckernel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ckernel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7CkernelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN7CkernelE = QtMocHelpers::stringData(
    "Ckernel",
    "setNetPackMap",
    "",
    "initConfig",
    "slot_destroy",
    "slot_loginCommit",
    "tel",
    "pass",
    "slot_registerCommit",
    "name",
    "slot_createRoom",
    "slot_joinRoom",
    "slot_quitRoom",
    "slot_audioFrame",
    "ba",
    "slot_dealData",
    "sock",
    "char*",
    "buf",
    "nlen",
    "slot_dealLoginRs",
    "slot_dealRegisterRs",
    "slot_dealCreateRoomRs",
    "slot_dealJoinRoomRs",
    "slot_dealRoomMemberRq",
    "slot_dealLeaveRoomRq",
    "slot_dealAudioFrameRq"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7CkernelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x0a,    1 /* Public */,
       3,    0,  117,    2, 0x0a,    2 /* Public */,
       4,    0,  118,    2, 0x0a,    3 /* Public */,
       5,    2,  119,    2, 0x0a,    4 /* Public */,
       8,    3,  124,    2, 0x0a,    7 /* Public */,
      10,    0,  131,    2, 0x0a,   11 /* Public */,
      11,    0,  132,    2, 0x0a,   12 /* Public */,
      12,    0,  133,    2, 0x0a,   13 /* Public */,
      13,    1,  134,    2, 0x0a,   14 /* Public */,
      15,    3,  137,    2, 0x0a,   16 /* Public */,
      20,    3,  144,    2, 0x0a,   20 /* Public */,
      21,    3,  151,    2, 0x0a,   24 /* Public */,
      22,    3,  158,    2, 0x0a,   28 /* Public */,
      23,    3,  165,    2, 0x0a,   32 /* Public */,
      24,    3,  172,    2, 0x0a,   36 /* Public */,
      25,    3,  179,    2, 0x0a,   40 /* Public */,
      26,    3,  186,    2, 0x0a,   44 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 17, QMetaType::Int,   16,   18,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject Ckernel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN7CkernelE.offsetsAndSizes,
    qt_meta_data_ZN7CkernelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN7CkernelE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Ckernel, std::true_type>,
        // method 'setNetPackMap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initConfig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_destroy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_loginCommit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_registerCommit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_createRoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_joinRoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_quitRoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_audioFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'slot_dealData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealLoginRs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealRegisterRs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealCreateRoomRs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealJoinRoomRs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealRoomMemberRq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealLeaveRoomRq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealAudioFrameRq'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Ckernel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Ckernel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setNetPackMap(); break;
        case 1: _t->initConfig(); break;
        case 2: _t->slot_destroy(); break;
        case 3: _t->slot_loginCommit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->slot_registerCommit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->slot_createRoom(); break;
        case 6: _t->slot_joinRoom(); break;
        case 7: _t->slot_quitRoom(); break;
        case 8: _t->slot_audioFrame((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 9: _t->slot_dealData((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->slot_dealLoginRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 11: _t->slot_dealRegisterRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 12: _t->slot_dealCreateRoomRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 13: _t->slot_dealJoinRoomRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->slot_dealRoomMemberRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->slot_dealLeaveRoomRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 16: _t->slot_dealAudioFrameRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *Ckernel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ckernel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN7CkernelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Ckernel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
