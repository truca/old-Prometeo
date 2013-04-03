#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QObject::connect(&w, SIGNAL(quit()), &a, SLOT(quit()));

    return a.exec();
}
