import QtQuick 2.9
import QtQuick.Controls 2.2
//import QtWebView 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import QtPositioning 5.8
import QtMultimedia 5.8

//import "JSControl.js" as JSC


TabBar {
    property Camera camera
    currentIndex: swipeView.currentIndex
    contentHeight: (1/10) * mainPage.height

    TabButton {
        onClicked: if(camera.ActiveState == 2)
                       camera.stop();
        Image {
            source: "../../../images/icon/home.png"

            height: (1/10) * mainPage.height
            fillMode: Image.PreserveAspectFit

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }

    TabButton {
        onClicked: if(camera.ActiveState == 2)
                       camera.stop();
        Image {
            source: "../../../images/icon/trekking_icon.png"

            height: (1/10) * mainPage.height
            fillMode: Image.PreserveAspectFit

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }

    TabButton {
        onClicked: if(camera.ActiveState == 2)
                       camera.stop();
        Image {
            source: "../../../images/icon/current_trek_icon.png"

            height: (1/10) * mainPage.height
            fillMode: Image.PreserveAspectFit

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }

    TabButton {
        onClicked: camera.start();
        Image {
            source: "../../../images/icon/camera_icon.png"

            height: (1/10) * mainPage.height
            fillMode: Image.PreserveAspectFit

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }

    TabButton {
        onClicked: if(camera.ActiveState == 2)
                       camera.stop();
        Image {
            source: "../../../images/icon/upload_icon.png"

            height: (1/10) * mainPage.height
            fillMode: Image.PreserveAspectFit

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }
    TabButton {
        Image {
            source: "../../../images/icon/upload_icon.png"

            height: (1/10) * mainPage.height
            fillMode: Image.PreserveAspectFit

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }
}
