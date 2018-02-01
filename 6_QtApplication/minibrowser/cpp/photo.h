#ifndef PHOTO_H
#define PHOTO_H

#include <QObject>

#include "gpspoint.h"

class Photo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(bool privatePhoto READ privatePhoto WRITE setPrivatePhoto NOTIFY privatePhotoChanged)
//    Q_PROPERTY(GpsPoint* gpsPoint READ getGpsPoint WRITE setGpsPoint NOTIFY gpsPointChanged)

private:

    QString m_title;
    QString m_url;
    bool m_privatePhoto;
//    GpsPoint* m_gpsPoint;

public:
    explicit Photo(QObject *parent = nullptr);
    Photo(const QString title, QString url, const bool privatePhoto, /*GpsPoint *gpsPoint,*/ QObject *parent = 0);
    Photo(const Photo &_photo, QObject *parent = 0);

    void showPhotoData(Photo *photo);

    QString title() const
    {
        return m_title;
    }

    QString url() const
    {
        return m_url;
    }

    bool privatePhoto() const
    {
        return m_privatePhoto;
    }

   /* GpsPoint* gpsPoint() const
    {
        return m_gpsPoint;
    }

    void setGpsPoint(GpsPoint* const &gpsPoint)
    {
        m_gpsPoint = gpsPoint;
    }

    GpsPoint* getGpsPoint() const
    {
        return m_gpsPoint;
    }*/

signals:

    void titleChanged(QString title);

    void urlChanged(QString url);

    void privatePhotoChanged(bool privatePhoto);

//    void gpsPointChanged(GpsPoint* gpsPoint);

public slots:

    void setTitle(QString title)
    {
        if (m_title == title)
            return;

        m_title = title;
        emit titleChanged(m_title);
    }

    void setUrl(QString url)
    {
        if (m_url == url)
            return;

        m_url = url;
        emit urlChanged(m_url);
    }

    void setPrivatePhoto(bool privatePhoto)
    {
        if (m_privatePhoto == privatePhoto)
            return;

        m_privatePhoto = privatePhoto;
        emit privatePhotoChanged(m_privatePhoto);
    }
};

#endif // PHOTO_H
