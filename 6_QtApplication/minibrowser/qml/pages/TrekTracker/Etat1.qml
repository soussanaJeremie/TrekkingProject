import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"
import "../../../images"
import "../../javascript/JSControl.js" as MyScript

ColumnLayout {
    id : etat

    anchors.fill: parent
    spacing: 0


    RowLayout {
        spacing: 0
        Layout.preferredHeight: 0.25*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    RowLayout {
        id : btn1
        visible: true

        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            MyButton {
                text : "Nouveau Trek"
                height: etat.height / 15
                width: etat.width / 2
                onClicked: {
                    btn1.visible = false
                    btn2.visible = false
                    error.visible = false
                    check.visible = true
                }
            }
        }
    } // fin RowLayout

    RowLayout {
        id : btn2
        visible: true

        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            MyButton {
                text : "Charger un Trek"
                height: etat.height / 15
                width: etat.width / 2
                onClicked: {
                    console.log("changement de page > TrekTracker.etat2");
                    trek2_loadTrek = true;
                    trek1_visibilite = false;
                    trek2_visibilite = true;
                }

            }
        }
    } // fin RowLayout

    RowLayout {
        id : error
        visible: true

        spacing: 0

        Layout.preferredHeight: 0.25*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true


        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ErrorBox {
                height : parent.height
                width : parent.width

                anchors.centerIn : parent

                content : trek1_error
            }
        }

    } //fin RowLayout


    RowLayout {
        id : check
        visible: false

        spacing: 0

        Layout.preferredHeight: 0.25*parent.height
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

                    InputBox {
                        id : label
                        placeholderText: "titre du trek"

                        width: parent.width * 0.90
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

                    MyButton {
                        id : valid
                        visible: true

                        text : "OK"
                        height: etat.height / 15
                        width: etat.width /3
                        onClicked: {
                            console.log("valid " + label.text)
                            trek1_visibilite = false;
                            trek3_visibilite = true;

//                            mapPage.trekName = label.text;
//                            mapPage.startNewTrek = true;

                            etat2.labelTrek = label.text;
                            etat2.lengthTrek = 0;
                            etat2.timeTrek = "";
                        }
                    }
                }

                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    MyButton {
                        id: cancel
                        visible : true

                        text : "cancel"
                        height: etat.height / 15
                        width: etat.width /3
                        onClicked: {
                            btn1.visible = true
                            btn2.visible = true
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
        Layout.preferredHeight: 0.25*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true


        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            LogoAFPA {}
        }
    } // fin RowLayout

}



