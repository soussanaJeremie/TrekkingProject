import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"
import "../../../images"

ColumnLayout {

    property string currenturl: "../../../images/defaultPhoto.png"
    property bool portraitView : false

    id : etat

    anchors.fill: parent
    spacing: 0

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (4/5)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            Image {
                id: currentPhoto
                source: currenturl

                width:  portraitView? parent.width:parent.width*1/2
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    } // fin rowlayout 1


    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/5)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                //color: "red"

                MyButton {
                    id : valid
                    visible: true

                    text : "Retour"
                    height: etat.height / 15
                    width: etat.width /3
                    onClicked: {
                        photo3_visibilite = false ;
                        photo2_visibilite = true ;
                        console.log("retour") ;
                    }
                }
            }
        } //fin rowlayout2

    } //fin columnlayout


