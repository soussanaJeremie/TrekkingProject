#include "photo.h"

using namespace std;

Photo::Photo(QObject *parent) : QObject(parent) {}

Photo::Photo(QString title, QString url, bool privatePhoto, /*GpsPoint* gpsPoint,*/ QObject *parent)
    : m_title(title), m_url(url), m_privatePhoto(privatePhoto), /*m_gpsPoint(gpsPoint),*/ QObject(parent) {}

Photo::Photo(const Photo &_photo, QObject *parent) : QObject(parent)
{
    m_title = _photo.m_title;
    m_url = _photo.m_url;
    m_privatePhoto = _photo.m_privatePhoto;
    //    m_gpsPoint = _photo.m_gpsPoint;
}

void Photo::showPhotoData(Photo* photo)
{
    qDebug() << "title : " << photo->title() << endl;
    qDebug() << "url : " << photo->url() << endl;
    qDebug() << "private : " << photo->privatePhoto() << endl;
    qDebug() << endl;
}
