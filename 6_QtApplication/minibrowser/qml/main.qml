import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.2

import QtPositioning 5.8

import "../qml/modules"
import "../qml/pages"

ApplicationWindow {

    id : mainPage

    property var pixelRatio: Screen.devicePixelRatio
    property var pixelDensity: Screen.pixelDensity
    property bool debugVisibility : false;

    visible: true

    width: 384
    height: 640

    //    width: Screen.width
    //    height: Screen.height

    title: "Trecker _ Le tracker de trek"

    header: MyToolBar {
        id: tabBar
        camera: photoPage.camera
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        property bool interactivity : true
        property var magicCode : "31414";
        property var currentCode : "";

        currentIndex: tabBar.currentIndex
        interactive: interactivity

        onCurrentIndexChanged: {
            currentCode += currentIndex
            if( currentCode.length > 5 )
                currentCode = currentCode.substr(1)

            if( magicCode == currentCode)
            {
                console.log("bingo");
                debugVisibility === false ? debugVisibility = true : debugVisibility = false ;
            }

            if (currentIndex == 2 || (currentIndex == 4 && !debugVisibility) ) { //a modifier si bug d'affichage
                interactivity = false
            }
            else {
                interactivity = true
            }
        }

/* Item of the SwipeView */

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
//            Component.onCompleted: etat1.implicitHeight = contentItem.implicitHeight;
        }

        MyDebuggingPage {
            id : idDebug
        }
    }

}
