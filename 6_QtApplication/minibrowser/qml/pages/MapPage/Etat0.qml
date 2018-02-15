import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"
import "../../../images"

ColumnLayout {

    property bool anime: true
    id : etat

    anchors.fill: parent
    spacing: 0

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/4)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            Text {
                text : "mode hors connexion"

                font.family: "Californian FB"
                font.pixelSize: Qt.application.font.pixelSize * 1
                font.bold: true

                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/2)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "lightBlue"

            AnimatedImage {
                id: animation
                source: "../../../images/nordic.gif"

                height: parent.height
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter

                playing: anime
            }

            MouseArea {
                anchors.fill : parent

                onClicked: anime === true ? anime = false : anime = true

//                ToolTip.visible: hovered
//                ToolTip.text: "arret de l'animation"
            }
        }
    }

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/4)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                //color: "red"

                LogoAFPA {}
            }
        }
    }

} //fin columnlayout



