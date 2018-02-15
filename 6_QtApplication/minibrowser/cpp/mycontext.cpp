#include "mycontext.h"
#include <QDebug>


MyContext::MyContext(QObject *parent) : QObject(parent), m_myContext(nullptr)
{
    m_fileManager = new FileManager;
    m_myTrek = new Trek;

    if(m_fileManager->fileExists("user", "info"))
    {
        QStringList userData = m_fileManager->loadFile("user", "info");
        m_user = new User(userData);
    }

    else
    {
        m_user = new User;
    }

    if(m_fileManager->fileExists("trek", "detail"))
    {
        QStringList trekData = m_fileManager->loadFile("trek", "detail");
        m_myTrek = new Trek(trekData);
    }
    else
    {
//        m_myTrek = new Trek( "trek_trek_trek", 0.0 , 0.0);
        m_myTrek = new Trek();
    }

    setErrorMessage("");


}

void MyContext::initMyContext(/*QQmlApplicationEngine &engine,*/ QQmlContext *myContext)
{
    m_myContext = myContext;

    QString initialUrl = QStringLiteral("localhost:3000");

    //    m_myContext->setContextProperty(QStringLiteral("utils"), new Utils(&engine));
    m_myContext->setContextProperty(QStringLiteral("initialUrl"),
                                    Utils::fromUserInput(initialUrl));
    m_myContext->setContextProperty("MyContext", this);
}


// Fonction to update the QML
void MyContext::loadMyContext()
{
    // Send the data to Qml
    if( m_myContext != nullptr )
    {
        m_myContext->setContextProperty("trekList", QVariant::fromValue( m_trekList ));
    }
    else
    {
        qDebug() << "Context has not been instantiated";
    }
}


void MyContext::updateTrek(const double &latitude, const double &longitude)
{
    m_myTrek->addNewGpsPoint(GpsPoint(latitude, longitude));

    //    m_myContext->setContextProperty("MyContext", this);
}

void MyContext::startTrek(const QString &trekName,const double &latitude, const double &longitude)
{
    delete m_myTrek;
    m_myTrek = nullptr;
    setMyTrek(new Trek (trekName, latitude, longitude));
//    setMyTrek(new Trek());

    qDebug() << " # " << trekName;
    qDebug() << "New Trek Created";
    setErrorMessage(m_errorMessage + "/nNew Trek created");
}

void MyContext::saveLastImageTakenUrl(const QString &path)
{
    setLastUrl(path);
    qDebug() << "url = " + m_lastUrl;
}

void MyContext::photoTaken(QString title, QString url, bool privatePhoto)
{
    url = m_lastUrl;

    Photo *photo = nullptr;
    photo = new Photo(title, url, privatePhoto);
    photo->showPhotoData(photo);

    setMyPhoto(photo);
    m_myTrek->addPhoto(m_myPhoto);
}

void MyContext::saveUser(const int &id,  QString username,  QString password,  QString mail)
{
    User* currentUser = new User;
    currentUser->setIdUser(id);
    currentUser->setUsername(username.remove("\""));
    currentUser->setPassword(password.remove("\""));
    currentUser->setEmail(mail.remove("\""));

    setUser(currentUser);

    //qDebug() << getUser()->getIdUser();

    QStringList userData = getUser()->userSQLFormat();
    getFileManager()->saveFile("user", "info", userData);


    delete currentUser;
    currentUser = nullptr;
}

void MyContext::deleteUser()
{

    getFileManager()->deleteFile("user", "info");
}

void MyContext::saveTrek()
{
//    QString trekName = getMyTrek()->getLabel().replace(" ", "_");
    QStringList trekData = getMyTrek()->trekSQLFormat();

//    m_fileManager->saveFile("trek", trekName , trekData);
    m_fileManager->saveFile("trek", "detail", trekData);
}

void MyContext::deleteTrek()
{
//    QString trekName = getMyTrek()->getLabel().replace(" ", "_");
//    getFileManager()->deleteFile("trek", trekName);
    getFileManager()->deleteFile("trek", "detail");

    delete m_myTrek;
    m_myTrek = nullptr;
}

int MyContext::getIdUser()
{
    return getUser()->getIdUser();
}
