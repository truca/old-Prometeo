#ifndef CHROMIFICADOR_H
#define CHROMIFICADOR_H

#include <QObject>
#include <QWebPage>


class Chromificador : public QWebPage
{
    Q_OBJECT
public:
    explicit Chromificador();
    virtual QString userAgentForUrl(const QUrl& url) const {
        return "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.2 (KHTML, like Gecko) Chrome/15.0.874.121 Safari/535.2";
    }
protected:
    virtual void  javaScriptConsoleMessage ( const QString & message, int lineNumber, const QString & sourceID );

signals:

public slots:

};

#endif // CHROMIFICADOR_H
