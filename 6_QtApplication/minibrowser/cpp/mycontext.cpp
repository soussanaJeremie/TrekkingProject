#include "mycontext.h"
#include <QDebug>

/////////////////////////////////////////////////////////////////////////////
/// Initialisation
/////////////////////////////////////////////////////////////////////////////

MyContext::MyContext(QObject *parent) : QObject(parent), m_myContext(nullptr)
{
    m_myTrek = new Trek;

    //initialisation des messages d'erreurs
    setErrorMessage("");
    setWellDoneMessage("");
    setStorageStatus("");

    //Initialisation des fichiers de sauvegarde
    FileManager::initFolder();

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
        //        m_myTrek = new Trek( "trek_trek_trek", 0.0 , 0.0);
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

/////////////////////////////////////////////////////////////////////////////
/// Trek Manager
/////////////////////////////////////////////////////////////////////////////

void MyContext::updateTrek(const double &latitude, const double &longitude)
{
    m_myTrek->addNewGpsPoint(GpsPoint(latitude, longitude));

    //    m_myContext->setContextProperty("MyContext", this);
}

void MyContext::startTrek(const QString &trekName,const double &latitude, const double &longitude, const QString &leafletTrace)
{
    delete m_myTrek;
    m_myTrek = nullptr;
    setMyTrek(new Trek (trekName, latitude, longitude, leafletTrace));
    //    setMyTrek(new Trek());

    qDebug() << " # " << trekName;
    qDebug() << "New Trek Created";
    setWellDoneMessage(m_wellDoneMessage + "/nNew Trek created");
}


/////////////////////////////////////////////////////////////////////////////
/// Photos Manager
/////////////////////////////////////////////////////////////////////////////

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
    User* currentUser = new User;
    currentUser->setIdUser(id);
    currentUser->setUsername(username.remove("\""));
    currentUser->setPassword(password.remove("\""));
    currentUser->setEmail(mail.remove("\""));

    setUser(currentUser);
    setWellDoneMessage(m_wellDoneMessage + "\nUser " + username + " saved");


    QStringList userData = getUser()->userSQLFormat();
    //    FileManager::saveFile("user", "info", userData);
    FileManager::saveInFile("user", "info", userData);

    delete currentUser;
    currentUser = nullptr;
}

void MyContext::deleteUser()
{
    FileManager::deleteFile("user", "info");
}


void MyContext::saveTrek()
{
    //    QString trekName = getMyTrek()->getLabel().replace(" ", "_");
    QStringList trekData = getMyTrek()->trekSQLFormat();

    //    FileManager::saveFile("trek", trekName , trekData);
    FileManager::saveInFile("trek", "detail", trekData);
}

void MyContext::deleteTrek()
{
    //    QString trekName = getMyTrek()->getLabel().replace(" ", "_");
    //    FileManager::deleteFile("trek", trekName);
    FileManager::deleteFile("trek", "detail");

    delete m_myTrek;
    m_myTrek = nullptr;
}



/* NEW FUNCTIONS */

void MyContext::testUploadPhoto()
{
    HttpServer::post("C:/Users/34011-58-03/Pictures/panda.jpg", "petitPanda");
}
