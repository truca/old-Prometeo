#include <QtGui/QApplication>
#include "mainwindow.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Server server;
    
    return a.exec();
}
