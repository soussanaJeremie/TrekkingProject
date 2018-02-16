#ifndef TREK_H
#define TREK_H

#include <QObject>
#include <QDebug>

#include "gpspoint.h"
#include "photo.h"

class Trek : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ getLabel WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString length READ getLength WRITE setLength NOTIFY lengthChanged)
    Q_PROPERTY(QString time READ getTime WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QList<QObject*> path READ getPath WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QList<QObject*> photos READ getPhotos WRITE setPhotos NOTIFY photosChanged)
    Q_PROPERTY(QString level READ getLevel WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(bool done READ getDone WRITE setDone NOTIFY doneChanged)
    Q_PROPERTY(QList<QObject*> trace READ getTrace WRITE setTrace NOTIFY traceChanged)

//    Q_PROPERTY(QString test READ test WRITE setTest NOTIFY testChanged)

    QString m_label;
    QString m_length;
    QString m_time;
    QList<QObject*> m_path;
    QList<QObject*> m_photos;
    QString m_level;
    bool m_done;
    QList<QObject*> m_trace;


public:
    explicit Trek(QObject *parent = nullptr);

    /// BASIC CONSTRUCTORS AND DESTRUCTOR
    Trek(const QString &label, const double &latitude, const double &longitude, const QString &trace = "", QObject *parent = 0);
    Trek(const Trek &otherTrek, QObject *parent = 0);
    ~Trek();

    /// OBJECT MODIFIERS
    void addNewGpsPoint (GpsPoint newGpsPoint);
    bool didUserMove (GpsPoint &newGpsPoint);
    void addPhoto(Photo *myPhoto);

    /////////////////////////////////
    /// SAVING AND LOADING METHODS///
    /////////////////////////////////

    Trek(QStringList &trekData, QObject *parent = nullptr);
    QList<QObject*> pathJSONToQList(QString &pathData);
    QString pathSQLFormat();
    QStringList trekSQLFormat();


    //////////////////////////
    /// GETTERS AND SETTERS///
    //////////////////////////

    QString getLabel() const
    {
        return m_label;
    }

    QString getLength() const
    {
        return m_length;
    }

    QString getTime() const
    {
        return m_time;
    }

    QList<QObject*> getPath() const
    {
        return m_path;
    }

    QString getLevel() const
    {
        return m_level;
    }

    bool getDone() const
    {
        return m_done;
    }

    QList<QObject*> getTrace() const
    {
        return m_trace;
    }

    QList<QObject*> getPhotos() const
    {
        return m_photos;
    }

signals:

    void labelChanged(QString label);
    void lengthChanged(QString length);
    void timeChanged(QString time);
    void pathChanged(QList<QObject*> path);
    void levelChanged(QString level);
    void doneChanged(bool done);
    void traceChanged(QList<QObject*> trace);


    void photosChanged(QList<QObject*> photos);

public slots:
    void setLabel(QString label)
    {
        if (m_label == label)
            return;

        m_label = label;
        emit labelChanged(m_label);
    }
    void setLength(QString length)
    {
        if (m_length == length)
            return;

        m_length = length;
        emit lengthChanged(m_length);
    }
    void setTime(QString time)
    {
        if (m_time == time)
            return;

        m_time = time;
        emit timeChanged(m_time);
    }

    void setPath(QList<QObject*> path)
    {
        if (m_path == path)
            return;

        m_path = path;
        emit pathChanged(m_path);
    }
    void setLevel(QString level)
    {
        if (m_level == level)
            return;

        m_level = level;
        emit levelChanged(m_level);
    }
    void setDone(bool done)
    {
        if (m_done == done)
            return;

        m_done = done;
        emit doneChanged(m_done);
    }

    void setTrace(QList<QObject*> trace)
    {
        if (m_trace == trace)
            return;

        m_trace = trace;
        emit traceChanged(m_trace);
    }

    void setPhotos(QList<QObject*> photos)
    {
        if (m_photos == photos)
            return;

        m_photos = photos;
        emit photosChanged(m_photos);
    }
};

#endif // TREK_H
