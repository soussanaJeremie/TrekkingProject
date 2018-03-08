#include "filemanager.h"


QString FileManager::m_basePath = QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation)[0];

FileManager::FileManager()
{
}

void FileManager::initFolder()
{
    QDir dir(m_basePath);
    QDir storage(m_basePath + "minibrowser/storage");

    if (!storage.exists())
    {
        dir.mkdir("storage");
    }

    m_basePath += "/minibrowser/storage/";
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
        DebugClass::getInstance()->saveDebugMsg("Error", "cannot open file: " + fileUrl);
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
        DebugClass::getInstance()->saveDebugMsg("Error", "cannot open file: " + fileUrl);
    }

    else {
        QTextStream writeStream( &fileToUpdate );
        writeStream.setCodec("UTF-8");
        writeStream << endl << dataLine;

        if(!fileUrl.contains("debug_log"))
        {
            DebugClass::getInstance()->saveDebugMsg("Success", "Saved Line in : " + fileUrl);
        }
    }
}

void FileManager::deleteFile( const QString &fileType, const QString &fileName )
{
    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile fileToDelete (fileUrl);

    if(fileToDelete.remove())
    {
        DebugClass::getInstance()->saveDebugMsg("Success", fileUrl + " was deleted");
    }
    else
    {
        DebugClass::getInstance()->saveDebugMsg("Error", fileUrl + " could not be deleted");
    }
}

void FileManager::saveInFile(const QString &fileType, const QString &fileName, const QStringList &data)
{
    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile fileToUpdate (fileUrl);

    if (!fileToUpdate.open(QIODevice::WriteOnly | QIODevice::Text)) {
        DebugClass::getInstance()->saveDebugMsg("Error", "cannot open file: " + fileUrl);
    }

    else {
        QTextStream writeStream( &fileToUpdate );
        writeStream.setCodec("UTF-8");

        for (QString dataLine : data)
        {
            writeStream << dataLine << ";" ;
        }
        DebugClass::getInstance()->saveDebugMsg("Success", fileUrl + " was append");
    }
}

QString FileManager::readFile(const QString &fileType, const QString &fileName)
{
    QString datas;

    QString fileUrl = m_basePath + fileType + "_" + fileName + ".txt";
    QFile fileToRead (fileUrl);

    if (!fileToRead.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        DebugClass::getInstance()->saveDebugMsg("Error", fileUrl + " could not be deleted");
    }
    else
    {
        QTextStream readingStream(&fileToRead);
        readingStream.setCodec("UTF-8");
        while (!readingStream.atEnd())
        {
            datas += readingStream.readLine() + '\r';
        }
        fileToRead.close();
    }
    return datas;
}

