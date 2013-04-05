#include "tcpclient.h"
#include <QHostAddress>

TCPClient::TCPClient(QObject* parent): QObject(parent)
{

}

TCPClient::~TCPClient()
{
  client.close();
}

void TCPClient::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}

void TCPClient::SendLonLat(float lon, float lat){
    this->lat = lat;
    this->lon = lon;
    client.write(QByteArray::fromRawData(codificar(this->lat, this->lon, this->yaw, this->altura), 41));
}

void TCPClient::SendYaw(float yaw){
    this->yaw = yaw;
    client.write(QByteArray::fromRawData(codificar(this->lat, this->lon, this->yaw, this->altura), 41));
}

void TCPClient::SendHight(float hight){
    this->alt = high;
    client.write(QByteArray::fromRawData(codificar(this->lat, this->lon, this->yaw, this->altura), 41));
}

unsigned char * TCPClient::codificar(lat, lon, yaw, alt){
    unsigned char msg[41];
    msg[0] = 0x01h;
    unsigned short largo = 32;
    msg[1] = (largo>>8) & 0xff;
    msg[2] = largo & 0xff;
    unsigned short largo_n = (~largo);
    msg[3] = (largo_n>>8) & 0xff;
    msg[4] = largo_n & 0xff;
    msg[5] = 0x02h;
    //****** INICIO DATA ******
    msg[6] = 17h;
    msg[7] = 0x00;
    msg[8] = 0x00;
    msg[9] = 0x00;
    //id
    unsigned int id = 1;
    msg[10] = (id>>24) & 0xff;
    msg[11] = (id>>16) & 0xff;
    msg[12] = (id>>8) & 0xff;
    msg[13] = id & 0xff;
    //latitud
    unsigned int latitud = lat * 10000000;
    msg[14] = (latitud>>24) & 0xff;
    msg[15] = (latitud>>16) & 0xff;
    msg[16] = (latitud>>8) & 0xff;
    msg[17] = latitud & 0xff;
    //longitud
    unsigned int longitud = lon * 10000000;
    msg[18] = (longitud>>24) & 0xff;
    msg[19] = (longitud>>16) & 0xff;
    msg[20] = (longitud>>8) & 0xff;
    msg[21] = longitud & 0xff;
    //altura
    unsigned int altura = alt * 100;
    msg[22] = (altura>>24) & 0xff;
    msg[23] = (altura>>16) & 0xff;
    msg[24] = (altura>>8) & 0xff;
    msg[25] = altura & 0xff;
    //rumbo
    unsigned int rumbo = 0 * 1000;
    msg[26] = (rumbo>>24) & 0xff;
    msg[27] = (rumbo>>16) & 0xff;
    msg[28] = (rumbo>>8) & 0xff;
    msg[29] = rumbo & 0xff;
    //velocidad
    unsigned int velocidad = 0 * 1000;
    msg[30] = (velocidad>>24) & 0xff;
    msg[31] = (velocidad>>16) & 0xff;
    msg[31] = (velocidad>>8) & 0xff;
    msg[33] = velocidad & 0xff;
    //yaw
    unsigned int yaw_u = yaw * 100;
    msg[34] = (yaw_u>>24) & 0xff;
    msg[35] = (yaw_u>>16) & 0xff;
    msg[36] = (yaw_u>>8) & 0xff;
    msg[37] = yaw_u & 0xff;
    //*******   FIN DATA ********
    msg[38] = 03h;
    unsigned short checksum;
    int i;
    for(i=6; i<38; i++){
        checksum += msg[i];
    }
    //darle valor al checksum
    msg[39] = (checksum>>8) & 0xff;
    msg[40] = checksum & 0xff;
    msg[41] = 04h;

    return msg;
}



















