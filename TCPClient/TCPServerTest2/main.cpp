#include <QtCore/QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug("Holi");
    Server server;
    return a.exec();
}
