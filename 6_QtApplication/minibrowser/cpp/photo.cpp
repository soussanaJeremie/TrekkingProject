#include "photo.h"

using namespace std;

Photo::Photo(QObject *parent) : QObject(parent) {}

Photo::Photo(QString title, QString currentUrl, bool privatePhoto, QDateTime datePhoto, QObject *parent)
    : QObject(parent), m_title(title), m_currentUrl(currentUrl), m_privatePhoto(privatePhoto)
{
    m_datePhoto = datePhoto.currentDateTime();
}

Photo::Photo(const Photo &_photo, QObject *parent) : QObject(parent)
{
    m_title = _photo.m_title;
    m_currentUrl = _photo.m_currentUrl;
    m_privatePhoto = _photo.m_privatePhoto;
    m_datePhoto = _photo.m_datePhoto;
}

QString Photo::getFileName() const
{
    return m_fileName;
}

void Photo::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

QString Photo::getDatabaseUrl() const
{
    return m_databaseUrl;
}

void Photo::setDatabaseUrl(const QString &databaseUrl)
{
    m_databaseUrl = databaseUrl;
}

void Photo::createFileName()
{
    setFileName(getDatePhoto() + getTitle());
}

void Photo::createDatabaseUrl()
{
    QString adresseServer = "";
    setDatabaseUrl(adresseServer + "pictures/uploads" + getFileName());
}

void Photo::showPhotoData(Photo* photo)
{
    qDebug() << "title : " << photo->getTitle() << endl;
    qDebug() << "currentUrl : " << photo->getCurrentUrl() << endl;
    qDebug() << "private : " << photo->getPrivatePhoto() << endl;
    qDebug() << "datePhoto : " << photo->getDatePhoto() << endl;
    qDebug() << "fileName : " << photo->getFileName() << endl;
    qDebug() << "databaseUrl : " << photo->getDatabaseUrl() << endl;
    qDebug() << endl;
}

QStringList Photo::photoSQLFormat()
{
    QStringList photoData;

    photoData << getTitle()
              << getPrivatePhoto()
              << getDatePhoto()
              << getDatabaseUrl();

    return photoData;
}
