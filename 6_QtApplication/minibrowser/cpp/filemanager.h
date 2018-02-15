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


class FileManager : public QObject
{
    Q_OBJECT

    QString m_basePath;

public:
    explicit FileManager ( QObject *parent = nullptr );

    void initFolder();
    bool fileExists( const QString &fileType, const QString &fileName );
    QStringList loadFile( const QString &fileType, const QString &fileName );
//    void addLine( const QString &fileType, const QString &fileName, const QString &dataLine );
    void saveFile( const QString &fileType, const QString &fileName, const QStringList &data );
    void deleteFile( const QString &fileType, const QString &fileName );


    QString getBasePath() const
    {
        return m_basePath;
    }
    void setBasePath( const QString &basePath )
    {
        m_basePath = basePath;
    }

signals:


public slots:


};

#endif // FILEMANAGER_H
