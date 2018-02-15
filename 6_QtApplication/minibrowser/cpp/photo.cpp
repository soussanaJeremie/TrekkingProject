#include "photo.h"

using namespace std;

Photo::Photo(QObject *parent) : QObject(parent) {}

Photo::Photo(const QString title, QString currentUrl, const bool privatePhoto, QDateTime datePhoto, QObject *parent)
 : QObject(parent), m_title(title), m_currentUrl(currentUrl), m_privatePhoto(privatePhoto) {}

Photo::Photo(const Photo &_photo, QObject *parent) : QObject(parent)
{
    m_title = _photo.m_title;
    m_currentUrl = _photo.m_currentUrl;
    m_privatePhoto = _photo.m_privatePhoto;
    m_datePhoto = _photo.m_datePhoto;
    m_fileName = _photo.m_fileName;
    m_databaseUrl = _photo.m_databaseUrl;
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
    setFileName( this->getDatePhoto().toString("yyyy.MM.dd hh:mm:ss") + getTitle());
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
              << QString::number(getPrivatePhoto())
              << this->getDatePhoto().toString("yyyy.MM.dd hh:mm:ss")
              << getDatabaseUrl();

    return photoData;
}
