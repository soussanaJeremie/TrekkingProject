import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtMultimedia 5.8

import QtWebView 1.1

import "../../modules"
import "../../modules/camera"

ColumnLayout {

    property alias urlLastPhoto: maCam.urlLastPhoto
    signal urlSet

    id : etat

    anchors.fill: parent
    Layout.fillHeight: true
    Layout.fillWidth: true

    spacing: 0

    Rectangle {
        id : cameraUI

        Layout.fillHeight: true
        Layout.fillWidth: true

        color: "black"
        state: "PhotoCapture"

        MyCamera {
            id : maCam
            anchors.fill: parent
            onUrlLastPhotoChanged: {
                console.log("camera.urlLastPhoto -> " + urlLastPhoto)
                urlSet();
            }
        }
    }
}
