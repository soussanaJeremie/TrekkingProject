#include "filemanager.h"


QString FileManager::m_basePath = QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation)[0];

FileManager::FileManager()
{
}

void FileManager::initFolder()
{
    // verif dossier de sauvegarde.exists() et cree au cas ou

    QDir dir(m_basePath);
    QDir storage(m_basePath + "minibrowser/storage");

    if (!storage.exists())
    {
        qDebug() << "no directory";
        dir.mkdir("storage");
    }
    m_basePath += "/minibrowser/storage/";

    QString test = m_basePath;
    qDebug() << "#test" << test;
}

bool FileManager::fileExists( const QString &fileType, const QString &fileName )
{
    QStringList data = loadFile(fileType, fileName);
    return !data.empty();
}

QStringList FileManager::loadFile( const QString &fileType, const QString &fileName )
{
    QStringList data;

    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile storedFile(fileUrl);

    if (!storedFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "cannot open file:" << fileUrl;
    }

    else
    {
        QTextStream readingStream(&storedFile);
        readingStream.setCodec("UTF-8");
        while (!readingStream.atEnd())
        {
            data << readingStream.readLine();
        }
        storedFile.close();
    }
    return data;
}

void FileManager::addLine( const QString &fileType, const QString &fileName, const QString &dataLine)
{
    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile fileToUpdate (fileUrl);

    if (!fileToUpdate.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        qDebug() << "Ouverture Impossible" << fileUrl << "n'a pas pu être ouvert";
    }

    else {
        QTextStream writeStream( &fileToUpdate );
        writeStream.setCodec("UTF-8");
        writeStream << endl << dataLine;

        qDebug() << "Saved Line in :" << fileUrl;
    }
}

//void FileManager::saveFile(const QString &fileType, const QString &fileName, const QStringList &data)
//{
//    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
//    QFile fileToUpdate (fileUrl);

//    if (!fileToUpdate.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        qDebug() << "Ouverture Impossible" << fileUrl << "n'a pas pu être ouvert";
//    }

//    else {
//        QTextStream writeStream( &fileToUpdate );
//        writeStream.setCodec("UTF-8");

//        for (QString dataLine : data)
//        {
//            writeStream << dataLine << endl;
//        }
//        qDebug() << "Saved Line in :" << fileUrl;
//    }
//}

void FileManager::deleteFile( const QString &fileType, const QString &fileName )
{
    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile fileToDelete (fileUrl);

    if(fileToDelete.remove())
    {
        qDebug() << fileUrl + " was deleted";
    }
    else
    {
        qDebug() << fileUrl + " could not be deleted";
    }
}

void FileManager::saveInFile(const QString &fileType, const QString &fileName, const QStringList &data)
{
    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile fileToUpdate (fileUrl);

    if (!fileToUpdate.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ouverture Impossible" << fileUrl << "n'a pas pu être ouvert";
    }

    else {
        QTextStream writeStream( &fileToUpdate );
        writeStream.setCodec("UTF-8");

        for (QString dataLine : data)
        {
            writeStream << dataLine << ";" ;
        }
        qDebug() << "Saved Line in :" << fileUrl;
    }
}

