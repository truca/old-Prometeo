#include "tcpclient.h"
#include <QHostAddress>

TCPClient::TCPClient(QObject* parent): QObject(parent)
{
  connect(&client, SIGNAL(connected()),
    this, SLOT(startTransfer()));
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

void TCPClient::startTransfer()
{
  client.write("Hello, world", 13);
}

void TCPClient::SendLonLat(float lon, float lat){}
void TCPClient::SendYaw(float yaw){}
void TCPClient::SendHight(float hight){}
