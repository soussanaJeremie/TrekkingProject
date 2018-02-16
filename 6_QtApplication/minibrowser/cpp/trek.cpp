#include "trek.h"


Trek::Trek(QObject *parent)
    : QObject(parent), m_label("trek_name"), m_length("1"), m_time("00:00:00"), m_path(), m_photos(), m_level("1"), m_done(1), m_trace()
{
    //      m_path = {new GpsPoint(43.462, 3.2527), new GpsPoint(43.462, 3.2527), new GpsPoint(43.463, 3.2528), new GpsPoint(43.464, 3.2529), new GpsPoint(43.466, 3.2530), new GpsPoint(43.462, 3.2527)};
}

Trek::Trek(const QString &label,  const double &latitude, const double &longitude, const QString &trace, QObject *parent)
    : QObject(parent), m_label(label), m_length("1"), m_time("00:00:00"), m_level("1"), m_done(1)
{
    m_path = {new GpsPoint( latitude, longitude )};
    m_trace = pathJSONToQList(trace)
}

Trek::Trek(const Trek &otherTrek, QObject *parent): QObject(parent)
{
    m_label = otherTrek.getLabel();
    m_length = otherTrek.getLength();
    m_time = otherTrek.getTime();
    m_path = otherTrek.getPath();
    m_photos = otherTrek.getPhotos();
    m_level = otherTrek.getLevel();
    m_done = otherTrek.getDone();
//    m_trace = otherTrek.getTrace();
}

QList<QObject *> Trek::pathJSONToQList(QString &pathData)
{
    QList<QObject *> path;
    QRegularExpression re ("[ a-z \":{}\\[\\] ]");
    pathData.remove(re);

    QStringList pathInQStringList = pathData.split(",");
    double lat(0.0);
    double lng(0.0);

    for (int i(0); i < pathInQStringList.length(); i++)
    {
        if (i == 0 || i%2 ==0)
        {
            lat = pathInQStringList[i].toDouble();
        }
        else
        {
            lng = pathInQStringList[i].toDouble();
            path.push_back(new GpsPoint(lat, lng));
            lat = 0.0;
            lng = 0.0;
        }
    }
    return path;
}

Trek::Trek(QStringList &trekData, QObject *parent): QObject(parent)
{
    QStringList datas = trekData[0].split(";");

    m_label = datas[0];
    m_length = datas[1];
    m_time = datas[2];
    m_path = pathJSONToQList(datas[3]);
    m_level = datas[4];
    m_done = true;
}

Trek::~Trek()
{
    while(m_path.length() != 0)
    {
        delete m_path.back();
        m_path.back() = nullptr;
        m_path.pop_back(); ;
        qDebug() << m_path.length();
    }

    while(m_trace.length() != 0)
    {
        delete m_trace.back();
        m_trace.back() = nullptr;
        m_trace.pop_back(); ;
        qDebug() << m_trace.length();
    }

    while(m_photos.length() != 0)
    {
        delete m_photos.back();
        m_photos.back() = nullptr;
        m_photos.pop_back();
        qDebug() << m_photos.length();
    }
}

void Trek::addNewGpsPoint(GpsPoint newGpsPoint)
{

    bool moving = ( !m_path.empty() ) && didUserMove(newGpsPoint);

    if( m_path.length() != 0 )
    {
        moving = didUserMove(newGpsPoint);
    }

    /* si test en mouvement */
    if ( m_path.empty() || moving )
    {
        //ab
        m_path.push_back( new GpsPoint(newGpsPoint) );
        emit pathChanged(m_path); // permet la mise à jour du QML
        // à tester

        //        QList<QObject*> tmp = getPath();
        //        tmp.push_back(new GpsPoint(newGpsPoint));
        qDebug() << "Added Gps Point lat:" << qobject_cast<GpsPoint*>(m_path.back())->getLatitude()
                 << ", lng:" << qobject_cast<GpsPoint*>(m_path.back())->getLongitude();
        //        setPath(tmp);
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
    QList<QObject*> tmp = getPhotos();
    tmp.push_back(new Photo(myPhoto));
    setPhotos(tmp);

    qDebug() << "Photo added, il y a " << m_photos.length() + 1;
    if( m_photos.length() == 0 )
        qDebug() << " photo";
    else qDebug() << " photos";
    qDebug() << " dans ce trek !";
}


QString Trek::pathSQLFormat()
{
    QString pathData;
    pathData += "{\"chemin\":[";

    for(int i(0); i < getPath().length(); i++)
    {
        GpsPoint tmp_point (*qobject_cast<GpsPoint*>(m_path[i]));
        pathData += tmp_point.gpsPointSQLFormat();

        if ( i < getPath().length()-1)
        {
            pathData += ",";
        }
        else
        {
            pathData += "]}";
        }
    }
    return pathData;
}

QStringList Trek::trekSQLFormat()
{
    QStringList trekData;

    trekData << getLabel()
             << getLength()
             << getTime()
             << pathSQLFormat()
             << getLevel()
             << "1";
    //            + // 1 to indicate the trek is done. (done == true)
    //            pathSQLFormat();

    return trekData;
}


