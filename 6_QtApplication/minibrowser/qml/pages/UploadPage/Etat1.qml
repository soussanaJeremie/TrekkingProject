import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import QtWebView 1.1

import "../../modules"

ColumnLayout {

    id : etat

    anchors.fill: parent
    Layout.fillHeight: true
    Layout.fillWidth: true

    spacing: 0

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/12)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "blue"

            TextBox {
                text : "Etat actuel de la sauvegarde : "

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    RowLayout {
        id : status
        visible : true

        spacing: 0
        Layout.preferredHeight: (5/12)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "yellow"

            TextBox {
                id : localStorageStatus
                text : "aucune sauvegarde"

                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

            }


        }
    }

    RowLayout {
        id : boutons
        visible : true

        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "grey"

            MyButton {
                text : "Sauvegarder"
                height: etat.height / 15
                width: etat.width / 3

                onClicked: console.log("sauvegarde de la photo & edition du LocalFile")
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "grey"

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
        id : error
        visible : true

        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            ErrorBox {
                height : parent.height
                width : parent.width

                anchors.centerIn : parent

            }
        }
    }

    RowLayout {
        id : check
        visible: false

        spacing: 0
        Layout.preferredHeight: (1/2)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            RowLayout {
                spacing: 0
                Layout.preferredHeight: (1/3)*parent.height
                Layout.fillHeight: true
                Layout.fillWidth: true

                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: "grey"

                    Text {
                        text : "Etes vous sûr ?"

                        font.family: "Calibri"
                        font.pixelSize: Qt.application.font.pixelSize * 1.5
                        font.bold: true

                        anchors.centerIn : parent
                    }
                }
            } //fin rowlayout


            RowLayout {
                spacing: 0
                Layout.preferredHeight: (1/3)*parent.height
                Layout.fillHeight: true
                Layout.fillWidth: true

                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: "red"

                    MyButton {
                        id : valid
                        visible: true

                        text : "OK"
                        height: etat.height / 15
                        width: etat.width /3
                        onClicked: console.log("valid")
                    }
                }

                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: "red"

                    MyButton {
                        id: cancel
                        visible : true

                        text : "cancel"
                        height: etat.height / 15
                        width: etat.width /3
                        onClicked: {
                            status.visible = true
                            boutons.visible = true
                            check.visible = false
                            console.log("cancel")
                        }
                    }
                }
            }
        } //fin rowlayout
    }


    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/4)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "blue"

            Image {
                id: logoAfpa
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                source: "../../../images/logoAfpa.jpg"
            }
        }
    } // fin RowLayout

    //    MyDialog {
    //        id : dialog
    //        titre: ""
    //        instruction: "Are you sure ?"
    //    }
}
