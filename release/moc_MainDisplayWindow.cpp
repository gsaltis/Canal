/****************************************************************************
** Meta object code from reading C++ file 'MainDisplayWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MainDisplayWindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainDisplayWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainDisplayWindow_t {
    const uint offsetsAndSize[24];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainDisplayWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainDisplayWindow_t qt_meta_stringdata_MainDisplayWindow = {
    {
QT_MOC_LITERAL(0, 17), // "MainDisplayWindow"
QT_MOC_LITERAL(18, 24), // "SignalFormatTypeSelected"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 6), // "InType"
QT_MOC_LITERAL(51, 24), // "SignalFileObjectSelected"
QT_MOC_LITERAL(76, 25), // "SignalFileElementSelected"
QT_MOC_LITERAL(102, 5), // "InTag"
QT_MOC_LITERAL(108, 6), // "InKeys"
QT_MOC_LITERAL(115, 22), // "SlotFormatTypeSelected"
QT_MOC_LITERAL(138, 22), // "SlotFileObjectSelected"
QT_MOC_LITERAL(161, 8), // "InObject"
QT_MOC_LITERAL(170, 23) // "SlotFileElementSelected"

    },
    "MainDisplayWindow\0SignalFormatTypeSelected\0"
    "\0InType\0SignalFileObjectSelected\0"
    "SignalFileElementSelected\0InTag\0InKeys\0"
    "SlotFormatTypeSelected\0SlotFileObjectSelected\0"
    "InObject\0SlotFileElementSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDisplayWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    1,   53,    2, 0x06,    3 /* Public */,
       5,    2,   56,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   61,    2, 0x0a,    8 /* Public */,
       9,    1,   64,    2, 0x0a,   10 /* Public */,
      11,    2,   67,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QJsonObject,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    6,    7,

       0        // eod
};

void MainDisplayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDisplayWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalFormatTypeSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->SignalFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 2: _t->SignalFileElementSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        case 3: _t->SlotFormatTypeSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->SlotFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 5: _t->SlotFileElementSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainDisplayWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDisplayWindow::SignalFormatTypeSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDisplayWindow::SignalFileObjectSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(QString , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainDisplayWindow::SignalFileElementSelected)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainDisplayWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainDisplayWindow.offsetsAndSize,
    qt_meta_data_MainDisplayWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainDisplayWindow_t
, QtPrivate::TypeAndForceComplete<MainDisplayWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainDisplayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDisplayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainDisplayWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainDisplayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MainDisplayWindow::SignalFormatTypeSelected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainDisplayWindow::SignalFileObjectSelected(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainDisplayWindow::SignalFileElementSelected(QString _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
