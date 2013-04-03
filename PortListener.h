


#ifndef PORTLISTENER_H_
#define PORTLISTENER_H_

#include <QObject>
#include <QList>
#include <QThread>
#include <QTime>
#include "qextserialport.h"
#include <mavlink.h>

enum Tipo_Punto_GPS {TIPO_PUNTO_GPS_GOTO=1, TIPO_PUNTO_GPS_HOME=2, TIPO_PUNTO_GPS_VIEW=3};

enum Tipo_Param {
    TIPO_PARAM_ALTURA_REF = 0,
    TIPO_PARAM_ALTURA_P   = 1,
    TIPO_PARAM_ALTURA_D   = 2,
    TIPO_PARAM_XY_P       = 3,
    TIPO_PARAM_XY_D       = 4,
    TIPO_PARAM_YAW_P      = 5,
    TIPO_PARAM_YAW_D      = 6,
    TIPO_PARAM_YAW_REF    = 7,
    TIPO_PARAM_COMPASS_OFFSET_0 = 8,
    TIPO_PARAM_COMPASS_OFFSET_1 = 9,
    TIPO_PARAM_COMPASS_OFFSET_2 = 10,
    TIPO_PARAM_ALTURA     = 11,
    TIPO_PARAM_BATERIA    = 12
};

class PortListener : public QThread
{
Q_OBJECT
public:
    PortListener(void);
    QByteArray inputBuffer;
    QList<mavlink_message_t> mensagesRecibidos;
    void run();
    long latencia;
    QTime time;
    int sysID;
    int compID;
    int uavsysID;
    int wpNum;
    int wpToReceive;

    void receiveWP(mavlink_message_t msg);
    int latitude;
    int altitude;
    int longitude;
    int velocity;
    int gpsfix;
    QextSerialPort *port;
    void selectPortName(QWidget * parent);
    QString port_name;

private:
    void gcs_handleMessage(mavlink_message_t* msg);

    QString portName2;

signals:
    void console(QString);
    void newParamValue(enum Tipo_Param, float);
    void newGPS(double, double);
    void newAltura(double);
    void newRoll(double);
    void newPitch(double);
    void newYaw(double);
    void newThrust(double);

private slots:
    void onReadyRead();
    void ReceiveWP(mavlink_message_t msg);
    void ReceiveHeartBeat(mavlink_message_t *msg);
    void ReceiveGPSRAW(mavlink_message_t *msg);
    void ReceiveAttitude(mavlink_message_t *msg);
    void ReceiveStatusText(mavlink_message_t *msg);
    void ReceiveSystemStatus(mavlink_message_t *msg);
    void ReceiveCommandResult(mavlink_message_t *msg);
    void ReceiveRCChannelsRaw(mavlink_message_t *msg);
    void ReceiveParamValue(mavlink_message_t *msg);
    void ReceiveVFRHud(mavlink_message_t *msg);
    void ReceiveRPYTSetpoint(mavlink_message_t *msg);
    void pedirControl();
    void perderControl();

public slots:
    void SendRequestParamList();
    void SendHeartBeat(mavlink_message_t *msg);
    void SendRequestDataStream();
    void SendWPCount();
    void SendWPClear();
    void SendWP(int x, int y, int z);
    void SendRequestWP();
    void SendReceivePosition(mavlink_message_t *msg);
    void SendRequestPosition();
    void SendRequestList();
    void SendActivarStream();
    void SendArmarDesarmarMotores();
    void SendDespegar();
    void SendAterrizar();
    void SendGotoHome();
    void SendMavCompIDAll(enum MAV_CMD cmd, float param[7], uint8_t confirmation);
    void SendLand(int tryNumber, int lat, int lon, int alt);
    void SendRcOverride(uint16_t chan);
    void SendSetRPYT(float roll, float pitch, float yaw, float thrust);
    void SendSetMode();
    void SendGoto(double lat, double lng);
    void SendHome(double lat, double lng);
    void SendView(double lat, double lng);
    void SendPuntoGPS(enum Tipo_Punto_GPS tipo, double lat, double lng);
    void SendParam(enum Tipo_Param, float value);
    void SendRequestParam(enum Tipo_Param tipo);
};


#endif /*PORTLISTENER_H_*/
