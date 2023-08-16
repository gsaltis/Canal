/****************************************************************************
** Meta object code from reading C++ file 'JSONFileWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../JSONFileWindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JSONFileWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JSONFileWindow_t {
    const uint offsetsAndSize[12];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_JSONFileWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_JSONFileWindow_t qt_meta_stringdata_JSONFileWindow = {
    {
QT_MOC_LITERAL(0, 14), // "JSONFileWindow"
QT_MOC_LITERAL(15, 24), // "SignalFileObjectSelected"
QT_MOC_LITERAL(40, 0), // ""
QT_MOC_LITERAL(41, 12), // "QJsonObject*"
QT_MOC_LITERAL(54, 8), // "InObject"
QT_MOC_LITERAL(63, 22) // "SlotFileObjectSelected"

    },
    "JSONFileWindow\0SignalFileObjectSelected\0"
    "\0QJsonObject*\0InObject\0SlotFileObjectSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JSONFileWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   29,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void JSONFileWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JSONFileWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject*>>(_a[1]))); break;
        case 1: _t->SlotFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JSONFileWindow::*)(QJsonObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JSONFileWindow::SignalFileObjectSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject JSONFileWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_JSONFileWindow.offsetsAndSize,
    qt_meta_data_JSONFileWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_JSONFileWindow_t
, QtPrivate::TypeAndForceComplete<JSONFileWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject *, std::false_type>


>,
    nullptr
} };


const QMetaObject *JSONFileWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JSONFileWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JSONFileWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int JSONFileWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void JSONFileWindow::SignalFileObjectSelected(QJsonObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
