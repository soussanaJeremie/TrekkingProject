#include "trek.h"


Trek::Trek(QObject *parent) : QObject(parent)
{
    m_label = "trek_name";
    m_length = "1";
    m_time = "00:00:00";
    m_path = {};
    //  m_path = {new GpsPoint(43.462, 3.2527), new GpsPoint(43.462, 3.2527), new GpsPoint(43.463, 3.2528), new GpsPoint(43.464, 3.2529), new GpsPoint(43.466, 3.2530), new GpsPoint(43.462, 3.2527)};
    m_trace = {};
    m_photos = {};
    m_level = "1";
    m_done = 1;
}

Trek::Trek(const QString &label,  const double &latitude, const double &longitude, QObject *parent): m_label(label), QObject(parent)
{
    m_length = "1";
    m_time = "00:00:00";
    m_path = {new GpsPoint( latitude, longitude )};
    m_trace = {};
    m_photos = {};
    m_level = "1";
    m_done = 1;
}

Trek::Trek(const Trek &otherTrek, QObject *parent): QObject(parent)
{
    m_label = otherTrek.getLabel();
    m_length = otherTrek.getLength();
    m_time = otherTrek.getTime();
    m_path = otherTrek.getPath();
    m_trace = otherTrek.getTrace();
    m_photos = otherTrek.getPhotos();
    m_level = otherTrek.getLevel();
    m_done = otherTrek.getDone();
}

Trek::~Trek()
{
    while(m_path.length() != 0)
    {
        m_path.back() = nullptr;
        delete m_path.back();
        m_path.pop_back(); ;
        qDebug() << m_path.length();
    }

    while(m_trace.length() != 0)
    {
        m_trace.back() = nullptr;
        delete m_trace.back();
        m_trace.pop_back(); ;
        qDebug() << m_trace.length();
    }

    while(m_photos.length() != 0)
    {
        m_photos.back() = nullptr;
        delete m_photos.back();
        m_photos.pop_back();
        qDebug() << m_photos.length();
    }
}

void Trek::addNewGpsPoint(GpsPoint newGpsPoint)
{

    bool moving = (m_path.length() != 0) && didUserMove(newGpsPoint);

    if( m_path.length() != 0 )
    {
        moving = didUserMove(newGpsPoint);
    }

    /* si test en mouvement */
    if ( m_path.length() == 0 || moving )
    {
        QList<QObject*> tmp = getPath();
        tmp.push_back(new GpsPoint(newGpsPoint));
        qDebug() << "Added Gps Point lat:" << qobject_cast<GpsPoint*>(m_path.back())->getLatitude()
                 << ", lng:" << qobject_cast<GpsPoint*>(m_path.back())->getLongitude();
        setPath(tmp);
    }

    else
    {
        qDebug() << "User is not moving";
    }
}

bool Trek::didUserMove(GpsPoint &newGpsPoint)
{
    return newGpsPoint.userMoved(*qobject_cast<GpsPoint*>(m_path.back()));
}

void Trek::addPhoto(Photo* myPhoto)
{
    QObjectList tmp = getPhotos();
    tmp.push_back(new Photo(myPhoto));
    setPhotos(tmp);

    qDebug() << "Photo added, il y a " << m_photos.length() + 1;
    if( m_photos.length() == 0 )
        qDebug() << " photo";
    else qDebug() << " photos";
    qDebug() << " dans ce trek !";
}
