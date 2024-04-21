/****************************************************************************
** Meta object code from reading C++ file 'charrecogdlg.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QVision/dialog/charrecogdlg.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'charrecogdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSCharRecogDlgENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCharRecogDlgENDCLASS = QtMocHelpers::stringData(
    "CharRecogDlg",
    "Clean",
    "",
    "MakeBig",
    "SaveText",
    "ShutDown",
    "Recognize",
    "getPicture"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCharRecogDlgENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[13];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[10];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCharRecogDlgENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCharRecogDlgENDCLASS_t qt_meta_stringdata_CLASSCharRecogDlgENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "CharRecogDlg"
        QT_MOC_LITERAL(13, 5),  // "Clean"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 7),  // "MakeBig"
        QT_MOC_LITERAL(28, 8),  // "SaveText"
        QT_MOC_LITERAL(37, 8),  // "ShutDown"
        QT_MOC_LITERAL(46, 9),  // "Recognize"
        QT_MOC_LITERAL(56, 10)   // "getPicture"
    },
    "CharRecogDlg",
    "Clean",
    "",
    "MakeBig",
    "SaveText",
    "ShutDown",
    "Recognize",
    "getPicture"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCharRecogDlgENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CharRecogDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSCharRecogDlgENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCharRecogDlgENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCharRecogDlgENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CharRecogDlg, std::true_type>,
        // method 'Clean'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MakeBig'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SaveText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ShutDown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Recognize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getPicture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CharRecogDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CharRecogDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Clean(); break;
        case 1: _t->MakeBig(); break;
        case 2: _t->SaveText(); break;
        case 3: _t->ShutDown(); break;
        case 4: _t->Recognize(); break;
        case 5: _t->getPicture(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CharRecogDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CharRecogDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCharRecogDlgENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CharRecogDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
