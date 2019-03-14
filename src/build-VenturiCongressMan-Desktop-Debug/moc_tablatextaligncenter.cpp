/****************************************************************************
** Meta object code from reading C++ file 'tablatextaligncenter.h'
**
** Created: Wed Jun 12 10:19:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VenturiCongressMan/tablatextaligncenter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tablatextaligncenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TablaTextAlignCenter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   31,   22,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TablaTextAlignCenter[] = {
    "TablaTextAlignCenter\0\0QVariant\0,\0"
    "data(QModelIndex,int)\0"
};

void TablaTextAlignCenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TablaTextAlignCenter *_t = static_cast<TablaTextAlignCenter *>(_o);
        switch (_id) {
        case 0: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TablaTextAlignCenter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TablaTextAlignCenter::staticMetaObject = {
    { &QSqlQueryModel::staticMetaObject, qt_meta_stringdata_TablaTextAlignCenter,
      qt_meta_data_TablaTextAlignCenter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TablaTextAlignCenter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TablaTextAlignCenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TablaTextAlignCenter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TablaTextAlignCenter))
        return static_cast<void*>(const_cast< TablaTextAlignCenter*>(this));
    return QSqlQueryModel::qt_metacast(_clname);
}

int TablaTextAlignCenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
