import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtWebView 1.1

import "../../modules"
import "../../../images"
//import "../HomePage.qml"

ColumnLayout {
    id : etat

    anchors.fill: parent
    spacing: 0

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (7/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            WebView {
                anchors.fill: parent
                url: "http://localhost:3000/"
                onLoadingChanged: {
                    if (loadRequest.errorString)
                    {
                        MyContext.debug(loadRequest.errorString);
                    };
                }
            }
        }
    } //fin rowlayout

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            MyButton {
                text : "Return"
                height: etat.height / 15
                width: etat.width /3
                onClicked: {
                    home3_visibilite = false;
                    home1_visibilite = true
                }
            }
        }
    } //fin rowlayout


} //fin columnlayout



