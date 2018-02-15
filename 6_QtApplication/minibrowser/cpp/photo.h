#ifndef PHOTO_H
#define PHOTO_H

#include <QObject>
#include <QDateTime>

#include "gpspoint.h"

class Photo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString currentUrl READ getCurrentUrl WRITE setCurrentUrl NOTIFY currentUrlChanged)
    Q_PROPERTY(bool privatePhoto READ getPrivatePhoto WRITE setPrivatePhoto NOTIFY privatePhotoChanged)
    Q_PROPERTY(QDateTime datePhoto READ getDatePhoto WRITE setDatePhoto NOTIFY datePhotoChanged)


private:

    QString m_title;
    QString m_currentUrl;
    bool m_privatePhoto;    
    QDateTime m_datePhoto;

    QString m_fileName;
    QString m_databaseUrl;

public:
    explicit Photo(QObject *parent = nullptr);
    Photo(const QString title, QString currentUrl, const bool privatePhoto, QDateTime datePhoto, QObject *parent = 0);
    Photo(const Photo &_photo, QObject *parent = 0);

    QString getFileName() const;
    void setFileName(const QString &fileName);

    QString getDatabaseUrl() const;
    void setDatabaseUrl(const QString &databaseUrl);

    void showPhotoData(Photo *photo);
    QStringList photoSQLFormat();

    QString getTitle() const
    {
        return m_title;
    }

    QString getCurrentUrl() const
    {
        return m_currentUrl;
    }

    bool getPrivatePhoto() const
    {
        return m_privatePhoto;
    }

    QDateTime getDatePhoto() const
    {
        return m_datePhoto;
    }

signals:

    void titleChanged(QString title);

    void currentUrlChanged(QString currentUrl);

    void privatePhotoChanged(bool privatePhoto);

    void datePhotoChanged(QDateTime datePhoto);

public slots:

    void setTitle(QString title)
    {
        if (m_title == title)
            return;

        m_title = title;
        emit titleChanged(m_title);
    }

    void setcurrentUrl(QString currentUrl)
    {
        if (m_currentUrl == currentUrl)
            return;

        m_currentUrl = currentUrl;
        emit currentUrlChanged(m_currentUrl);
    }

    void setPrivatePhoto(bool privatePhoto)
    {
        if (m_privatePhoto == privatePhoto)
            return;

        m_privatePhoto = privatePhoto;
        emit privatePhotoChanged(m_privatePhoto);
    }
    void setDatePhoto(QDateTime datePhoto)
    {
        if (m_datePhoto == datePhoto)
            return;

        m_datePhoto = datePhoto;
        emit datePhotoChanged(m_datePhoto);
    }
};

#endif // PHOTO_H
