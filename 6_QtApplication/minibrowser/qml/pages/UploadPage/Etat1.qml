import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import QtWebView 1.1

import "../../modules"

ColumnLayout {  
    spacing: 0
    id: etat

    anchors.fill: parent
    Layout.fillHeight: true
    Layout.fillWidth: true

    RowLayout {
        spacing: 0

        Layout.preferredHeight: (1/12)*parent.height
        Layout.fillWidth: true
        Layout.fillHeight: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "white"
        }
    }

    RowLayout {
        spacing: 0

        Layout.preferredHeight: (1/12)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "lightGrey"

            TextBox {
                text : "Etat actuel de la sauvegarde : "
                font.family: "acumin-pro"

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    RowLayout {
        spacing: 0
        id: status

        visible : true
        Layout.preferredHeight: (1/3)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            TextBox {
                id: localStorageStatus
                text : MyContext.storageStatus

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    RowLayout {
        spacing: 0
        id: boutons

        visible : true
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            MyButton {
                text : "Sauvegarder"
                height: etat.height / 15
                width: etat.width / 3
                onClicked: {
                    MyContext.testUploadPhoto();
                    console.log("sauvegarde de la photo & edition du LocalFile")
                }
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            MyButton {
                text : "Supprimer"
                height: etat.height / 15
                width: etat.width / 3

                onClicked: {
                    status.visible = false
                    boutons.visible = false
                    error.visible = false
                    check.visible = true
                }
            }
        }
    }

    RowLayout {
        spacing: 0
        id: error

        visible : true
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ErrorBox {
                height : parent.height
                width : parent.width

                anchors.centerIn : parent
            }
        }
    }

  Check {
        id: check
       /* statusV: status.visible
        buttonV: boutons.visible
        errorV: error.visible*/
    }

    RowLayout {
        spacing: 0

        Layout.preferredHeight: (1/4)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            LogoAFPA {}
        }
    } // fin RowLayout
}
