/****************************************************************************
** Meta object code from reading C++ file 'spreadsheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "spreadsheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spreadsheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spreadSheet_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spreadSheet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spreadSheet_t qt_meta_stringdata_spreadSheet = {
    {
QT_MOC_LITERAL(0, 0, 11), // "spreadSheet"
QT_MOC_LITERAL(1, 12, 16), // "slot_setShowGrid"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "flag"
QT_MOC_LITERAL(4, 35, 8), // "slot_cut"
QT_MOC_LITERAL(5, 44, 9), // "slot_copy"
QT_MOC_LITERAL(6, 54, 10), // "slot_paste"
QT_MOC_LITERAL(7, 65, 11), // "slot_delete"
QT_MOC_LITERAL(8, 77, 14), // "slot_selectRow"
QT_MOC_LITERAL(9, 92, 17), // "slot_selectColumn"
QT_MOC_LITERAL(10, 110, 16), // "slot_recalculate"
QT_MOC_LITERAL(11, 127, 9), // "slot_sort"
QT_MOC_LITERAL(12, 137, 23) // "slot_setAutoRecalculate"

    },
    "spreadSheet\0slot_setShowGrid\0\0flag\0"
    "slot_cut\0slot_copy\0slot_paste\0slot_delete\0"
    "slot_selectRow\0slot_selectColumn\0"
    "slot_recalculate\0slot_sort\0"
    "slot_setAutoRecalculate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spreadSheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    0,   67,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x0a /* Public */,
       6,    0,   69,    2, 0x0a /* Public */,
       7,    0,   70,    2, 0x0a /* Public */,
       8,    0,   71,    2, 0x0a /* Public */,
       9,    0,   72,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void spreadSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spreadSheet *_t = static_cast<spreadSheet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_setShowGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slot_cut(); break;
        case 2: _t->slot_copy(); break;
        case 3: _t->slot_paste(); break;
        case 4: _t->slot_delete(); break;
        case 5: _t->slot_selectRow(); break;
        case 6: _t->slot_selectColumn(); break;
        case 7: _t->slot_recalculate(); break;
        case 8: _t->slot_sort(); break;
        case 9: _t->slot_setAutoRecalculate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject spreadSheet::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_spreadSheet.data,
      qt_meta_data_spreadSheet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spreadSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spreadSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spreadSheet.stringdata0))
        return static_cast<void*>(const_cast< spreadSheet*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int spreadSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
