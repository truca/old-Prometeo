
#include "PortListener.h"
#include <QtDebug>
#include <QTimer>
#include "stdio.h"
#include <QStringList>
#include <qextserialenumerator.h>
#include <QInputDialog>
#include <QDir>

PortListener::PortListener(void): QThread()
{
    time.start();
    sysID=1;
    compID=1;
    uavsysID=1;
    wpNum=0;
    wpToReceive=0;
}

void PortListener::gcs_handleMessage(mavlink_message_t* msg)
{
  switch (msg->msgid) {
    case MAVLINK_MSG_ID_ROLL_PITCH_YAW_THRUST_SETPOINT:
        this->ReceiveRPYTSetpoint(msg);
        break;
    case MAVLINK_MSG_ID_HEARTBEAT:
        this->ReceiveHeartBeat(msg);
        this->SendHeartBeat(msg);
        break;
    case MAVLINK_MSG_ID_VFR_HUD:
        this->ReceiveVFRHud(msg);
        break;
    case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
        this-> ReceiveRCChannelsRaw(msg);
        break;
    case MAVLINK_MSG_ID_COMMAND_ACK:
        this->ReceiveCommandResult(msg);
        break;
    case MAVLINK_MSG_ID_PARAM_VALUE:
//        qWarning("PARAM VALUE!!");
        this->ReceiveParamValue(msg);
        break;
/*    case MAVLINK_MSG_ID_GPS_RAW_INT:
        this->ReceiveGPSRAW(msg);
        break;*/
    case MAVLINK_MSG_ID_MISSION_REQUEST:
        qWarning("Mission req.\n");
        this->SendWP(-33,-71+1*wpNum,10000);
        wpNum++;
        break;
    case MAVLINK_MSG_ID_SYS_STATUS:
        this->ReceiveSystemStatus(msg);
        break;
    case MAVLINK_MSG_ID_ATTITUDE:
        this->ReceiveAttitude(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_ACK:
        qWarning("MISSION ACK recibido");
        break;
    case MAVLINK_MSG_ID_MISSION_ITEM:
        qWarning("solicitud de p respondida.");
        this->ReceiveWP(*msg);
        break;
    case MAVLINK_MSG_ID_GPS_STATUS:
        qWarning("GPS status arrived");
        break;
    case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
        qWarning("global position arrived");
        break;
    case MAVLINK_MSG_ID_MISSION_COUNT:
        qWarning("mission count received");
        mavlink_mission_count_t mcount;
        mavlink_msg_mission_count_decode(msg, &mcount);
        if(mcount.count>0){
            this->wpNum=mcount.count;
            this->wpToReceive=0;
            qWarning("cantidad puntos en quad: %d", mcount.count);
            this->SendRequestWP();
        }

        //qWarning("WP's in UAV: %d", mcount.count);
        //
        break;
    case MAVLINK_MSG_ID_STATUSTEXT:
        this->ReceiveStatusText(msg);
        break;
    case MAVLINK_MSG_ID_MISSION_ITEM_REACHED:
        break;
        //mavlink_msg_param_request_list_pack()
    case MAVLINK_MSG_ID_GPS_RAW_INT: {
        mavlink_gps_raw_int_t packet;
        mavlink_msg_gps_raw_int_decode(msg, &packet);
        double lat = ((double)packet.lat)/1e7;
        double lon = ((double)packet.lon)/1e7;
        double altura = packet.alt/1e3;
        emit newAltura(altura);
        if(lat == 0.0 || lon == 0.0) {
//            qWarning("no hay gps %d %d %.7f %.7f", packet.lat, packet.lon, lat, lon);
            break;
        }
//        qWarning("%d %d %.7f %.7f", packet.lat, packet.lon, lat, lon);
//        qWarning("%d %d %.7f %.7f", packet.lat, packet.lon, lat, lon);
//        emit console(QString(" %1 %2\n").arg(packet.lat).arg(lat,0,'g',9));
        emit newGPS(lat, lon);
        break;
  }
   default:
      qWarning("Este mensage no se reconoce: %d", msg->msgid);
      break;
      /*
   case MAVLINK_MSG_ID_ATTITUDE:
    {
      // decode
      mavlink_attitude_t packet;
      mavlink_msg_attitude_decode(msg, &packet);
      pitch = toDeg(packet.pitch);
      yaw = toDeg(packet.yaw);
      roll = toDeg(packet.roll);
      break;
    }
    case MAVLINK_MSG_ID_GPS_STATUS:
    {
      mavlink_gps_status_t packet;
      mavlink_msg_gps_status_decode(msg, &packet);
      numSats = packet.satellites_visible;
      break;
    }
    case MAVLINK_MSG_ID_RAW_PRESSURE:
    {
      // decode
      mavlink_raw_pressure_t packet;
      mavlink_msg_raw_pressure_decode(msg, &packet);
      break;
    }
    case MAVLINK_MSG_ID_SYS_STATUS:
    {

      mavlink_sys_status_t packet;
      mavlink_msg_sys_status_decode(msg, &packet);
      currentSMode = packet.mode;
      currentNMode = packet.nav_mode;
      battery = packet.vbat;
      break;
    }
    case MAVLINK_MSG_ID_PARAM_VALUE:
    {
      // decode
      mavlink_param_value_t packet;
      mavlink_msg_param_value_decode(msg, &packet);
      const char * key = (const char*) packet.param_id;
      int loc = find_param(key);
      if (loc != -1)
      {
        float value;
        parameter temp;
        //strcpy(temp.key, key);
        //temp.value = packet.param_value;
        value = packet.param_value;
        EEPROM_writeFloat((loc * sizeof(temp))+sizeof(temp.key), value);
        //EEPROM_writeParameter((loc * sizeof(temp))+sizeof(temp.key), temp);
        paramsRecv++;
      }
      if (waitingAck == 1)
      {
        if (strcmp(key, editParm.key) == 0)
        {
          waitingAck = 0;
        }
      }
      //else
      //  timeOut = 100; // each time we get another parameter reset the timeout
      //redraw = 1;
      break;
    }*/
  }
}

void PortListener::run() {

    port = new QextSerialPort(port_name, QextSerialPort::EventDriven);
//    port = new QextSerialPort("/dev/tty.usbserial-A501B4MB", QextSerialPort::EventDriven);
    port->setBaudRate(BAUD57600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);

    if (port->open(QIODevice::ReadWrite) == true) {
        connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        qDebug() << "listening for data on" << port->portName();
    }
    else {
        qDebug() << "device failed to open:" << port->errorString();
    }

    exec();
}


void PortListener::selectPortName(QWidget * parent) {
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    QStringList port_files;
    foreach (QextPortInfo info, ports) {
        port_files.append(info.portName);
    }

    bool ok = FALSE;
    const QString str( "Please select an item" );
    QString res = QInputDialog::getItem(parent, str, str, port_files, 0, TRUE, &ok, Qt::Dialog );
    if ( ok )
        port_name = res;
    else
        port_name = port_files[0];
}

void PortListener::onReadyRead()
{
    QByteArray bytes;
    QByteArray bytes_console;
    int a = port->bytesAvailable();
    bytes.resize(a);
    port->read(bytes.data(), bytes.size());
//    emit console(QString(bytes));


    mavlink_status_t *status = mavlink_get_channel_status(0);

    while(bytes.size() > 0) {
        mavlink_message_t msg;
        mavlink_status_t status2;
        char c = bytes[0];
        bytes = bytes.mid(1);
        if(mavlink_parse_char(0, c, &msg, &status2)) {
            gcs_handleMessage(&msg);
        } else
        if(MAVLINK_PARSE_STATE_IDLE == status->parse_state || MAVLINK_PARSE_STATE_UNINIT == status->parse_state) {
            bytes_console.append(c);
        }
    }
    if(bytes_console.size() > 0) // no funciona, imprime todo y deja lento la aplicacion...
        emit console(QString(bytes_console));
}

////////////////////////////////////////////////////////////////////////
//////////SEND//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void PortListener::SendWPCount(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_mission_count_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_MISSIONPLANNER, 3);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("WP COUNT ENVIADO. %d bytes in msg, %d bytes sended", len, bytes);

}

void PortListener::SendRequestWP(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_mission_request_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_MISSIONPLANNER, this->wpToReceive);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("WP REQUEST ENVIADO. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendActivarStream(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_request_data_stream_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_GPS, MAV_DATA_STREAM_ALL, 1, 1);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("ACTIVATE STREAM SENDED. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendWPClear(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_mission_clear_all_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_MISSIONPLANNER);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("WP CLEAR ALL ENVIADO. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendRequestPosition(){
    mavlink_message_t msg;
    mavlink_msg_heartbeat_get_system_status(&msg);

}

void PortListener::SendReceivePosition(mavlink_message_t *msg){
    mavlink_gps_raw_int_t packet;
    mavlink_msg_gps_raw_int_decode(msg, &packet);
    latitude = packet.lat;
    longitude = packet.lon;
    velocity = packet.vel;
    altitude = packet.alt;
    qWarning("lat %f, lon %f, alt %f", latitude, longitude, altitude);
    //position_antenna();
    //gpsfix = packet.fix_type;
}

void PortListener::SendMavCompIDAll(enum MAV_CMD cmd, float param[7], uint8_t confirmation) {
    int tryNumber=0;
    int lat=33;
    int lon=71;
    int alt=5;
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    //comando takeoff
    mavlink_msg_command_long_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_ALL, cmd, confirmation,param[0],param[1],param[2],param[3],param[4],param[5],param[6]);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes;
    if(port->isOpen())
      bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("%d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendArmarDesarmarMotores() {
    float param[7] = {0,0,0,0,0,0,0};
    SendMavCompIDAll(MAV_CMD_COMPONENT_ARM_DISARM, param, 1);
    qWarning("ENVIADO: MAV_CMD_COMPONENT_ARM_DISARM");
}

void PortListener::SendGotoHome() {
    float param[7] = {0,0,0,0,0,0,0};
    SendMavCompIDAll(MAV_CMD_NAV_RETURN_TO_LAUNCH, param, 1);
    qWarning("ENVIADO: MAV_CMD_NAV_RETURN_TO_LAUNCH");
}

void PortListener::SendGoto(double lat, double lng) {
    SendPuntoGPS(TIPO_PUNTO_GPS_GOTO, lat, lng);
}

void PortListener::SendHome(double lat, double lng) {
    SendPuntoGPS(TIPO_PUNTO_GPS_HOME, lat, lng);
}

void PortListener::SendView(double lat, double lng) {
    SendPuntoGPS(TIPO_PUNTO_GPS_VIEW, lat, lng);
}

void PortListener::SendPuntoGPS(enum Tipo_Punto_GPS tipo, double lat, double lng) {
    QByteArray buff(2041,0);
    mavlink_message_t msg;

    uint64_t time_usec = 0;
    uint8_t fix_type = tipo;
    int32_t lattitude = (int32_t)(lat*1e7);
    int32_t longitude = (int32_t)(lng*1e7);
    int32_t alt = 0;
    uint16_t eph;
    uint16_t epv;
    uint16_t vel;
    uint16_t cog;
    uint8_t satellites_visible=255;

    mavlink_msg_gps_raw_int_pack(sysID, compID, &msg, time_usec, fix_type, lattitude, longitude, alt, eph, epv, vel, cog, satellites_visible);

    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("WP ENVIADO. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendDespegar() {
    float param[7] = {0,0,0,0,0,0,0};
    SendMavCompIDAll(MAV_CMD_NAV_TAKEOFF, param, 1);
    qWarning("ENVIADO: MAV_CMD_NAV_TAKEOFF");
}

void PortListener::SendAterrizar() {
    float param[7] = {0,0,0,0,0,0,0};
    SendMavCompIDAll(MAV_CMD_NAV_LAND, param, 1);
    qWarning("ENVIADO: MAV_CMD_NAV_LAND");
}

void PortListener::SendWP(int x, int y, int z){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    int acceptRadius=5/*meters*/,
            loiterTime=0/*milis*/,
            orbitRadius=1/*clockwise, meters*/,
            yaw=0/*north, degrees*/,
            current=1/*true*/,
            autocontinue=1/*true (?)*/,
            sequence=wpNum;

    if( wpNum > 0 )
        current = 0;

    mavlink_msg_mission_item_pack(sysID,compID,&msg, uavsysID, MAV_COMP_ID_MISSIONPLANNER, (uint16_t)sequence,
                                  MAV_FRAME_GLOBAL, MAV_CMD_NAV_WAYPOINT, current, autocontinue,
                                  acceptRadius, loiterTime, orbitRadius, yaw, x,y,z);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("WP ENVIADO. (%d,%d,%d)%d bytes in msg, %d bytes sended",x,y,z, len, bytes);
}

void PortListener::SendRcOverride(uint16_t chan){
    QByteArray buff(2041,0);

    mavlink_message_t msg;
    mavlink_msg_rc_channels_override_pack(sysID, compID, &msg, uavsysID, 1, 1500,1500,1000,1000,0,0,0,0);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes;

    for (int i=0; i<1000; i++)
    {
        bytes = port->write(buff.data(), len);
        this->msleep(200);
        printf(".");
    }


    printf("Envio: ");
    for(int i=0; i<len; i++) {
        printf("%s:%s ", QString::number((unsigned int)buff[i]&0xFF,16).toAscii().data(), QString::number((unsigned int)buff[i]&0xFF,10).toAscii().data());
    }
    printf("\n");
    if (bytes == -1) qWarning ("error sending");
    else qWarning ("Seteado Chan0 como %d. %d bytes in msg, %d bytes sended", chan, len, bytes);

    /*this->msleep(100);

    mavlink_msg_rc_channels_override_pack(sysID, compID, &msg, uavsysID, 1, (uint16_t)2000, (uint16_t)chan,0,0,0,0,0,0);
    len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    bytes = port->write(buff.data(), len);
    if (bytes == -1) qWarning ("error sending");
    else qWarning ("Seteado Chan0 como %d. %d bytes in msg, %d bytes sended", chan, len, bytes);

    this->msleep(100);

    mavlink_msg_rc_channels_override_pack(sysID, compID, &msg, uavsysID, 1, 0, 0,chan,0,0,0,0,0);
    len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    bytes = port->write(buff.data(), len);
    if (bytes == -1) qWarning ("error sending");
    else qWarning ("Seteado Chan0 como %d. %d bytes in msg, %d bytes sended", chan, len, bytes);

    this->msleep(100);

    mavlink_msg_rc_channels_override_pack(sysID, compID, &msg, uavsysID, 1, 0, 0,0,chan,0,0,0,0);
    len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    bytes = port->write(buff.data(), len);
    if (bytes == -1) qWarning ("error sending");
    else qWarning ("Seteado Chan0 como %d. %d bytes in msg, %d bytes sended", chan, len, bytes);*/
}

void PortListener::SendLand(int tryNumber, int lat, int lon, int alt){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_command_long_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_MISSIONPLANNER, MAV_CMD_NAV_LAND, (uint8_t) tryNumber, 0,0,0,0,(float) lat,(float) lon, (float)alt);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("WP CLEAR ALL ENVIADO. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendSetMode(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_set_mode_pack(sysID, compID, &msg, uavsysID, MAV_MODE_AUTO_ARMED, MAV_MODE_STABILIZE_ARMED);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("SET MODE enviado. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendSetRPYT(float roll, float pitch, float yaw, float thrust){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_set_roll_pitch_yaw_thrust_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_ALL, roll, pitch, yaw, thrust);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("SET RPYT SENDED. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendRequestList(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_mission_request_list_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_MISSIONPLANNER);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("REQUEST LIST enviado. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendRequestDataStream(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_request_data_stream_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_ALL, 0, 100, 1);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("REQUEST DATA STREAM enviado. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendHeartBeat(mavlink_message_t *msg){
    QByteArray buff(2041,0);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(),msg);
    buff[3]=0xff;
    buff[4]=0xbe;
    buff[10]=0x06;
    buff[11]=0x03;
    buff[12]=0x00;
    buff[13]=0x00;
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("HeartBeat enviado. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::pedirControl(){
    SendRcOverride(1500);
    qWarning("Pedi Control");
}

void PortListener::perderControl(){
    SendRcOverride(0);
}

void PortListener::SendRequestParamList(){
    QByteArray buff(2041,0);
    mavlink_message_t msg;
    mavlink_msg_param_request_list_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_ALL);
    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("REQUEST PARAM LIST enviado. %d bytes in msg, %d bytes sended", len, bytes);
}

////////////////////////////////////////////////////////////////////////
//////////RECEIVE///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void PortListener::ReceiveCommandResult(mavlink_message_t *msg){
    mavlink_command_ack_t comack;
    mavlink_msg_command_ack_decode(msg, &comack);
    switch(comack.result){
        case MAV_RESULT_ACCEPTED://	Command ACCEPTED and EXECUTED
            qWarning("COMMAND RESULT: MAV_RESULT_ACCEPTED");
            break;
        case MAV_RESULT_TEMPORARILY_REJECTED://	Command TEMPORARY REJECTED/DENIED
            qWarning("COMMAND RESULT: MAV_RESULT_TEMPORARILY_REJECTED");
            break;
        case MAV_RESULT_DENIED://	Command PERMANENTLY DENIED
            qWarning("COMMAND RESULT: MAV_RESULT_DENIED");
            break;
        case MAV_RESULT_UNSUPPORTED://	Command UNKNOWN/UNSUPPORTED
            qWarning("COMMAND RESULT: MAV_RESULT_UNSUPPORTED");
            break;
        case MAV_RESULT_FAILED://	Command executed, but failed
            qWarning("COMMAND RESULT: MAV_RESULT_FAILED");
            break;
    }
}

void PortListener::ReceiveVFRHud(mavlink_message_t *msg){
    mavlink_vfr_hud_t vfr;
    mavlink_msg_vfr_hud_decode(msg, &vfr);
    qWarning("Potencia: %d", (int)vfr.throttle);
}

void PortListener::ReceiveRPYTSetpoint(mavlink_message_t *msg){
    mavlink_roll_pitch_yaw_thrust_setpoint_t rpyt;
    mavlink_msg_roll_pitch_yaw_thrust_setpoint_decode(msg, &rpyt);
    emit newRoll(rpyt.roll);
    emit newPitch(rpyt.pitch);
    emit newYaw(rpyt.yaw);
    emit newThrust(rpyt.thrust);
}

void PortListener::ReceiveGPSRAW(mavlink_message_t *msg){
    mavlink_gps_raw_int_t gps;
    mavlink_msg_gps_raw_int_decode(msg, &gps);
    qWarning("lat: %d, lon: %d, alt: %d", gps.lat, gps.lon, gps.alt);
}

void PortListener::ReceiveAttitude(mavlink_message_t *msg){
    mavlink_attitude_t att;
    mavlink_msg_attitude_decode(msg, &att);
    qWarning("roll: %f, yaw: %f, pitch: %f", att.roll, att.yaw, att.pitch);
}

void PortListener::ReceiveSystemStatus(mavlink_message_t *msg){
    mavlink_sys_status_t sysStat;
    //revisar el estado de las 3 variables de los sensores (bitmask)
    mavlink_msg_sys_status_decode(msg, &sysStat);
    qWarning("ERRORES: %d %d %d %d", (int)sysStat.errors_count1, (int)sysStat.errors_count2, (int)sysStat.errors_count3, (int)sysStat.errors_count4);
    qWarning("VOLTAJE: %dV", (int)(sysStat.voltage_battery/1000));
}

void PortListener::ReceiveStatusText(mavlink_message_t *msg){
    mavlink_statustext_t status;
    mavlink_msg_statustext_decode(msg, &status);
    switch(status.severity){
    case MAV_SEVERITY_EMERGENCY:	//System is unusable. This is a "panic" condition.
        qWarning("MAV_SEVERITY_EMERGENCY");
        break;
    case MAV_SEVERITY_ALERT:        //Action should be taken immediately. Indicates error in non-critical systems.
        qWarning("MAV_SEVERITY_ALERT");
        break;
    case MAV_SEVERITY_CRITICAL:     //Action must be taken immediately. Indicates failure in a primary system.
        qWarning("MAV_SEVERITY_ALERT");
        break;
    case MAV_SEVERITY_ERROR:        //Indicates an error in secondary/redundant systems.
        qWarning("MAV_SEVERITY_ERROR");
        break;
    case MAV_SEVERITY_WARNING:      //Indicates about a possible future error if this is not resolved within a given timeframe. Example would be a low battery warning.
        qWarning("MAV_SEVERITY_WARNING");
        break;
    case MAV_SEVERITY_NOTICE:       //An unusual event has occured, though not an error condition. This should be investigated for the root cause.
        qWarning("MAV_SEVERITY_NOTICE");
        break;
    case MAV_SEVERITY_INFO:         //Normal operational messages. Useful for logging. No action is required for these messages.
        qWarning("MAV_SEVERITY_INFO");
        break;
    case MAV_SEVERITY_DEBUG:        //Useful non-operational messages that can assist in debugging. These should not occur during normal operation.
        qWarning("MAV_SEVERITY_DEBUG");
        break;
    }
}

void PortListener::ReceiveWP(mavlink_message_t msg){
    mavlink_mission_item_t packet;
    mavlink_msg_mission_item_decode(&msg, &packet);
    qWarning("x: %f, y: %f, z: %f, seq: %d", packet.x, packet.y, packet.z, packet.seq);
    this->wpToReceive++;
    if(this->wpToReceive < this->wpNum)
        this->SendRequestWP();
}

void PortListener::ReceiveHeartBeat(mavlink_message_t *msg) {
    latencia=time.elapsed();
    time.restart();

    mavlink_heartbeat_t heart;
    mavlink_msg_heartbeat_decode(msg, &heart);
    switch(heart.system_status){
        case MAV_STATE_UNINIT:	//Uninitialized system, state is unknown.
            qWarning("latencia actualizada. %d, estado: MAV_STATE_UNINIT", latencia);
            break;
        case MAV_STATE_BOOT:	//System is booting up.
            qWarning("latencia actualizada. %d, estado: MAV_STATE_BOOT", latencia);
            break;
        case MAV_STATE_CALIBRATING:	//System is calibrating and not flight-ready.
            qWarning("latencia actualizada. %d, estado: MAV_STATE_CALIBRATING", latencia);
            break;
        case MAV_STATE_STANDBY:	//System is grounded and on standby. It can be launched any time.
            qWarning("latencia actualizada. %d, estado: MAV_STATE_STANDBY", latencia);
            break;
        case MAV_STATE_ACTIVE:	//System is active and might be already airborne. Motors are engaged.
            qWarning("latencia actualizada. %d, estado: MAV_STATE_ACTIVE", latencia);
            break;
        case MAV_STATE_POWEROFF:	//System is in a non-normal flight mode. It can however still navigate.
            qWarning("latencia actualizada. %d, estado: MAV_STATE_POWEROFF", latencia);
            break;
    }
    switch(heart.base_mode){
    case MAV_MODE_FLAG_SAFETY_ARMED://	0b10000000 MAV safety set to armed. Motors are enabled / running / can start. Ready to fly.
        qWarning("MAV_MODE_FLAG_SAFETY_ARMED");
        break;
    case MAV_MODE_FLAG_MANUAL_INPUT_ENABLED://	0b01000000 remote control input is enabled.
        qWarning("MAV_MODE_FLAG_MANUAL_INPUT_ENABLED");
        break;
    case MAV_MODE_FLAG_HIL_ENABLED://	0b00100000 hardware in the loop simulation. All motors / actuators are blocked, but internal software is full operational.
        qWarning("MAV_MODE_FLAG_MANUAL_INPUT_ENABLED");
        break;
    case MAV_MODE_FLAG_STABILIZE_ENABLED://	0b00010000 system stabilizes electronically its attitude (and optionally position). It needs however further control inputs to move around.
        qWarning("MAV_MODE_FLAG_STABILIZE_ENABLED");
        break;
    case MAV_MODE_FLAG_GUIDED_ENABLED://	0b00001000 guided mode enabled, system flies MISSIONs / mission items.
        qWarning("MAV_MODE_FLAG_GUIDED_ENABLED");
        break;
    case MAV_MODE_FLAG_AUTO_ENABLED://	0b00000100 autonomous mode enabled, system finds its own goal positions. Guided flag can be set or not, depends on the actual implementation.
        qWarning("MAV_MODE_FLAG_AUTO_ENABLED");
        break;
    case MAV_MODE_FLAG_TEST_ENABLED://	0b00000010 system has a test mode enabled. This flag is intended for temporary system tests and should not be used for stable implementations.
        qWarning("MAV_MODE_FLAG_TEST_ENABLED");
        break;
    case MAV_MODE_FLAG_CUSTOM_MODE_ENABLED://	0b00000001 Reserved for future use.
        qWarning("MAV_MODE_FLAG_CUSTOM_MODE_ENABLED");
        break;
    default:
        qWarning("wtf?!!! %d", heart.base_mode);
        break;
    }
}

void PortListener::ReceiveRCChannelsRaw(mavlink_message_t *msg){
    mavlink_rc_channels_raw_t channels_raw;
    mavlink_msg_rc_channels_raw_decode(msg,&channels_raw);
    qWarning("canal 1 : %d, canal 2 : %d, canal 3 : %d, canal 4 : %d",(int)channels_raw.chan1_raw, (int)channels_raw.chan2_raw, (int)channels_raw.chan3_raw, (int)channels_raw.chan4_raw);
}

void PortListener::ReceiveParamValue(mavlink_message_t *msg) {
    mavlink_param_value_t param_value;
    enum Tipo_Param tipo;
    mavlink_msg_param_value_decode(msg,&param_value);
    tipo = (enum Tipo_Param)param_value.param_index;
//    qWarning("Nuevo parametro tipo %d", (int)tipo);
    emit newParamValue(tipo, param_value.param_value);
}

void PortListener::SendParam(enum Tipo_Param tipo, float value) {
    QByteArray buff(2041,0);
    mavlink_message_t msg;

    const char *param_id = NULL;
    float param_value = value;
    uint8_t param_type = tipo;
    mavlink_msg_param_set_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_ALL, param_id, param_value, param_type);

    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("SendParam. %d bytes in msg, %d bytes sended", len, bytes);
}

void PortListener::SendRequestParam(enum Tipo_Param tipo) {
    QByteArray buff(2041,0);
    mavlink_message_t msg;

    char param_id[16];
    int16_t param_index = tipo;
    mavlink_msg_param_request_read_pack(sysID, compID, &msg, uavsysID, MAV_COMP_ID_ALL, param_id, param_index);

    int len = mavlink_msg_to_send_buffer((uint8_t *)buff.data(), &msg);
    uint32_t bytes = port->write(buff.data(), len);
    if(bytes==-1)
        qWarning("error sending");
    else
        qWarning("SendRequestParam. %d bytes in msg, %d bytes sended", len, bytes);
}
