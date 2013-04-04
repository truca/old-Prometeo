#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QtNetwork>

class TCPClient: public QObject
{
Q_OBJECT
public:
  TCPClient(QObject* parent = 0);
  ~TCPClient();
  void start(QString address, quint16 port);
public slots:
  void startTransfer();
private:
  QTcpSocket client;
};

#endif // TCPCLIENT_H
