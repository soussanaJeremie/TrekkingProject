import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../modules"
import "HomePage"

Page {
    id : myDebugPage



    header: Label {
        text: qsTr("Debug")
        font.pixelSize: Qt.application.font.pixelSize * 2
        font.family: "acumin-pro"
        padding: 10
    }

    ColumnLayout {
        //        id : etat

        anchors.fill: parent
        anchors.top : header.bottom
        spacing: 0

        RowLayout {
            spacing: 0
            Layout.preferredHeight: 0.25*parent.height
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                id: bobox
                Layout.fillHeight: true
                Layout.fillWidth: true
                //color: "red"

                TextArea{
                    id: messageBox
                    width: bobox.width
                    height: bobox.height
                    text: MyContext.errorMessage
                }
            }
        }
    }
}
