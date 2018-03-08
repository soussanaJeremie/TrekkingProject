#include "trek.h"
#include "debugclass.h"


Trek::Trek(QObject *parent)
    : QObject(parent), m_label("trek_name"), m_length("1"), m_time("00:00:00"), m_path(), m_photos(), m_level("1"), m_done(1), m_trace()
{
}

Trek::Trek(const QString &label,  const double &latitude, const double &longitude, const QString &trace, QObject *parent)
    : QObject(parent), m_label(label), m_length("1"), m_time("00:00:00"), m_level("1"), m_done(1)
{
    m_path = {new GpsPoint( latitude, longitude )};
    QString traceCopy = trace;
    m_trace = pathJSONToQList(traceCopy);
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
    m_trace = otherTrek.getTrace();
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
    m_trace = pathJSONToQList(datas[6]);
}

Trek::~Trek()
{
    while(m_path.length() != 0)
    {
        delete m_path.back();
        m_path.back() = nullptr;
        m_path.pop_back(); ;
        DebugClass::getInstance()->saveDebugMsg( "Info", "pathLength : " + m_path.length());
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


///////////////////////////
/// MOVEMENT MONITORING
///////////////////////////

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
        emit pathChanged(m_path);

        DebugClass::getInstance()->saveDebugMsg("Info", "Added Gps Point lat:"
                                                + QString::number(qobject_cast<GpsPoint*>(m_path.back())->getLatitude())
                                                + ", lng:"
                                                + QString::number(qobject_cast<GpsPoint*>(m_path.back())->getLongitude())
                                                );
    }
    else
    {
        DebugClass::getInstance()->saveDebugMsg("Error", "User is not moving");
    }
}

bool Trek::didUserMove(GpsPoint &newGpsPoint)
{
    return newGpsPoint.userMoved(*qobject_cast<GpsPoint*>(m_path.back()));
}

///////////////////////////
/// PHOTO RECORDING
///////////////////////////

void Trek::addPhoto(Photo* myPhoto)
{
    QList<QObject*> tmp = getPhotos();
    tmp.push_back(new Photo(myPhoto));
    setPhotos(tmp);

    DebugClass::getInstance()->saveDebugMsg("Success", "Photo added");
}

/////////////////////////////
/// SAVE & LOAD FUNCTIONS
/////////////////////////////


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


QString Trek::pathSQLFormat(QString pathType)
{
    QString pathData;
    QList<QObject*> path;

    if (pathType == "path")
    {
        path = getPath();
    }
    else if (pathType == "trace")
    {
        path = getTrace();
    }

    pathData += "{\"chemin\":[";

    for(int i(0); i < path.length(); i++)
    {
        GpsPoint tmp_point (*qobject_cast<GpsPoint*>(path[i]));
        pathData += tmp_point.gpsPointSQLFormat();

        if ( i < path.length()-1)
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
             << pathSQLFormat("path")
             << getLevel()
             << "1"
             << pathSQLFormat("trace");
    //            + // 1 to indicate the trek is done. (done == true)
    //            pathSQLFormat();

    return trekData;
}


