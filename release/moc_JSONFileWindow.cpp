/****************************************************************************
** Meta object code from reading C++ file 'JSONFileWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../JSONFileWindow.h"
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
#error "The header file 'JSONFileWindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSJSONFileWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSJSONFileWindowENDCLASS = QtMocHelpers::stringData(
    "JSONFileWindow",
    "SignalFileObjectSelected",
    "",
    "InObject",
    "SignalSizeValueChanged",
    "InSize",
    "SignalCallingFunctionFound",
    "InFunctionName",
    "SignalClearChildren",
    "SignalFileObjectClicked",
    "SlotFileObjectSelected",
    "SlotSizeValueChanged",
    "SlotLocalCountSet",
    "InLocalCount",
    "SlotCallingFunctionFound",
    "SlotClearChildren",
    "SlotFileObjectClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSJSONFileWindowENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[15];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[23];
    char stringdata5[7];
    char stringdata6[27];
    char stringdata7[15];
    char stringdata8[20];
    char stringdata9[24];
    char stringdata10[23];
    char stringdata11[21];
    char stringdata12[18];
    char stringdata13[13];
    char stringdata14[25];
    char stringdata15[18];
    char stringdata16[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSJSONFileWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSJSONFileWindowENDCLASS_t qt_meta_stringdata_CLASSJSONFileWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "JSONFileWindow"
        QT_MOC_LITERAL(15, 24),  // "SignalFileObjectSelected"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 8),  // "InObject"
        QT_MOC_LITERAL(50, 22),  // "SignalSizeValueChanged"
        QT_MOC_LITERAL(73, 6),  // "InSize"
        QT_MOC_LITERAL(80, 26),  // "SignalCallingFunctionFound"
        QT_MOC_LITERAL(107, 14),  // "InFunctionName"
        QT_MOC_LITERAL(122, 19),  // "SignalClearChildren"
        QT_MOC_LITERAL(142, 23),  // "SignalFileObjectClicked"
        QT_MOC_LITERAL(166, 22),  // "SlotFileObjectSelected"
        QT_MOC_LITERAL(189, 20),  // "SlotSizeValueChanged"
        QT_MOC_LITERAL(210, 17),  // "SlotLocalCountSet"
        QT_MOC_LITERAL(228, 12),  // "InLocalCount"
        QT_MOC_LITERAL(241, 24),  // "SlotCallingFunctionFound"
        QT_MOC_LITERAL(266, 17),  // "SlotClearChildren"
        QT_MOC_LITERAL(284, 21)   // "SlotFileObjectClicked"
    },
    "JSONFileWindow",
    "SignalFileObjectSelected",
    "",
    "InObject",
    "SignalSizeValueChanged",
    "InSize",
    "SignalCallingFunctionFound",
    "InFunctionName",
    "SignalClearChildren",
    "SignalFileObjectClicked",
    "SlotFileObjectSelected",
    "SlotSizeValueChanged",
    "SlotLocalCountSet",
    "InLocalCount",
    "SlotCallingFunctionFound",
    "SlotClearChildren",
    "SlotFileObjectClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSJSONFileWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    1,   83,    2, 0x06,    3 /* Public */,
       6,    1,   86,    2, 0x06,    5 /* Public */,
       8,    0,   89,    2, 0x06,    7 /* Public */,
       9,    0,   90,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   91,    2, 0x0a,    9 /* Public */,
      11,    1,   94,    2, 0x0a,   11 /* Public */,
      12,    1,   97,    2, 0x0a,   13 /* Public */,
      14,    1,  100,    2, 0x0a,   15 /* Public */,
      15,    0,  103,    2, 0x0a,   17 /* Public */,
      16,    0,  104,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject JSONFileWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSJSONFileWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSJSONFileWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSJSONFileWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<JSONFileWindow, std::true_type>,
        // method 'SignalFileObjectSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'SignalSizeValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SignalCallingFunctionFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SignalClearChildren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SignalFileObjectClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotFileObjectSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'SlotSizeValueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SlotLocalCountSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SlotCallingFunctionFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'SlotClearChildren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SlotFileObjectClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void JSONFileWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JSONFileWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignalFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->SignalSizeValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->SignalCallingFunctionFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->SignalClearChildren(); break;
        case 4: _t->SignalFileObjectClicked(); break;
        case 5: _t->SlotFileObjectSelected((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 6: _t->SlotSizeValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->SlotLocalCountSet((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->SlotCallingFunctionFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->SlotClearChildren(); break;
        case 10: _t->SlotFileObjectClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JSONFileWindow::*)(QJsonObject );
            if (_t _q_method = &JSONFileWindow::SignalFileObjectSelected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JSONFileWindow::*)(int );
            if (_t _q_method = &JSONFileWindow::SignalSizeValueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JSONFileWindow::*)(QString );
            if (_t _q_method = &JSONFileWindow::SignalCallingFunctionFound; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JSONFileWindow::*)();
            if (_t _q_method = &JSONFileWindow::SignalClearChildren; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JSONFileWindow::*)();
            if (_t _q_method = &JSONFileWindow::SignalFileObjectClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *JSONFileWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JSONFileWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSJSONFileWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int JSONFileWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void JSONFileWindow::SignalFileObjectSelected(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JSONFileWindow::SignalSizeValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JSONFileWindow::SignalCallingFunctionFound(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JSONFileWindow::SignalClearChildren()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void JSONFileWindow::SignalFileObjectClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
