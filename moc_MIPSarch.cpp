/****************************************************************************
** Meta object code from reading C++ file 'MIPSarch.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/MIPSarch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MIPSarch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MIPSarch[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      24,    9,    9,    9, 0x05,
      38,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MIPSarch[] = {
    "MIPSarch\0\0imemClicked()\0dmemClicked()\0"
    "regfileClicked()\0updateArch()\0"
};

void MIPSarch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MIPSarch *_t = static_cast<MIPSarch *>(_o);
        switch (_id) {
        case 0: _t->imemClicked(); break;
        case 1: _t->dmemClicked(); break;
        case 2: _t->regfileClicked(); break;
        case 3: _t->updateArch(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MIPSarch::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MIPSarch::staticMetaObject = {
    { &Q3CanvasView::staticMetaObject, qt_meta_stringdata_MIPSarch,
      qt_meta_data_MIPSarch, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MIPSarch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MIPSarch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MIPSarch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MIPSarch))
        return static_cast<void*>(const_cast< MIPSarch*>(this));
    return Q3CanvasView::qt_metacast(_clname);
}

int MIPSarch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3CanvasView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MIPSarch::imemClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MIPSarch::dmemClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MIPSarch::regfileClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
