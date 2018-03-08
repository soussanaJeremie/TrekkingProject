#include "gpspoint.h"

GpsPoint::GpsPoint(QObject *parent) : QObject(parent)
{
    m_latitude = 0.0;
    m_longitude = 0.0;
}

GpsPoint::GpsPoint(const double &latitude, const double &longtitude, QObject *parent)
    : QObject(parent), m_latitude(latitude), m_longitude(longtitude)
{}

GpsPoint::GpsPoint(const GpsPoint &aGpsPoint,  QObject *parent): QObject(parent)
{
    m_latitude = aGpsPoint.m_latitude;
    m_longitude = aGpsPoint.m_longitude;
}

QString GpsPoint::gpsPointSQLFormat()
{
    QString gpsData ("");

    gpsData +=   "{\"lat\": \"" + QString::number(getLatitude())
            +   "\", \"lng\": \"" + QString::number(getLongitude())
            +   "\"}";

    return gpsData;
}

bool GpsPoint::userMoved(const GpsPoint &previousGpsPoint)
{
    double rayon = pow((getLatitude() - previousGpsPoint.getLatitude()) , 2) +
                    pow((getLongitude() - previousGpsPoint.getLongitude()) , 2) ;

    return rayon > 10e-9;
}
