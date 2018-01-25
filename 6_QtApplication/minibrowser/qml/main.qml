import QtQuick 2.9
import QtQuick.Controls 2.2
//import QtWebView 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.2

import QtPositioning 5.8

import "../qml/modules"
import "../qml/pages"



ApplicationWindow {
    property var pixelRatio: Screen.devicePixelRatio
    property var pixelDensity: Screen.pixelDensity

    id: myApp

    visible: true

//    width: 384
//    height: 640

    width: Screen.width
    height: Screen.height

    title: "Trecker _ Le tracker de trek"

    header: MyToolBar{
        id: tabBar
    }

    SwipeView{
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        HomePage{
            id: homePage
        }

        TrekTracker{
            id: trekPage
        }

        MapPage{
            id: mapPage
        }

        PhotoPage{
            id: photoPage
        }

        UploadPage{
            id: uploadPage
        }

    }
}
