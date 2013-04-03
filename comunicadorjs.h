#ifndef JSCOMUNICADOR_H
#define JSCOMUNICADOR_H

#include <QObject>

class JSComunicador : public QObject
{
    Q_OBJECT
public:
    explicit JSComunicador(QObject *parent = 0);
    void setHomeJS(float lat, float lng);

signals:
    void addWaypoint(float lat, float lng);
    void setHome(float lat, float lng);
    void setView(float lat, float lng);

public slots:

private:

};

#endif // JSCOMUNICADOR_H
