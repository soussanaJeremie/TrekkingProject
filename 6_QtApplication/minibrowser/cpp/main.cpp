#include <QtCore/QUrl>
#include <QtCore/QCommandLineOption>
#include <QtCore/QCommandLineParser>
#include <QGuiApplication>
#include <QStyleHints>
#include <QScreen>
#include <QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWebView/QtWebView>

#include "mycontext.h"
#include "debugclass.h"

using namespace std;

DebugClass *DebugClass::_singleton = nullptr;


int main(int argc, char *argv[])
{

    //! [0]
    QGuiApplication app(argc, argv);
    QtWebView::initialize();
    //! [0]

    QGuiApplication::setApplicationDisplayName(QCoreApplication::translate("main", "QtWebView Example"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();
    MyContext myContext;

    // Set le ctx
    myContext.initMyContext( /*engine,*/ ctx );

    // Update le ctx
    myContext.loadMyContext();

    // Ouvrir le Qml
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
