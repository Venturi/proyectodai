/****************************************************************************
** Meta object code from reading C++ file 'maincongressman.h'
**
** Created: Thu Jun 13 22:02:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VenturiCongressMan/maincongressman.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maincongressman.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainCongressMan[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      26,   16,   16,   16, 0x08,
      41,   16,   16,   16, 0x08,
      62,   16,   16,   16, 0x08,
      80,   16,   16,   16, 0x08,
      95,   16,   16,   16, 0x08,
     126,  118,  114,   16, 0x08,
     157,   16,   16,   16, 0x08,
     185,   16,   16,   16, 0x08,
     206,   16,   16,   16, 0x08,
     240,   16,   16,   16, 0x08,
     278,   16,   16,   16, 0x08,
     302,   16,   16,   16, 0x08,
     332,   16,   16,   16, 0x08,
     356,   16,   16,   16, 0x08,
     380,   16,   16,   16, 0x08,
     402,   16,   16,   16, 0x08,
     427,   16,   16,   16, 0x08,
     451,   16,   16,   16, 0x08,
     499,  488,  483,   16, 0x08,
     529,  526,   16,   16, 0x08,
     543,  526,   16,   16, 0x08,
     557,   16,   16,   16, 0x08,
     580,   16,   16,   16, 0x08,
     604,   16,   16,   16, 0x08,
     632,   16,   16,   16, 0x08,
     653,   16,   16,   16, 0x08,
     673,   16,   16,   16, 0x08,
     696,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainCongressMan[] = {
    "MainCongressMan\0\0initUI()\0resetEventos()\0"
    "resetOrganizadores()\0resetAsistentes()\0"
    "resetLugares()\0resetUbicaciones()\0int\0"
    ",,model\0busca(int,int,QSqlQueryModel*)\0"
    "on_tabMain_currentChanged()\0"
    "on_cmdExit_clicked()\0"
    "on_cmbLugar_currentIndexChanged()\0"
    "on_cmbUbicacion_currentIndexChanged()\0"
    "on_tblEventos_clicked()\0"
    "on_tblOrganizadores_clicked()\0"
    "on_cmdCheckin_clicked()\0on_cmdLimpiar_clicked()\0"
    "on_cmdNuevo_clicked()\0on_cmdEliminar_clicked()\0"
    "on_cmdGuardar_clicked()\0"
    "on_datFechaInicio_dateChanged()\0bool\0"
    "message,op\0customBox(const char*,int)\0"
    "op\0doUpdate(int)\0doInsert(int)\0"
    "on_cmdBuscar_clicked()\0on_tblLugares_clicked()\0"
    "on_tblUbicaciones_clicked()\0"
    "on_cmdEdit_clicked()\0on_cmdAdd_clicked()\0"
    "on_cmdRemove_clicked()\0on_cmdRefresh_clicked()\0"
};

void MainCongressMan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainCongressMan *_t = static_cast<MainCongressMan *>(_o);
        switch (_id) {
        case 0: _t->initUI(); break;
        case 1: _t->resetEventos(); break;
        case 2: _t->resetOrganizadores(); break;
        case 3: _t->resetAsistentes(); break;
        case 4: _t->resetLugares(); break;
        case 5: _t->resetUbicaciones(); break;
        case 6: { int _r = _t->busca((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QSqlQueryModel*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->on_tabMain_currentChanged(); break;
        case 8: _t->on_cmdExit_clicked(); break;
        case 9: _t->on_cmbLugar_currentIndexChanged(); break;
        case 10: _t->on_cmbUbicacion_currentIndexChanged(); break;
        case 11: _t->on_tblEventos_clicked(); break;
        case 12: _t->on_tblOrganizadores_clicked(); break;
        case 13: _t->on_cmdCheckin_clicked(); break;
        case 14: _t->on_cmdLimpiar_clicked(); break;
        case 15: _t->on_cmdNuevo_clicked(); break;
        case 16: _t->on_cmdEliminar_clicked(); break;
        case 17: _t->on_cmdGuardar_clicked(); break;
        case 18: _t->on_datFechaInicio_dateChanged(); break;
        case 19: { bool _r = _t->customBox((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 20: _t->doUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->doInsert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_cmdBuscar_clicked(); break;
        case 23: _t->on_tblLugares_clicked(); break;
        case 24: _t->on_tblUbicaciones_clicked(); break;
        case 25: _t->on_cmdEdit_clicked(); break;
        case 26: _t->on_cmdAdd_clicked(); break;
        case 27: _t->on_cmdRemove_clicked(); break;
        case 28: _t->on_cmdRefresh_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainCongressMan::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainCongressMan::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainCongressMan,
      qt_meta_data_MainCongressMan, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainCongressMan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainCongressMan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainCongressMan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainCongressMan))
        return static_cast<void*>(const_cast< MainCongressMan*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainCongressMan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
