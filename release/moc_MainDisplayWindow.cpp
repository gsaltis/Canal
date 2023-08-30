/****************************************************************************
** Meta object code from reading C++ file 'MainDisplayWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainDisplayWindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainDisplayWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS = QtMocHelpers::stringData(
    "MainDisplayWindow",
    "SignalClearChildren",
    "",
    "SignalSetMessageNormal",
    "InMessage",
    "SlotSelectWindow",
    "InWindowIndex",
    "SlotClearChildren",
    "SlotSetMessageNormal"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[18];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[10];
    char stringdata5[17];
    char stringdata6[14];
    char stringdata7[18];
    char stringdata8[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "MainDisplayWindow"
        QT_MOC_LITERAL(18, 19),  // "SignalClearChildren"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 22),  // "SignalSetMessageNormal"
        QT_MOC_LITERAL(62, 9),  // "InMessage"
        QT_MOC_LITERAL(72, 16),  // "SlotSelectWindow"
        QT_MOC_LITERAL(89, 13),  // "InWindowIndex"
        QT_MOC_LITERAL(103, 17),  // "SlotClearChildren"
        QT_MOC_LITERAL(121, 20)   // "SlotSetMessageNormal"
    },
    "MainDisplayWindow",
    "SignalClearChildren",
    "",
    "SignalSetMessageNormal",
    "InMessage",
    "SlotSelectWindow",
    "InWindowIndex",
    "SlotClearChildren",
    "SlotSetMessageNormal"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainDisplayWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    1,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   48,    2, 0x0a,    4 /* Public */,
       7,    0,   51,    2, 0x0a,    6 /* Public */,
       8,    1,   52,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainDisplayWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainDisplayWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainDisplayWindow, std::true_type>,
        // method 'SignalClearChildren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SignalSetMessageNormal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotSelectWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SlotClearChildren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotSetMessageNormal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MainDisplayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDisplayWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalClearChildren(); break;
        case 1: _t->SignalSetMessageNormal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->SlotSelectWindow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->SlotClearChildren(); break;
        case 4: _t->SlotSetMessageNormal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainDisplayWindow::*)();
            if (_t _q_method = &MainDisplayWindow::SignalClearChildren; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(QString );
            if (_t _q_method = &MainDisplayWindow::SignalSetMessageNormal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *MainDisplayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDisplayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainDisplayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MainDisplayWindow::SignalClearChildren()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainDisplayWindow::SignalSetMessageNormal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
