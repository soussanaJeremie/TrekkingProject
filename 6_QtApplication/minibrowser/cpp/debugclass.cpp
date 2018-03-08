#include "debugclass.h"


DebugClass::DebugClass(QObject *parent) : QObject(parent)
{
    m_debugMsg = QString("");
    m_infosDebug << "";
}

void DebugClass::saveDebugMsg(QString type, QString message)
{
    m_debugMsg = (QDateTime::currentDateTime().toString("dd/MM/yy hh:mm")) + "-" + type + "-" + message;

    FileManager::addLine("debug", "log", m_debugMsg);
    m_infosDebug << m_debugMsg;

    emit valueChanged();
}
