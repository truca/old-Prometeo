#include "chromificador.h"

Chromificador::Chromificador()
{
}

void  Chromificador::javaScriptConsoleMessage ( const QString & message, int lineNumber, const QString & sourceID ) {
    qWarning("%s linea:%d archivo:%s", message.toAscii().data(), lineNumber, sourceID.toAscii().data());
}
