#ifndef MYCONTEXT_H
#define MYCONTEXT_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "filemanager.h"
#include "trek.h"
#include "user.h"
#include "utils.h"
#include "photo.h"
#include "httpserver.h"
#include "debugclass.h"

class Utils;

class MyContext : public QObject
{
    Q_OBJECT

/* trek manager */
    Q_PROPERTY(Trek* myTrek READ getMyTrek WRITE setMyTrek NOTIFY myTrekChanged)
    Q_PROPERTY(QList<QObject*> trekList READ getTrekList WRITE setTrekList NOTIFY trekListChanged)

/* photo manager */
    Q_PROPERTY(QString lastUrl READ getLastUrl WRITE setLastUrl NOTIFY lastUrlChanged)
    Q_PROPERTY(Photo* myPhoto READ getMyPhoto WRITE setMyPhoto NOTIFY myPhotoChanged)

/* user manager */
    Q_PROPERTY(User* user READ getUser WRITE setUser NOTIFY userChanged)

/* message manager */
    Q_PROPERTY(QString debugMessage READ debugMessage WRITE setDebugMessage NOTIFY debugMessageChanged) //for debugPage
    Q_PROPERTY(QString storageStatus READ storageStatus WRITE setStorageStatus NOTIFY storageStatusChanged)

/* debug manager */
    Q_PROPERTY(QStringList dbgInfos READ dbgInfos WRITE setDbgInfos NOTIFY dbgInfosChanged)

/* variables */
    QQmlContext* m_myContext;

    QList<QObject*> m_trekList;
    Trek* m_myTrek;

    Photo* m_myPhoto;
    QString m_lastUrl;

    User* m_user;

    QString m_debugMessage;
    QString m_storageStatus;
    QStringList m_dbgInfos;

public:

    explicit MyContext(QObject *parent = nullptr);

    void initMyContext(QQmlContext *myContext);
    void loadMyContext();
    void updateMyContext(QString modelName);

/* trek manager */
    Q_INVOKABLE void updateTrek (double const &latitude, double const &longitude);
    Q_INVOKABLE void startTrek (const QString &trekName, const double &latitude, const double &longitude, const QString &leafletTrace = "");

/* photo manager */
    Q_INVOKABLE void saveLastImageTakenUrl(const QString &path);
    Q_INVOKABLE void photoTaken(QString title, QString url, bool privatePhoto);

/* user manager */
    Q_INVOKABLE int getIdUser ();

/* save manager */
    Q_INVOKABLE void saveUser (const int &id, QString username, QString password, QString mail);
    Q_INVOKABLE void deleteUser ();
    Q_INVOKABLE void saveTrek();
    Q_INVOKABLE void deleteTrek();
    Q_INVOKABLE void testUploadPhoto();

/* debug manager */
    Q_INVOKABLE void debug(QString message);


/* Get & Set functions of Q_PROPERTIES */
/* *********************************** */

    Trek* getMyTrek() const
    {
        return m_myTrek;
    }

    QList<QObject*> getTrekList() const
    {
        return m_trekList;
    }

    Photo* getMyPhoto() const
    {
        return m_myPhoto;
    }

    QString getLastUrl() const
    {
        return m_lastUrl;
    }

    User* getUser() const
    {
        return m_user;
    }

    QString debugMessage() const
    {
        return m_debugMessage;
    }

    QString storageStatus() const
    {
        return m_storageStatus;
    }

    QStringList dbgInfos() const
    {
        return m_dbgInfos;
    }

signals:

    void myTrekChanged(Trek* myTrek);
    void trekListChanged(QList<QObject*> trekList);

    void myPhotoChanged(Photo* myPhoto);
    void lastUrlChanged(QString lastUrl);

    void userChanged(User* user);

    void debugMessageChanged(QString debugMessage);
    void storageStatusChanged(QString storageStatus);   

    void dbgInfosChanged(QStringList dbgInfos);

public slots:
    void valueChanged();

    void setMyTrek(Trek* myTrek)
    {
        if (m_myTrek == myTrek)
            return;

        m_myTrek = myTrek;
        emit myTrekChanged(m_myTrek);
    }

    void setTrekList(QList<QObject*> trekList)
    {
        if (m_trekList == trekList)
            return;

        m_trekList = trekList;
        emit trekListChanged(m_trekList);
    }

    void setMyPhoto(Photo* myPhoto)
    {
        if (m_myPhoto == myPhoto)
            return;

        m_myPhoto = myPhoto;
        emit myPhotoChanged(m_myPhoto);
    }
    void setLastUrl(QString lastUrl)
    {
        if (m_lastUrl == lastUrl)
            return;

        m_lastUrl = lastUrl;
        emit lastUrlChanged(m_lastUrl);
    }

    void setUser(User* user)
    {
        if (m_user == user)
            return;

        m_user = user;
        emit userChanged(m_user);
    }

    void setDebugMessage(QString debugMessage)
    {
        if (m_debugMessage == debugMessage)
            return;

        m_debugMessage = debugMessage;
        emit debugMessageChanged(m_debugMessage);
    }

    void setStorageStatus(QString storageStatus)
    {
        if (m_storageStatus == storageStatus)
            return;

        m_storageStatus = storageStatus;
        emit storageStatusChanged(m_storageStatus);
    }
    void setDbgInfos(QStringList dbgInfos)
    {
        if (m_dbgInfos == dbgInfos)
            return;

        m_dbgInfos = dbgInfos;
        emit dbgInfosChanged(m_dbgInfos);
    }
};

#endif // MYCONTEXT_H
