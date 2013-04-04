/****************************************************************************
** Meta object code from reading C++ file 'comunicadorjs.h'
**
** Created: Thu 4. Apr 02:26:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../comunicadorjs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comunicadorjs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JSComunicador[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x05,
      48,   15,   14,   14, 0x05,
      69,   15,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_JSComunicador[] = {
    "JSComunicador\0\0lat,lng\0addWaypoint(float,float)\0"
    "setHome(float,float)\0setView(float,float)\0"
};

void JSComunicador::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        JSComunicador *_t = static_cast<JSComunicador *>(_o);
        switch (_id) {
        case 0: _t->addWaypoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->setHome((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: _t->setView((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData JSComunicador::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject JSComunicador::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JSComunicador,
      qt_meta_data_JSComunicador, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JSComunicador::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JSComunicador::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JSComunicador::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JSComunicador))
        return static_cast<void*>(const_cast< JSComunicador*>(this));
    return QObject::qt_metacast(_clname);
}

int JSComunicador::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void JSComunicador::addWaypoint(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JSComunicador::setHome(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JSComunicador::setView(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
