#include "user.h"

User::User(QObject *parent) : QObject(parent)
{
    m_idUser = 0;
    m_username = "";
    m_password = "";
    m_email = "";
}

User::User(const int &idUser, const QString &username, const QString &password,
           const QString &email, QObject *parent):
    m_idUser(idUser), m_username(username), m_password(password),
    m_email(email), QObject(parent)
{

}

User::User( QStringList &userData, QObject *parent): QObject(parent)
{
    if (userData.length() == 4)
    {
        m_idUser = userData[0].toInt();
        m_username = userData[1];
        m_password = userData[2];
        m_email = userData[3];
    }
}

QStringList User::userSQLFormat()
{
    QStringList userData;

    userData << QString::number(getIdUser())
            << getUsername()
            << getPassword()
            << getEmail();

    return userData;
}

