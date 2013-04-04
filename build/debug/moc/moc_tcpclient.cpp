/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created: Thu 4. Apr 06:59:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tcpclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TCPClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      35,   27,   10,   10, 0x0a,
      63,   59,   10,   10, 0x0a,
      84,   78,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TCPClient[] = {
    "TCPClient\0\0startTransfer()\0lon,lat\0"
    "SendLonLat(float,float)\0yaw\0SendYaw(float)\0"
    "hight\0SendHight(float)\0"
};

void TCPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TCPClient *_t = static_cast<TCPClient *>(_o);
        switch (_id) {
        case 0: _t->startTransfer(); break;
        case 1: _t->SendLonLat((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: _t->SendYaw((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->SendHight((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TCPClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TCPClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPClient,
      qt_meta_data_TCPClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TCPClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TCPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TCPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TCPClient))
        return static_cast<void*>(const_cast< TCPClient*>(this));
    return QObject::qt_metacast(_clname);
}

int TCPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
