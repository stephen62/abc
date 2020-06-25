/****************************************************************************
** Meta object code from reading C++ file 'MainApplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainApplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainApplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainApplication_t {
    QByteArrayData data[22];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainApplication_t qt_meta_stringdata_MainApplication = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MainApplication"
QT_MOC_LITERAL(1, 16, 14), // "openCT_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "cur_open_ct"
QT_MOC_LITERAL(4, 44, 11), // "std::string"
QT_MOC_LITERAL(5, 56, 8), // "filename"
QT_MOC_LITERAL(6, 65, 16), // "openXRay_clicked"
QT_MOC_LITERAL(7, 82, 7), // "viewDRR"
QT_MOC_LITERAL(8, 90, 8), // "viewXRay"
QT_MOC_LITERAL(9, 99, 9), // "viewImage"
QT_MOC_LITERAL(10, 109, 4), // "flag"
QT_MOC_LITERAL(11, 114, 12), // "chooseReader"
QT_MOC_LITERAL(12, 127, 13), // "changeOpacity"
QT_MOC_LITERAL(13, 141, 13), // "vtkImitateDRR"
QT_MOC_LITERAL(14, 155, 5), // "input"
QT_MOC_LITERAL(15, 161, 10), // "adjustPara"
QT_MOC_LITERAL(16, 172, 10), // "restorPara"
QT_MOC_LITERAL(17, 183, 13), // "changeToOther"
QT_MOC_LITERAL(18, 197, 15), // "runRegistration"
QT_MOC_LITERAL(19, 213, 21), // "outOfFocusConfirm_TRS"
QT_MOC_LITERAL(20, 235, 11), // "compareArea"
QT_MOC_LITERAL(21, 247, 10) // "outputArea"

    },
    "MainApplication\0openCT_clicked\0\0"
    "cur_open_ct\0std::string\0filename\0"
    "openXRay_clicked\0viewDRR\0viewXRay\0"
    "viewImage\0flag\0chooseReader\0changeOpacity\0"
    "vtkImitateDRR\0input\0adjustPara\0"
    "restorPara\0changeToOther\0runRegistration\0"
    "outOfFocusConfirm_TRS\0compareArea\0"
    "outputArea"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainApplication[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    1,   95,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    1,  101,    2, 0x0a /* Public */,
      11,    0,  104,    2, 0x0a /* Public */,
      12,    0,  105,    2, 0x0a /* Public */,
      13,    1,  106,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    0,  111,    2, 0x0a /* Public */,
      18,    0,  112,    2, 0x0a /* Public */,
      19,    0,  113,    2, 0x0a /* Public */,
      20,    0,  114,    2, 0x0a /* Public */,
      21,    0,  115,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainApplication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openCT_clicked(); break;
        case 1: _t->cur_open_ct((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->openXRay_clicked(); break;
        case 3: _t->viewDRR(); break;
        case 4: _t->viewXRay(); break;
        case 5: _t->viewImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->chooseReader(); break;
        case 7: _t->changeOpacity(); break;
        case 8: _t->vtkImitateDRR((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->adjustPara(); break;
        case 10: _t->restorPara(); break;
        case 11: _t->changeToOther(); break;
        case 12: _t->runRegistration(); break;
        case 13: _t->outOfFocusConfirm_TRS(); break;
        case 14: _t->compareArea(); break;
        case 15: _t->outputArea(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainApplication::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainApplication.data,
    qt_meta_data_MainApplication,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainApplication.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
