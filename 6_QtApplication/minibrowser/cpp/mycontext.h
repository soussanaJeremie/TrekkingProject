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

/* save manager */
    Q_PROPERTY(FileManager* fileManager READ getFileManager WRITE setFileManager NOTIFY fileManagerChanged)

/* message manager */
    Q_PROPERTY(QString errorMessage READ errorMessage WRITE setErrorMessage NOTIFY errorMessageChanged) //for debugPage
    Q_PROPERTY(QString wellDoneMessage READ wellDoneMessage WRITE setWellDoneMessage NOTIFY wellDoneMessageChanged) //for debugPage

    Q_PROPERTY(QString storageStatus READ storageStatus WRITE setStorageStatus NOTIFY storageStatusChanged)


/* variables */
    QQmlContext* m_myContext;

    QList<QObject*> m_trekList;
    Trek* m_myTrek;

    Photo* m_myPhoto;
    QString m_lastUrl;

    User* m_user;

    FileManager* m_fileManager;

    QString m_errorMessage;
    QString m_wellDoneMessage;
    QString m_storageStatus;


public:

    explicit MyContext(QObject *parent = nullptr);

    void initMyContext(QQmlContext *myContext);
    void loadMyContext();
    void updateMyContext(QString modelName);

/* trek manager */
    Q_INVOKABLE void updateTrek (double const &latitude, double const &longitude);
    Q_INVOKABLE void startTrek (const QString &trekName, const double &latitude, const double &longitude);

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

    FileManager* getFileManager() const
    {
        return m_fileManager;
    }

    QString errorMessage() const
    {
        return m_errorMessage;
    }

    QString wellDoneMessage() const
    {
        return m_wellDoneMessage;
    }

    QString storageStatus() const
    {
        return m_storageStatus;
    }

signals:

    void myTrekChanged(Trek* myTrek);
    void trekListChanged(QList<QObject*> trekList);

    void myPhotoChanged(Photo* myPhoto);
    void lastUrlChanged(QString lastUrl);

    void userChanged(User* user);

    void fileManagerChanged(FileManager* fileManager);

    void errorMessageChanged(QString errorMessage);
    void wellDoneMessageChanged(QString wellDoneMessage);
    void storageStatusChanged(QString storageStatus);   

public slots:

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

    void setFileManager(FileManager* fileManager)
    {
        if (m_fileManager == fileManager)
            return;

        m_fileManager = fileManager;
        emit fileManagerChanged(m_fileManager);
    }

    void setErrorMessage(QString errorMessage)
    {
        if (m_errorMessage == errorMessage)
            return;

        m_errorMessage = errorMessage;
        emit errorMessageChanged(m_errorMessage);
    }

    void setWellDoneMessage(QString wellDoneMessage)
    {
        if (m_wellDoneMessage == wellDoneMessage)
            return;

        m_wellDoneMessage = wellDoneMessage;
        emit wellDoneMessageChanged(m_wellDoneMessage);
    }

    void setStorageStatus(QString storageStatus)
    {
        if (m_storageStatus == storageStatus)
            return;

        m_storageStatus = storageStatus;
        emit storageStatusChanged(m_storageStatus);
    }
};

#endif // MYCONTEXT_H
