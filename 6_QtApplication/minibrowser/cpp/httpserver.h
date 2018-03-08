#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QtNetwork>
#include <QUrl>
#include <QFile>
#include <QDebug>

#include "debugclass.h"


class HttpServer
{
public:

    HttpServer();

    static void post(QString uri, QString filename);

public slots:
signals:
private:
};

#endif // HTTPSERVER_H
