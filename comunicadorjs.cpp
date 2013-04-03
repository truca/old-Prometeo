#include "comunicadorjs.h"

#include <QMessageBox>

JSComunicador::JSComunicador(QObject *parent) :
    QObject(parent)
{

}

void JSComunicador::setHomeJS(float lat, float lng) {
    emit setHome(lat, lng);
    qWarning("Home seteado! %f %f", lat, lng);
}

