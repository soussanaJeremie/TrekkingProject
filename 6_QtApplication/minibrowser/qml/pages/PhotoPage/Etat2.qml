import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtMultimedia 5.8

import "../../modules"
import "../../modules/camera"
import "../../../images"

ColumnLayout {

    property string currenturl: "../../../images/defaultPhoto.png"
    property Camera camera

    id : etat

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
            //color: "red"
            Image {
                id: currentPhoto
                source: currenturl
                height: parent.height
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter

                MouseArea {
                    anchors.fill : parent
                    onClicked: {
                        photo2_visibilite = false ;
                        photo3_visibilite = true ;
                    }
                }
            }
        }
    } // fin rowlayout 1

    RowLayout {
        id : form1
        visible: true

        spacing: 0
        Layout.preferredHeight: (13/48)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            RowLayout {
                spacing: 0
                Layout.preferredHeight: 0.5*parent.height
                Layout.fillHeight: true
                Layout.fillWidth: true

                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: "lightBlue"

                    InputBox {
                        id : label
                        placeholderText: "titre de la photo"


                        width: parent.width * 0.90
                    }
                }
            } // fin Row du textInput

            RowLayout {
                spacing: 0
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredHeight: (13/48)*parent.height


                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: "blue"

                    ComboType {
                        id : poi_type

                        height: etat.height / 15
                        width: parent.width * 0.90
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter

                        onCurrentTextChanged: currentText != "" ? description.visible =  true : description.visible = false
                    }
                }

                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: "red"

                    MySwitchButton {
                        id : privateStatus
                        switchWidth: parent.width / 3
                        switchHeight : etat.height / 20
                    }
                }
            } //fin row de la comboBox et Switch
        } // fin columnLayout
    } // fin rowlayout 2

    RowLayout {
        id : form2
        visible: true

        spacing: 0
        Layout.preferredHeight: (13/48)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "lightBlue"

            TextEditBox {
                id : description
                visible: false
            }

        }
    } // fin RowLayout 3

    RowLayout {
        id : boutons
        visible: true

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

                onClicked: {
                    MyContext.photoTaken(label.text,urlLastPhoto, privateStatus.checkedValue)
                    MyContext.debug("datas : " + label.text + " ; " + poi_type.currentText + " ; " + privateStatus.checkedValue + " ; " + description.text)
                }
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
                    form1.visible = false
                    form2.visible =  false
                    boutons.visible = false
                    check.visible = true
                }
            }
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "grey"

            MyButton {
                text : "Take photo"
                height: etat.height / 15
                width: etat.width / 3
                onClicked: {
                    photo2_visibilite = false;
                    photo1_visibilite = true;
                }
            }
        }
    } // fin RowLayout 4


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
                            form1.visible = true
                            form2.visible =  true
                            boutons.visible = true
                            check.visible = false
                            console.log("cancel")
                        }
                    }
                }
            }
        } //fin columnlayout
    }
}
