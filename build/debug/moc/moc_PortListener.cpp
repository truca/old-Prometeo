/****************************************************************************
** Meta object code from reading C++ file 'PortListener.h'
**
** Created: Thu 4. Apr 02:26:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PortListener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PortListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PortListener[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      33,   31,   13,   13, 0x05,
      65,   31,   13,   13, 0x05,
      87,   13,   13,   13, 0x05,
     105,   13,   13,   13, 0x05,
     121,   13,   13,   13, 0x05,
     138,   13,   13,   13, 0x05,
     153,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     171,   13,   13,   13, 0x08,
     189,  185,   13,   13, 0x08,
     218,  185,   13,   13, 0x08,
     255,  185,   13,   13, 0x08,
     289,  185,   13,   13, 0x08,
     325,  185,   13,   13, 0x08,
     363,  185,   13,   13, 0x08,
     403,  185,   13,   13, 0x08,
     444,  185,   13,   13, 0x08,
     485,  185,   13,   13, 0x08,
     523,  185,   13,   13, 0x08,
     557,  185,   13,   13, 0x08,
     597,   13,   13,   13, 0x08,
     612,   13,   13,   13, 0x08,
     628,   13,   13,   13, 0x0a,
     651,  185,   13,   13, 0x0a,
     685,   13,   13,   13, 0x0a,
     709,   13,   13,   13, 0x0a,
     723,   13,   13,   13, 0x0a,
     743,  737,   13,   13, 0x0a,
     763,   13,   13,   13, 0x0a,
     779,  185,   13,   13, 0x0a,
     819,   13,   13,   13, 0x0a,
     841,   13,   13,   13, 0x0a,
     859,   13,   13,   13, 0x0a,
     879,   13,   13,   13, 0x0a,
     906,   13,   13,   13, 0x0a,
     921,   13,   13,   13, 0x0a,
     937,   13,   13,   13, 0x0a,
     975,  952,   13,   13, 0x0a,
    1040, 1018,   13,   13, 0x0a,
    1071, 1066,   13,   13, 0x0a,
    1118, 1096,   13,   13, 0x0a,
    1155,   13,   13,   13, 0x0a,
    1177, 1169,   13,   13, 0x0a,
    1201, 1169,   13,   13, 0x0a,
    1225, 1169,   13,   13, 0x0a,
    1262, 1249,   13,   13, 0x0a,
    1312, 1305,   13,   13, 0x0a,
    1345, 1340,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PortListener[] = {
    "PortListener\0\0console(QString)\0,\0"
    "newParamValue(Tipo_Param,float)\0"
    "newGPS(double,double)\0newAltura(double)\0"
    "newRoll(double)\0newPitch(double)\0"
    "newYaw(double)\0newThrust(double)\0"
    "onReadyRead()\0msg\0ReceiveWP(mavlink_message_t)\0"
    "ReceiveHeartBeat(mavlink_message_t*)\0"
    "ReceiveGPSRAW(mavlink_message_t*)\0"
    "ReceiveAttitude(mavlink_message_t*)\0"
    "ReceiveStatusText(mavlink_message_t*)\0"
    "ReceiveSystemStatus(mavlink_message_t*)\0"
    "ReceiveCommandResult(mavlink_message_t*)\0"
    "ReceiveRCChannelsRaw(mavlink_message_t*)\0"
    "ReceiveParamValue(mavlink_message_t*)\0"
    "ReceiveVFRHud(mavlink_message_t*)\0"
    "ReceiveRPYTSetpoint(mavlink_message_t*)\0"
    "pedirControl()\0perderControl()\0"
    "SendRequestParamList()\0"
    "SendHeartBeat(mavlink_message_t*)\0"
    "SendRequestDataStream()\0SendWPCount()\0"
    "SendWPClear()\0x,y,z\0SendWP(int,int,int)\0"
    "SendRequestWP()\0SendReceivePosition(mavlink_message_t*)\0"
    "SendRequestPosition()\0SendRequestList()\0"
    "SendActivarStream()\0SendArmarDesarmarMotores()\0"
    "SendDespegar()\0SendAterrizar()\0"
    "SendGotoHome()\0cmd,param,confirmation\0"
    "SendMavCompIDAll(MAV_CMD,float[7],uint8_t)\0"
    "tryNumber,lat,lon,alt\0SendLand(int,int,int,int)\0"
    "chan\0SendRcOverride(uint16_t)\0"
    "roll,pitch,yaw,thrust\0"
    "SendSetRPYT(float,float,float,float)\0"
    "SendSetMode()\0lat,lng\0SendGoto(double,double)\0"
    "SendHome(double,double)\0SendView(double,double)\0"
    "tipo,lat,lng\0SendPuntoGPS(Tipo_Punto_GPS,double,double)\0"
    ",value\0SendParam(Tipo_Param,float)\0"
    "tipo\0SendRequestParam(Tipo_Param)\0"
};

void PortListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PortListener *_t = static_cast<PortListener *>(_o);
        switch (_id) {
        case 0: _t->console((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newParamValue((*reinterpret_cast< Tipo_Param(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: _t->newGPS((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->newAltura((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->newRoll((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->newPitch((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->newYaw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->newThrust((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->onReadyRead(); break;
        case 9: _t->ReceiveWP((*reinterpret_cast< mavlink_message_t(*)>(_a[1]))); break;
        case 10: _t->ReceiveHeartBeat((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 11: _t->ReceiveGPSRAW((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 12: _t->ReceiveAttitude((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 13: _t->ReceiveStatusText((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 14: _t->ReceiveSystemStatus((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 15: _t->ReceiveCommandResult((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 16: _t->ReceiveRCChannelsRaw((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 17: _t->ReceiveParamValue((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 18: _t->ReceiveVFRHud((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 19: _t->ReceiveRPYTSetpoint((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 20: _t->pedirControl(); break;
        case 21: _t->perderControl(); break;
        case 22: _t->SendRequestParamList(); break;
        case 23: _t->SendHeartBeat((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 24: _t->SendRequestDataStream(); break;
        case 25: _t->SendWPCount(); break;
        case 26: _t->SendWPClear(); break;
        case 27: _t->SendWP((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 28: _t->SendRequestWP(); break;
        case 29: _t->SendReceivePosition((*reinterpret_cast< mavlink_message_t*(*)>(_a[1]))); break;
        case 30: _t->SendRequestPosition(); break;
        case 31: _t->SendRequestList(); break;
        case 32: _t->SendActivarStream(); break;
        case 33: _t->SendArmarDesarmarMotores(); break;
        case 34: _t->SendDespegar(); break;
        case 35: _t->SendAterrizar(); break;
        case 36: _t->SendGotoHome(); break;
        case 37: _t->SendMavCompIDAll((*reinterpret_cast< MAV_CMD(*)>(_a[1])),(*reinterpret_cast< float(*)[7]>(_a[2])),(*reinterpret_cast< uint8_t(*)>(_a[3]))); break;
        case 38: _t->SendLand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 39: _t->SendRcOverride((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 40: _t->SendSetRPYT((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 41: _t->SendSetMode(); break;
        case 42: _t->SendGoto((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 43: _t->SendHome((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 44: _t->SendView((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 45: _t->SendPuntoGPS((*reinterpret_cast< Tipo_Punto_GPS(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 46: _t->SendParam((*reinterpret_cast< Tipo_Param(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 47: _t->SendRequestParam((*reinterpret_cast< Tipo_Param(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PortListener::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PortListener::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PortListener,
      qt_meta_data_PortListener, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PortListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PortListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PortListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PortListener))
        return static_cast<void*>(const_cast< PortListener*>(this));
    return QThread::qt_metacast(_clname);
}

int PortListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void PortListener::console(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PortListener::newParamValue(Tipo_Param _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PortListener::newGPS(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PortListener::newAltura(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PortListener::newRoll(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PortListener::newPitch(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PortListener::newYaw(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PortListener::newThrust(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
