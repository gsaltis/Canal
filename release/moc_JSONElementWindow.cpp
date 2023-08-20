/****************************************************************************
** Meta object code from reading C++ file 'JSONElementWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../JSONElementWindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JSONElementWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JSONElementWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[346];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_JSONElementWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_JSONElementWindow_t qt_meta_stringdata_JSONElementWindow = {
    {
QT_MOC_LITERAL(0, 17), // "JSONElementWindow"
QT_MOC_LITERAL(18, 24), // "SignalTypeFormatSelected"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 6), // "InType"
QT_MOC_LITERAL(51, 25), // "SignalFileElementSelected"
QT_MOC_LITERAL(77, 5), // "InTag"
QT_MOC_LITERAL(83, 6), // "InKeys"
QT_MOC_LITERAL(90, 26), // "SignalObjectFormatSelected"
QT_MOC_LITERAL(117, 17), // "JSONObjectFormat*"
QT_MOC_LITERAL(135, 14), // "InObjectFormat"
QT_MOC_LITERAL(150, 27), // "SignalFileElementIdentified"
QT_MOC_LITERAL(178, 11), // "InSearchTag"
QT_MOC_LITERAL(190, 24), // "SignalFileObjectSelected"
QT_MOC_LITERAL(215, 8), // "InObject"
QT_MOC_LITERAL(224, 22), // "SlotTypeFormatSelected"
QT_MOC_LITERAL(247, 23), // "SlotFileElementSelected"
QT_MOC_LITERAL(271, 24), // "SlotObjectFormatSelected"
QT_MOC_LITERAL(296, 26), // "SlotObjectFormatIdentified"
QT_MOC_LITERAL(323, 22) // "SlotFileObjectSelected"

    },
    "JSONElementWindow\0SignalTypeFormatSelected\0"
    "\0InType\0SignalFileElementSelected\0"
    "InTag\0InKeys\0SignalObjectFormatSelected\0"
    "JSONObjectFormat*\0InObjectFormat\0"
    "SignalFileElementIdentified\0InSearchTag\0"
    "SignalFileObjectSelected\0InObject\0"
    "SlotTypeFormatSelected\0SlotFileElementSelected\0"
    "SlotObjectFormatSelected\0"
    "SlotObjectFormatIdentified\0"
    "SlotFileObjectSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JSONElementWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    2,   77,    2, 0x06,    3 /* Public */,
       7,    1,   82,    2, 0x06,    6 /* Public */,
      10,    2,   85,    2, 0x06,    8 /* Public */,
      12,    1,   90,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,   93,    2, 0x0a,   13 /* Public */,
      15,    2,   96,    2, 0x0a,   15 /* Public */,
      16,    1,  101,    2, 0x0a,   18 /* Public */,
      17,    2,  104,    2, 0x0a,   20 /* Public */,
      18,    1,  109,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   11,    6,
    QMetaType::Void, QMetaType::QJsonObject,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    5,    6,
    QMetaType::Void, QMetaType::QJsonObject,   13,

       0        // eod
};

void JSONElementWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JSONElementWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalTypeFormatSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->SignalFileElementSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        case 2: _t->SignalObjectFormatSelected((*reinterpret_cast< std::add_pointer_t<JSONObjectFormat*>>(_a[1]))); break;
        case 3: _t->SignalFileElementIdentified((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 4: _t->SignalFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 5: _t->SlotTypeFormatSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->SlotFileElementSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        case 7: _t->SlotObjectFormatSelected((*reinterpret_cast< std::add_pointer_t<JSONObjectFormat*>>(_a[1]))); break;
        case 8: _t->SlotObjectFormatIdentified((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 9: _t->SlotFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< JSONObjectFormat* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< JSONObjectFormat* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JSONElementWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JSONElementWindow::SignalTypeFormatSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JSONElementWindow::*)(QString , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JSONElementWindow::SignalFileElementSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JSONElementWindow::*)(JSONObjectFormat * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JSONElementWindow::SignalObjectFormatSelected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JSONElementWindow::*)(QString , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JSONElementWindow::SignalFileElementIdentified)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JSONElementWindow::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JSONElementWindow::SignalFileObjectSelected)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject JSONElementWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_JSONElementWindow.offsetsAndSize,
    qt_meta_data_JSONElementWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_JSONElementWindow_t
, QtPrivate::TypeAndForceComplete<JSONElementWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<JSONObjectFormat *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<JSONObjectFormat *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>


>,
    nullptr
} };


const QMetaObject *JSONElementWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JSONElementWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JSONElementWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int JSONElementWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void JSONElementWindow::SignalTypeFormatSelected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JSONElementWindow::SignalFileElementSelected(QString _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JSONElementWindow::SignalObjectFormatSelected(JSONObjectFormat * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JSONElementWindow::SignalFileElementIdentified(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JSONElementWindow::SignalFileObjectSelected(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
