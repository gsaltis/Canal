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
#include <QtCore/QList>

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
    "SignalFormatTypeSelected",
    "",
    "InType",
    "SignalFileObjectSelected",
    "SignalFileElementSelected",
    "InTag",
    "InKeys",
    "SignalObjectFormatSelected",
    "JSONObjectFormat*",
    "InObjectFormat",
    "SignalFileElementIdentified",
    "InSearchTag",
    "SlotFormatTypeSelected",
    "SlotFileObjectSelected",
    "InObject",
    "SlotFileElementSelected",
    "SlotObjectFormatSelected",
    "SlotObjectFormatIdentified"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[18];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[25];
    char stringdata5[26];
    char stringdata6[6];
    char stringdata7[7];
    char stringdata8[27];
    char stringdata9[18];
    char stringdata10[15];
    char stringdata11[28];
    char stringdata12[12];
    char stringdata13[23];
    char stringdata14[23];
    char stringdata15[9];
    char stringdata16[24];
    char stringdata17[25];
    char stringdata18[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS_t qt_meta_stringdata_CLASSMainDisplayWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "MainDisplayWindow"
        QT_MOC_LITERAL(18, 24),  // "SignalFormatTypeSelected"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 6),  // "InType"
        QT_MOC_LITERAL(51, 24),  // "SignalFileObjectSelected"
        QT_MOC_LITERAL(76, 25),  // "SignalFileElementSelected"
        QT_MOC_LITERAL(102, 5),  // "InTag"
        QT_MOC_LITERAL(108, 6),  // "InKeys"
        QT_MOC_LITERAL(115, 26),  // "SignalObjectFormatSelected"
        QT_MOC_LITERAL(142, 17),  // "JSONObjectFormat*"
        QT_MOC_LITERAL(160, 14),  // "InObjectFormat"
        QT_MOC_LITERAL(175, 27),  // "SignalFileElementIdentified"
        QT_MOC_LITERAL(203, 11),  // "InSearchTag"
        QT_MOC_LITERAL(215, 22),  // "SlotFormatTypeSelected"
        QT_MOC_LITERAL(238, 22),  // "SlotFileObjectSelected"
        QT_MOC_LITERAL(261, 8),  // "InObject"
        QT_MOC_LITERAL(270, 23),  // "SlotFileElementSelected"
        QT_MOC_LITERAL(294, 24),  // "SlotObjectFormatSelected"
        QT_MOC_LITERAL(319, 26)   // "SlotObjectFormatIdentified"
    },
    "MainDisplayWindow",
    "SignalFormatTypeSelected",
    "",
    "InType",
    "SignalFileObjectSelected",
    "SignalFileElementSelected",
    "InTag",
    "InKeys",
    "SignalObjectFormatSelected",
    "JSONObjectFormat*",
    "InObjectFormat",
    "SignalFileElementIdentified",
    "InSearchTag",
    "SlotFormatTypeSelected",
    "SlotFileObjectSelected",
    "InObject",
    "SlotFileElementSelected",
    "SlotObjectFormatSelected",
    "SlotObjectFormatIdentified"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainDisplayWindowENDCLASS[] = {

 // content:
      11,       // revision
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
       4,    1,   77,    2, 0x06,    3 /* Public */,
       5,    2,   80,    2, 0x06,    5 /* Public */,
       8,    1,   85,    2, 0x06,    8 /* Public */,
      11,    2,   88,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,   93,    2, 0x0a,   13 /* Public */,
      14,    1,   96,    2, 0x0a,   15 /* Public */,
      16,    2,   99,    2, 0x0a,   17 /* Public */,
      17,    1,  104,    2, 0x0a,   20 /* Public */,
      18,    2,  107,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QJsonObject,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   12,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QJsonObject,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    6,    7,

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
        // method 'SignalFormatTypeSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SignalFileObjectSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'SignalFileElementSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>,
        // method 'SignalObjectFormatSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<JSONObjectFormat *, std::false_type>,
        // method 'SignalFileElementIdentified'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'SlotFormatTypeSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotFileObjectSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'SlotFileElementSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>,
        // method 'SlotObjectFormatSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<JSONObjectFormat *, std::false_type>,
        // method 'SlotObjectFormatIdentified'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>
    >,
    nullptr
} };

void MainDisplayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainDisplayWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalFormatTypeSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->SignalFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 2: _t->SignalFileElementSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        case 3: _t->SignalObjectFormatSelected((*reinterpret_cast< std::add_pointer_t<JSONObjectFormat*>>(_a[1]))); break;
        case 4: _t->SignalFileElementIdentified((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 5: _t->SlotFormatTypeSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->SlotFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 7: _t->SlotFileElementSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        case 8: _t->SlotObjectFormatSelected((*reinterpret_cast< std::add_pointer_t<JSONObjectFormat*>>(_a[1]))); break;
        case 9: _t->SlotObjectFormatIdentified((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< JSONObjectFormat* >(); break;
            }
            break;
        case 8:
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
            using _t = void (MainDisplayWindow::*)(QString );
            if (_t _q_method = &MainDisplayWindow::SignalFormatTypeSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(QJsonObject );
            if (_t _q_method = &MainDisplayWindow::SignalFileObjectSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(QString , QList<QString> );
            if (_t _q_method = &MainDisplayWindow::SignalFileElementSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(JSONObjectFormat * );
            if (_t _q_method = &MainDisplayWindow::SignalObjectFormatSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainDisplayWindow::*)(QString , QStringList );
            if (_t _q_method = &MainDisplayWindow::SignalFileElementIdentified; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
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

// SIGNAL 3
void MainDisplayWindow::SignalObjectFormatSelected(JSONObjectFormat * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainDisplayWindow::SignalFileElementIdentified(QString _t1, QStringList _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
