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
