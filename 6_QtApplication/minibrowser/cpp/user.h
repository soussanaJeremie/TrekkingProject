#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>
#include <QStringList>

class User : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int idUser READ getIdUser WRITE setIdUser NOTIFY idUserChanged)
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString email READ getEmail WRITE setEmail NOTIFY emailChanged)

    int m_idUser;
    QString m_username;
    QString m_password;
    QString m_email;

public:
    explicit User(QObject *parent = nullptr);

    User(   const int &idUser, const QString &username, const QString &password,
            const QString &email, QObject *parent = nullptr );
    User(  QStringList &userData, QObject *parent = nullptr );

    QStringList userSQLFormat();


    //////////////////////////
    /// GETTERS AND SETTERS///
    //////////////////////////

    int getIdUser() const
    {
        return m_idUser;
    }

    QString getUsername() const
    {
        return m_username;
    }

    QString getPassword() const
    {
        return m_password;
    }

    QString getEmail() const
    {
        return m_email;
    }


signals:

    void idUserChanged(int idUser);

    void usernameChanged(QString username);

    void passwordChanged(QString password);

    void emailChanged(QString email);


public slots:

    void setIdUser(int idUser)
    {
        if (m_idUser == idUser)
            return;

        m_idUser = idUser;
        emit idUserChanged(m_idUser);
    }
    void setUsername(QString username)
    {
        if (m_username == username)
            return;

        m_username = username;
        emit usernameChanged(m_username);
    }
    void setPassword(QString password)
    {
        if (m_password == password)
            return;

        m_password = password;
        emit passwordChanged(m_password);
    }
    void setEmail(QString email)
    {
        if (m_email == email)
            return;

        m_email = email;
        emit emailChanged(m_email);
    }
};

#endif // USER_H
