import QtQuick 2.9
import QtQuick.Controls 2.2
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
        Layout.preferredHeight: (1/2)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true
        
        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "white"
            
            Text {
                id : errorBox
                text : "List of Bugs : \n" + MyContext.errorMessage
                wrapMode: Text.WordWrap
                width: parent.width
                
                color : "red"
                font.family: "acumin-pro"
                font.pixelSize: Qt.application.font.pixelSize * 1.15
                
                anchors.centerIn : parent
                
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
            color: "lightGrey"
            
            Text {
                id : succesBox
                text : "List of succes : \n" + MyContext.wellDoneMessage

                wrapMode: Text.WordWrap
                width: parent.width
                
                color : "green"
                font.family: "acumin-pro"
                font.pixelSize: Qt.application.font.pixelSize * 1.15
                
                anchors.centerIn : parent
                
            }
        }
    }
    
}
