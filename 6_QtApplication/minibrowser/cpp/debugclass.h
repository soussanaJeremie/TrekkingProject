#ifndef DEBUGCLASS_H
#define DEBUGCLASS_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QDateTime>

#include "filemanager.h"


class DebugClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList infosDebug READ infosDebug WRITE setInfosDebug NOTIFY infosDebugChanged)

public:

    explicit DebugClass(QObject *parent = 0);

    static DebugClass *getInstance() {
        if(nullptr == _singleton) {
            _singleton = new DebugClass;
        }
        return _singleton;
    }

    void saveDebugMsg(QString type, QString message);

    QStringList infosDebug() const
    {
        return m_infosDebug;
    }

public slots:

    void setInfosDebug(QStringList infosDebug)
    {
        if (m_infosDebug == infosDebug)
            return;

        m_infosDebug = infosDebug;
        emit infosDebugChanged(m_infosDebug);
    }

signals:

    void infosDebugChanged(QStringList infosDebug);
    void valueChanged();

private:
    static DebugClass *_singleton;

    QString m_debugMsg;
    QStringList m_infosDebug;
};

#endif // DEBUGCLASS_H
