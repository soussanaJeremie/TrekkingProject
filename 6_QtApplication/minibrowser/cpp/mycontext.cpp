#include "mycontext.h"
#include <QDebug>

/////////////////////////////////////////////////////////////////////////////
/// Initialisation
/////////////////////////////////////////////////////////////////////////////

MyContext::MyContext(QObject *parent) : QObject(parent), m_myContext(nullptr)
{
    QObject::connect(DebugClass::getInstance(), &DebugClass::valueChanged , this, &MyContext::valueChanged );

    m_myTrek = new Trek;

    //initialisation des messages d'erreurs
    setDebugMessage("");
    setStorageStatus("");

    //Initialisation des fichiers de sauvegarde
    FileManager::initFolder();

    if(FileManager::fileExists("debug", "log"))
    {
        FileManager::deleteFile("debug", "log");
    }

    if(FileManager::fileExists("user", "info"))
    {
        QStringList userData = FileManager::loadFile("user", "info");
        m_user = new User(userData);
    }

    else
    {
        m_user = new User;
    }

    if(FileManager::fileExists("trek", "detail"))
    {
        QStringList trekData = FileManager::loadFile("trek", "detail");
        m_myTrek = new Trek(trekData);
        setStorageStatus("Un trek n'a pas été sauvegardé sur le serveur");
    }
    else
    {
        m_myTrek = new Trek();
    }

    if(FileManager::fileExists("photos", "detail"))
    {
        setStorageStatus(storageStatus() + "\nDes photos n'ont pas été sauvegardées sur le serveur");
    }
}

void MyContext::initMyContext(/*QQmlApplicationEngine &engine,*/ QQmlContext *myContext)
{
    m_myContext = myContext;

    QString initialUrl = QStringLiteral("localhost:3000");

    m_myContext->setContextProperty(QStringLiteral("initialUrl"), Utils::fromUserInput(initialUrl));
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
        DebugClass::getInstance()->saveDebugMsg("Error", "Context has not been instantiated");
    }
}

/////////////////////////////////////////////////////////////////////////////
/// Trek Manager
/////////////////////////////////////////////////////////////////////////////

void MyContext::updateTrek(const double &latitude, const double &longitude)
{
    m_myTrek->addNewGpsPoint(GpsPoint(latitude, longitude));
}

void MyContext::startTrek(const QString &trekName,const double &latitude, const double &longitude, const QString &leafletTrace)
{
    delete m_myTrek;
    m_myTrek = nullptr;
    setMyTrek(new Trek (trekName, latitude, longitude, leafletTrace));

    DebugClass::getInstance()->saveDebugMsg("Success", "New Trek created with name " + trekName);
}


/////////////////////////////////////////////////////////////////////////////
/// Photos Manager
/////////////////////////////////////////////////////////////////////////////

void MyContext::saveLastImageTakenUrl(const QString &path)
{
    setLastUrl(path);

    DebugClass::getInstance()->saveDebugMsg("Success", "Photo saved at url " +  m_lastUrl);
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

/////////////////////////////////////////////////////////////////////////////
/// User Manager
/////////////////////////////////////////////////////////////////////////////

int MyContext::getIdUser()
{
    return getUser()->getIdUser();
}

/////////////////////////////////////////////////////////////////////////////
/// Save Manager
/////////////////////////////////////////////////////////////////////////////

void MyContext::saveUser(const int &id,  QString username,  QString password,  QString mail)
{
    m_user->setIdUser(id);
    m_user->setUsername(username.remove("\""));
    m_user->setPassword(password.remove("\""));
    m_user->setEmail(mail.remove("\""));

    DebugClass::getInstance()->saveDebugMsg("Success", "User " + username + " saved");

    QStringList userData = getUser()->userSQLFormat();
    FileManager::saveInFile("user", "info", userData);
}

void MyContext::deleteUser()
{
    FileManager::deleteFile("user", "info");
    m_user->setIdUser(0);
    m_user->setUsername("");
    m_user->setPassword("");
    m_user->setEmail("");
}

void MyContext::saveTrek()
{
    QStringList trekData = getMyTrek()->trekSQLFormat();
    FileManager::saveInFile("trek", "detail", trekData);
}

void MyContext::deleteTrek()
{
    FileManager::deleteFile("trek", "detail");

    delete m_myTrek;
    m_myTrek = nullptr;
}



/* NEW FUNCTIONS */

void MyContext::testUploadPhoto()
{
    HttpServer::post("C:/Users/34011-58-03/Pictures/panda.jpg", "petitPanda");
}

void MyContext::debug(QString message)
{
    DebugClass::getInstance()->saveDebugMsg("QML", message);
}

void MyContext::valueChanged()
{
    setDbgInfos( DebugClass::getInstance()->infosDebug() );
}

