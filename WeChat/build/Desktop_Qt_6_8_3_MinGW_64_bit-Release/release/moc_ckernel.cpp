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
    "SIG_SendVideo",
    "",
    "char*",
    "buf",
    "nlen",
    "img",
    "setNetPackMap",
    "initConfig",
    "slot_destroy",
    "slot_startVideo",
    "slot_pauseVideo",
    "slot_startScreen",
    "slot_pauseScreen",
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
    "slot_sendVideoFrame",
    "slot_SendVideo_thread",
    "slot_dealData",
    "sock",
    "slot_dealLoginRs",
    "slot_dealRegisterRs",
    "slot_dealCreateRoomRs",
    "slot_dealJoinRoomRs",
    "slot_dealRoomMemberRq",
    "slot_dealLeaveRoomRq",
    "slot_dealAudioFrameRq",
    "slot_dealVideoFrameRq"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN7CkernelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  176,    2, 0x06,    1 /* Public */,
       1,    1,  181,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  184,    2, 0x0a,    6 /* Public */,
       8,    0,  185,    2, 0x0a,    7 /* Public */,
       9,    0,  186,    2, 0x0a,    8 /* Public */,
      10,    0,  187,    2, 0x0a,    9 /* Public */,
      11,    0,  188,    2, 0x0a,   10 /* Public */,
      12,    0,  189,    2, 0x0a,   11 /* Public */,
      13,    0,  190,    2, 0x0a,   12 /* Public */,
      14,    2,  191,    2, 0x0a,   13 /* Public */,
      17,    3,  196,    2, 0x0a,   16 /* Public */,
      19,    0,  203,    2, 0x0a,   20 /* Public */,
      20,    0,  204,    2, 0x0a,   21 /* Public */,
      21,    0,  205,    2, 0x0a,   22 /* Public */,
      22,    1,  206,    2, 0x0a,   23 /* Public */,
      24,    1,  209,    2, 0x0a,   25 /* Public */,
      25,    2,  212,    2, 0x0a,   27 /* Public */,
      25,    1,  217,    2, 0x0a,   30 /* Public */,
      26,    3,  220,    2, 0x0a,   32 /* Public */,
      28,    3,  227,    2, 0x0a,   36 /* Public */,
      29,    3,  234,    2, 0x0a,   40 /* Public */,
      30,    3,  241,    2, 0x0a,   44 /* Public */,
      31,    3,  248,    2, 0x0a,   48 /* Public */,
      32,    3,  255,    2, 0x0a,   52 /* Public */,
      33,    3,  262,    2, 0x0a,   56 /* Public */,
      34,    3,  269,    2, 0x0a,   60 /* Public */,
      35,    3,  276,    2, 0x0a,   64 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QImage,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   15,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   23,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QImage,    6,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, QMetaType::Int,   27,    4,    5,

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
        // method 'SIG_SendVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SIG_SendVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'setNetPackMap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initConfig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_destroy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_startVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_pauseVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_startScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_pauseScreen'
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
        // method 'slot_sendVideoFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'slot_SendVideo_thread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_SendVideo_thread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_dealVideoFrameRq'
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
        case 0: _t->SIG_SendVideo((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->SIG_SendVideo((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 2: _t->setNetPackMap(); break;
        case 3: _t->initConfig(); break;
        case 4: _t->slot_destroy(); break;
        case 5: _t->slot_startVideo(); break;
        case 6: _t->slot_pauseVideo(); break;
        case 7: _t->slot_startScreen(); break;
        case 8: _t->slot_pauseScreen(); break;
        case 9: _t->slot_loginCommit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->slot_registerCommit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 11: _t->slot_createRoom(); break;
        case 12: _t->slot_joinRoom(); break;
        case 13: _t->slot_quitRoom(); break;
        case 14: _t->slot_audioFrame((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 15: _t->slot_sendVideoFrame((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 16: _t->slot_SendVideo_thread((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 17: _t->slot_SendVideo_thread((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 18: _t->slot_dealData((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 19: _t->slot_dealLoginRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 20: _t->slot_dealRegisterRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 21: _t->slot_dealCreateRoomRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 22: _t->slot_dealJoinRoomRs((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 23: _t->slot_dealRoomMemberRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 24: _t->slot_dealLeaveRoomRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 25: _t->slot_dealAudioFrameRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 26: _t->slot_dealVideoFrameRq((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Ckernel::*)(char * , int );
            if (_q_method_type _q_method = &Ckernel::SIG_SendVideo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Ckernel::*)(QImage );
            if (_q_method_type _q_method = &Ckernel::SIG_SendVideo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
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
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Ckernel::SIG_SendVideo(char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Ckernel::SIG_SendVideo(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {
struct qt_meta_tag_ZN15SendVideoWorkerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN15SendVideoWorkerE = QtMocHelpers::stringData(
    "SendVideoWorker",
    "slot_sendVideo",
    "",
    "char*",
    "buf",
    "nlen",
    "img"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN15SendVideoWorkerE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x0a,    1 /* Public */,
       1,    1,   31,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QImage,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject SendVideoWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<ThreadWorker::staticMetaObject>(),
    qt_meta_stringdata_ZN15SendVideoWorkerE.offsetsAndSizes,
    qt_meta_data_ZN15SendVideoWorkerE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN15SendVideoWorkerE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SendVideoWorker, std::true_type>,
        // method 'slot_sendVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_sendVideo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>
    >,
    nullptr
} };

void SendVideoWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SendVideoWorker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->slot_sendVideo((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->slot_sendVideo((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *SendVideoWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SendVideoWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN15SendVideoWorkerE.stringdata0))
        return static_cast<void*>(this);
    return ThreadWorker::qt_metacast(_clname);
}

int SendVideoWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ThreadWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
