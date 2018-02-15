#include "cpp/httpserver.h"

HttpServer::HttpServer()
{

}

void HttpServer::post(QString uri, QString filename)
{
    qDebug() << "httpserver ready";

    // On crée le boundary
    QByteArray boundary = "---------------------------87142694621188";

    // On initie la requete
    QUrl url = QUrl("http://localhost:3000/upload");
    QNetworkRequest requete(url);
    QNetworkAccessManager *m = new QNetworkAccessManager;

    // Creation des headers
    QByteArray ct = QString("Content-Type").toLatin1().constData();
    QByteArray mp = QString("multipart/form-data; boundary=" + boundary).toLatin1().constData();
    requete.setRawHeader(ct, mp);


    // On ouvre le fichier à envoyer
    QFile file( uri );
    file.open( QIODevice::ReadOnly );


    //creation de la variable passee a POST
    QByteArray data = "--" + boundary + "\r\n";
    data += "Content-Disposition: form-data; name=\"upload\"; filename=\"" + filename + ".jpg\";\r\n";
    data += "Content-Type: image/jpeg\r\n\r\n" + file.readAll() + "\r\n";
    data += "--" + boundary + "--\r\n";


    QByteArray cl = QString("Content-Length").toLatin1().constData();
    QByteArray si = QString::number(data.size()).toLatin1().constData();
    requete.setRawHeader(cl,si);


    QNetworkReply *r = m->post( requete, data );
    r->finished();
    file.close();


}

