import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"
import "../../../images"

ColumnLayout {
    id : etat

    anchors.fill: parent
    spacing: 0

    RowLayout {
        id : helloBox
        visible: true

        spacing: 0
        Layout.preferredHeight: (15/36)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "lightBlue"

            Text {
                id : label
                text : "Bonjour" + "\n" + MyContext.user.username

                font.family: "tablet-gothic-condensed"
                font.pixelSize: Qt.application.font.pixelSize * 4
                font.bold: true
                //font.capitalization: Font.SmallCaps

                anchors.centerIn : parent
                horizontalAlignment: Text.AlignHCenter

            }
        }
    }

    RowLayout {
        id : erreur
        visible: true

        spacing: 0
        Layout.preferredHeight: (2/9)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "grey"

            ErrorBox {
                height : parent.height
                width : parent.width

                content : MyContext.storageStatus

                anchors.centerIn : parent
            }
        }
    } //fin rowlayout

    RowLayout {
        id : boutons
        visible: true

        spacing: 0
        Layout.preferredHeight: (1/9)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            MyButton {
                id : saveButton
                visible: true

                text : "Sauver"
                height: etat.height / 15
                width: etat.width /3
                onClicked: {
//                    console.log("switch to UploadPage")
//                    MyContext.saveTrek();
                }
            }

            MyButton {
                id: continueButton
                visible : false

                text : "Continuer"
                height: etat.height / 15
                width: etat.width /3
                onClicked: console.log("switch to TrekTracker")
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            MyButton {
                id: deleteButton
                visible : true

                text : "Effacer"
                height: etat.height / 15
                width: etat.width /3
                onClicked:
                {
                    MyContext.deleteTrek();
                    helloBox.visible = false
                    boutons.visible = false
                    check.visible = true
                }
            }
        }
    } //fin rowlayout

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

                        font.family: "acumin-pro"
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
                            helloBox.visible = true
                            boutons.visible = true
                            check.visible = false
                            console.log("cancel")
                        }
                    }
                }
            }
        } //fin columnlayout
    }

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "blue"

            MyButton {
                text : "Deconnexion"
                height: etat.height / 15
                width: etat.width /3
                onClicked: {
                    console.log("deconnexion");
                    home2_visibilite = false;
                    home1_visibilite = true
                    MyContext.deleteUser();
                }
            }
        }
    }



    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "blue"

            LogoAFPA {}
        }

    } // fin RowLayout

} //fin columnlayout



