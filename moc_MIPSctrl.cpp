/****************************************************************************
** Meta object code from reading C++ file 'MIPSctrl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/MIPSctrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MIPSctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MIPSctrl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      21,    9,    9,    9, 0x0a,
      32,    9,    9,    9, 0x0a,
      39,    9,    9,    9, 0x0a,
      47,    9,    9,    9, 0x0a,
      58,    9,    9,    9, 0x0a,
      69,    9,    9,    9, 0x0a,
      83,    9,    9,    9, 0x0a,
      91,    9,    9,    9, 0x0a,
     119,  116,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MIPSctrl[] = {
    "MIPSctrl\0\0readImem()\0readDmem()\0step()\0"
    "reset()\0showImem()\0showDmem()\0"
    "showRegfile()\0about()\0windowsMenuAboutToShow()\0"
    "id\0windowsMenuActivated(int)\0"
};

void MIPSctrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MIPSctrl *_t = static_cast<MIPSctrl *>(_o);
        switch (_id) {
        case 0: _t->readImem(); break;
        case 1: _t->readDmem(); break;
        case 2: _t->step(); break;
        case 3: _t->reset(); break;
        case 4: _t->showImem(); break;
        case 5: _t->showDmem(); break;
        case 6: _t->showRegfile(); break;
        case 7: _t->about(); break;
        case 8: _t->windowsMenuAboutToShow(); break;
        case 9: _t->windowsMenuActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MIPSctrl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MIPSctrl::staticMetaObject = {
    { &Q3MainWindow::staticMetaObject, qt_meta_stringdata_MIPSctrl,
      qt_meta_data_MIPSctrl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MIPSctrl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MIPSctrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MIPSctrl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MIPSctrl))
        return static_cast<void*>(const_cast< MIPSctrl*>(this));
    return Q3MainWindow::qt_metacast(_clname);
}

int MIPSctrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
