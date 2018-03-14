#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QStringList>
#include <iostream>
#include <QString>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStandardPaths>
#include <QObject>


class FileManager
{

public:
    FileManager();

    static void initFolder();
    static bool fileExists( const QString &fileType, const QString &fileName );
    static QStringList loadFile( const QString &fileType, const QString &fileName );
    static void addLine( const QString &fileType, const QString &fileName, const QString &dataLine );
//    static void saveFile( const QString &fileType, const QString &fileName, const QStringList &data );
    static void deleteFile( const QString &fileType, const QString &fileName );

    static void saveInFile (const QString &fileType, const QString &fileName, const QStringList &data);

private:
    static QString m_basePath;

};

#endif // FILEMANAGER_H
