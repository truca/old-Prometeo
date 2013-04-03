#include "mapa.h"

Mapa::Mapa(QWidget *parent) :
    QWebView(parent)
{


    // MAPA
    comunicadorjs = new JSComunicador(this);
    setPage(new Chromificador());

    settings()->setAttribute( QWebSettings::JavascriptEnabled, true );
    settings()->setAttribute( QWebSettings::DeveloperExtrasEnabled, true );

    connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(addJSObject()));
    connect(page(), SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));

//    load(QUrl("http://www.puertosur.cl/images/Mapa2.html"));
    load(QUrl("http://www.xaerials.lin.cl/Mapa.html"));


    connect(comunicadorjs, SIGNAL(addWaypoint(float,float)), this, SLOT(JSaddWaypoint(float,float)));
    connect(comunicadorjs, SIGNAL(setHome(float,float)), this, SLOT(JSsetHome(float,float)));
    connect(comunicadorjs, SIGNAL(setView(float,float)), this, SLOT(JSsetView(float,float)));
}

void Mapa::loadFinished(bool ok) {
    page()->mainFrame()->evaluateJavaScript("setCenter(-33.02321, -71.55033, 10);");
//    page()->mainFrame()->evaluateJavaScript("addPosition(-33.02321, -71.55033)");
}

void Mapa::JSaddWaypoint(float lat, float lng){
    qWarning("Senial punto GPS emitido!");
    emit setGoto((double)lat, (double)lng);
}

void Mapa::JSsetView(float lat, float lng){
    qWarning("Senial View emitido!");
    emit setView((double)lat, (double)lng);
}

void Mapa::JSsetHome(float lat, float lng){
    qWarning("Senial Home emitido!");
    emit setHome((double)lat, (double)lng);
}

void Mapa::addPosition(double lat, double lng){
    QString Lat, Lng;
    Lat.setNum(lat, 'g', 9);
    Lng.setNum(lng, 'g', 9);
    page()->mainFrame()->evaluateJavaScript("addPosition("+Lat+","+Lng+");");
}

void Mapa::addJSObject() {
    page()->mainFrame()->addToJavaScriptWindowObject("comunicadorjs", comunicadorjs);
}

void Mapa::setCenter(float lat, float lng, int zoom){
    QString Lat, Lng, Zoom;
    Lat.setNum(lat, 'g', 9);
    Lng.setNum(lng, 'g', 9);
    Zoom.setNum(zoom);
    page()->mainFrame()->evaluateJavaScript("setCenter2("+Lat+","+Lng+","+Zoom+");");
}
