#include "cpp/httpserver.h"

HttpServer::HttpServer()
{

}

void HttpServer::post(QString uri, QString filename)
{
    DebugClass::getInstance()->saveDebugMsg("info", "httpserver ready");

    // Boundary
    QByteArray boundary = "---------------------------87142694621188";

    // Initialization of the request
    QUrl url = QUrl("http://localhost:3000/upload");
    QNetworkRequest requete(url);
    QNetworkAccessManager *m = new QNetworkAccessManager;

    // Creation of the headers
    QByteArray ct = QString("Content-Type").toLatin1().constData();
    QByteArray mp = QString("multipart/form-data; boundary=" + boundary).toLatin1().constData();
    requete.setRawHeader(ct, mp);


    // Open file
    QFile file( uri );
    file.open( QIODevice::ReadOnly );


    //Variable
    QByteArray data = "--" + boundary + "\r\n";
    data += "Content-Disposition: form-data; name=\"upload\"; filename=\"" + filename + ".jpg\";\r\n";
    data += "Content-Type: image/jpeg\r\n\r\n" + file.readAll() + "\r\n";
    data += "--" + boundary + "--\r\n";


    QByteArray cl = QString("Content-Length").toLatin1().constData();
    QByteArray si = QString::number(data.size()).toLatin1().constData();
    requete.setRawHeader(cl,si);


    QNetworkReply *r = m->post( requete, data );

    if (r->error())
        DebugClass::getInstance()->saveDebugMsg("Error", "An error was found during the processing of the request");

    r->finished();
    file.close();
}

