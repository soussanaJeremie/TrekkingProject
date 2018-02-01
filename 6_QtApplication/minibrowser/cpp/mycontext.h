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


// Faut peut-etre appeler la classe Utils une fois

class Utils;

class MyContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Trek* myTrek READ getMyTrek WRITE setMyTrek NOTIFY myTrekChanged)
    Q_PROPERTY(QList<QObject*> trekList READ getTrekList WRITE setTrekList NOTIFY trekListChanged)
    Q_PROPERTY(User* user READ getUser WRITE setUser NOTIFY userChanged)
    Q_PROPERTY(FileManager* fileManager READ getFileManager WRITE setFileManager NOTIFY fileManagerChanged)

    Q_PROPERTY(QString errorMessage READ errorMessage WRITE setErrorMessage NOTIFY errorMessageChanged)


    QQmlContext* m_myContext;

    /* variables */
    FileManager* m_fileManager;
    QList<QObject*> m_trekList;
    User* m_user;
    Trek* m_myTrek;

    QString m_errorMessage;


    // File Searching Functions
    void searchUserFile();
    void searchTrekFile();
    void searchPhotoFile();


public:

    explicit MyContext(QObject *parent = nullptr);

    void initMyContext(QQmlContext *myContext);
    void loadMyContext();
    void updateMyContext(QString modelName);


    QString truncateUrl(const QString &url);

    Q_INVOKABLE void sendActionToCpp (QString nomAction, QString parameter = QString (""), QString parameter2 = QString ("") );

    Q_INVOKABLE void updateTrek (double const &latitude, double const &longitude);
    Q_INVOKABLE void startTrek (const QString &trekName, const double &latitude, const double &longitude);

    Q_INVOKABLE void saveUser (const int &id, QString username, QString password, QString mail);
    Q_INVOKABLE void deleteUser ();

    Q_INVOKABLE int getIdUser ();


    Trek* getMyTrek() const
    {
        return m_myTrek;
    }

    QString errorMessage() const
    {
        return m_errorMessage;
    }


    QList<QObject*> getTrekList() const
    {
        return m_trekList;
    }

    User* getUser() const
    {
        return m_user;
    }

    FileManager* getFileManager() const
    {
        return m_fileManager;
    }

signals:

    void myTrekChanged(Trek* myTrek);
    void errorMessageChanged(QString errorMessage);
    void trekListChanged(QList<QObject*> trekList);
    void userChanged(User* user);
    void fileManagerChanged(FileManager* fileManager);

public slots:

    void setMyTrek(Trek* myTrek)
    {
        if (m_myTrek == myTrek)
            return;

        m_myTrek = myTrek;
        emit myTrekChanged(m_myTrek);
    }

    void setErrorMessage(QString errorMessage)
    {
        if (m_errorMessage == errorMessage)
            return;

        m_errorMessage = errorMessage;
        emit errorMessageChanged(m_errorMessage);
    }

    void setTrekList(QList<QObject*> trekList)
    {
        if (m_trekList == trekList)
            return;

        m_trekList = trekList;
        emit trekListChanged(m_trekList);
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
};

#endif // MYCONTEXT_H
