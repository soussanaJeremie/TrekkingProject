import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"
import "../HomePage"

ColumnLayout {
    
    id : etat
    
    anchors.fill: parent
    Layout.fillHeight: true
    Layout.fillWidth: true
    
    spacing: 0
    
    RowLayout {
        spacing: 0

        Layout.fillHeight: true
        Layout.fillWidth: true
        
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "white"

            ListView {
                anchors.fill: parent

                delegate : Rectangle {
                    height: txt.contentHeight + 8
                    width: etat.width

                    color : index%2 ? "#eeeeff" : "#ffffff"
                    Text{
                         y : 4
                        id: txt
                        anchors.fill: parent
                        text : modelData

                        padding: 5
                        wrapMode: Text.Wrap
                        font.family: "acumin-pro"
                        font.pixelSize: Qt.application.font.pixelSize * 1.25
                    }
                }
                spacing: 4

                model : MyContext.dbgInfos
            }
        }
    }
}
