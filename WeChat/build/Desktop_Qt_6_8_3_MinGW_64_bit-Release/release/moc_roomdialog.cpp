/****************************************************************************
** Meta object code from reading C++ file 'roomdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../roomdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomdialog.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10RoomDialogE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10RoomDialogE = QtMocHelpers::stringData(
    "RoomDialog",
    "SIG_close",
    "",
    "SIG_audioFrame",
    "ba",
    "SIG_videoStart",
    "SIG_videoPause",
    "SIG_screenStart",
    "SIG_screenPause",
    "SIG_setMoji",
    "newMoji",
    "slot_setInfo",
    "roomid",
    "slot_addUserShow",
    "UserShowWidget*",
    "user",
    "slot_removeUserShow",
    "id",
    "slot_clearUserShow",
    "slot_audioFrame",
    "slot_refreshUserShow",
    "QImage&",
    "img",
    "slot_setMainUsershow",
    "name",
    "on_pb_close_clicked",
    "on_pb_quit_clicked",
    "closeEvent",
    "QCloseEvent*",
    "event",
    "on_cb_audio_checkStateChanged",
    "Qt::CheckState",
    "arg1",
    "on_cb_video_checkStateChanged",
    "on_cb_desk_checkStateChanged",
    "on_pb_max_clicked",
    "on_pb_min_clicked",
    "on_cbb_special_currentIndexChanged",
    "index"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10RoomDialogE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  158,    2, 0x06,    1 /* Public */,
       3,    1,  159,    2, 0x06,    2 /* Public */,
       5,    0,  162,    2, 0x06,    4 /* Public */,
       6,    0,  163,    2, 0x06,    5 /* Public */,
       7,    0,  164,    2, 0x06,    6 /* Public */,
       8,    0,  165,    2, 0x06,    7 /* Public */,
       9,    1,  166,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,  169,    2, 0x0a,   10 /* Public */,
      13,    1,  172,    2, 0x0a,   12 /* Public */,
      16,    1,  175,    2, 0x0a,   14 /* Public */,
      16,    1,  178,    2, 0x0a,   16 /* Public */,
      18,    0,  181,    2, 0x0a,   18 /* Public */,
      19,    1,  182,    2, 0x0a,   19 /* Public */,
      20,    2,  185,    2, 0x0a,   21 /* Public */,
      23,    2,  190,    2, 0x0a,   24 /* Public */,
      25,    0,  195,    2, 0x08,   27 /* Private */,
      26,    0,  196,    2, 0x08,   28 /* Private */,
      27,    1,  197,    2, 0x08,   29 /* Private */,
      30,    1,  200,    2, 0x08,   31 /* Private */,
      33,    1,  203,    2, 0x08,   33 /* Private */,
      34,    1,  206,    2, 0x08,   35 /* Private */,
      35,    0,  209,    2, 0x08,   37 /* Private */,
      36,    0,  210,    2, 0x08,   38 /* Private */,
      37,    1,  211,    2, 0x08,   39 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 21,   17,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   17,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,

       0        // eod
};

Q_CONSTINIT const QMetaObject RoomDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN10RoomDialogE.offsetsAndSizes,
    qt_meta_data_ZN10RoomDialogE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10RoomDialogE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RoomDialog, std::true_type>,
        // method 'SIG_close'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SIG_audioFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'SIG_videoStart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SIG_videoPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SIG_screenStart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SIG_screenPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SIG_setMoji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_setInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_addUserShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<UserShowWidget *, std::false_type>,
        // method 'slot_removeUserShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<UserShowWidget *, std::false_type>,
        // method 'slot_removeUserShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_clearUserShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_audioFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'slot_refreshUserShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage &, std::false_type>,
        // method 'slot_setMainUsershow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pb_close_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_quit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>,
        // method 'on_cb_audio_checkStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Qt::CheckState &, std::false_type>,
        // method 'on_cb_video_checkStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Qt::CheckState &, std::false_type>,
        // method 'on_cb_desk_checkStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Qt::CheckState &, std::false_type>,
        // method 'on_pb_max_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_min_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cbb_special_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void RoomDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RoomDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->SIG_close(); break;
        case 1: _t->SIG_audioFrame((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->SIG_videoStart(); break;
        case 3: _t->SIG_videoPause(); break;
        case 4: _t->SIG_screenStart(); break;
        case 5: _t->SIG_screenPause(); break;
        case 6: _t->SIG_setMoji((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->slot_setInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->slot_addUserShow((*reinterpret_cast< std::add_pointer_t<UserShowWidget*>>(_a[1]))); break;
        case 9: _t->slot_removeUserShow((*reinterpret_cast< std::add_pointer_t<UserShowWidget*>>(_a[1]))); break;
        case 10: _t->slot_removeUserShow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->slot_clearUserShow(); break;
        case 12: _t->slot_audioFrame((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 13: _t->slot_refreshUserShow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QImage&>>(_a[2]))); break;
        case 14: _t->slot_setMainUsershow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->on_pb_close_clicked(); break;
        case 16: _t->on_pb_quit_clicked(); break;
        case 17: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 18: _t->on_cb_audio_checkStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::CheckState>>(_a[1]))); break;
        case 19: _t->on_cb_video_checkStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::CheckState>>(_a[1]))); break;
        case 20: _t->on_cb_desk_checkStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::CheckState>>(_a[1]))); break;
        case 21: _t->on_pb_max_clicked(); break;
        case 22: _t->on_pb_min_clicked(); break;
        case 23: _t->on_cbb_special_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< UserShowWidget* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< UserShowWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (RoomDialog::*)();
            if (_q_method_type _q_method = &RoomDialog::SIG_close; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (RoomDialog::*)(QByteArray );
            if (_q_method_type _q_method = &RoomDialog::SIG_audioFrame; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (RoomDialog::*)();
            if (_q_method_type _q_method = &RoomDialog::SIG_videoStart; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (RoomDialog::*)();
            if (_q_method_type _q_method = &RoomDialog::SIG_videoPause; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (RoomDialog::*)();
            if (_q_method_type _q_method = &RoomDialog::SIG_screenStart; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (RoomDialog::*)();
            if (_q_method_type _q_method = &RoomDialog::SIG_screenPause; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (RoomDialog::*)(int );
            if (_q_method_type _q_method = &RoomDialog::SIG_setMoji; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *RoomDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10RoomDialogE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RoomDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void RoomDialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RoomDialog::SIG_audioFrame(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RoomDialog::SIG_videoStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RoomDialog::SIG_videoPause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void RoomDialog::SIG_screenStart()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void RoomDialog::SIG_screenPause()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void RoomDialog::SIG_setMoji(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
