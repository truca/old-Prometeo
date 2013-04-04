/****************************************************************************
** Meta object code from reading C++ file 'mapa.h'
**
** Created: Thu 4. Apr 02:26:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mapa.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mapa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Mapa[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,    6,    5,    5, 0x05,
      37,    6,    5,    5, 0x05,
      60,    6,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,    5,    5,    5, 0x0a,
      97,    6,    5,    5, 0x0a,
     124,    6,    5,    5, 0x0a,
     147,    6,    5,    5, 0x0a,
     170,    6,    5,    5, 0x0a,
     210,  197,    5,    5, 0x0a,
     237,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Mapa[] = {
    "Mapa\0\0lat,lng\0setGoto(double,double)\0"
    "setHome(double,double)\0setView(double,double)\0"
    "addJSObject()\0JSaddWaypoint(float,float)\0"
    "JSsetView(float,float)\0JSsetHome(float,float)\0"
    "addPosition(double,double)\0lat,lng,zoom\0"
    "setCenter(float,float,int)\0"
    "loadFinished(bool)\0"
};

void Mapa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Mapa *_t = static_cast<Mapa *>(_o);
        switch (_id) {
        case 0: _t->setGoto((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->setHome((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->setView((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->addJSObject(); break;
        case 4: _t->JSaddWaypoint((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->JSsetView((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 6: _t->JSsetHome((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 7: _t->addPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->setCenter((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Mapa::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Mapa::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_Mapa,
      qt_meta_data_Mapa, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Mapa::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Mapa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Mapa::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mapa))
        return static_cast<void*>(const_cast< Mapa*>(this));
    return QWebView::qt_metacast(_clname);
}

int Mapa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Mapa::setGoto(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Mapa::setHome(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Mapa::setView(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
