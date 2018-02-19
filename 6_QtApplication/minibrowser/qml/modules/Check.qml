import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import QtWebView 1.1

import "../"

RowLayout {
   /* property bool statusV
    property bool buttonV
    property bool errorV*/
    spacing: 0
    id: check
    visible: false
    Layout.preferredHeight: (1/2)*parent.height
    Layout.fillHeight: true
    Layout.fillWidth: true
    
    ColumnLayout {
        spacing: 0
        
        anchors.fill: parent
        
        RowLayout {
            spacing: 0
            
            Layout.preferredHeight: (1/3)*parent.height
            Layout.fillHeight: true
            Layout.fillWidth: true
            
            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                
                Text {
                    text : "Êtes-vous sûr ?"
                    
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
                
                MyButton {
                    id: valid
                    visible: true
                    
                    text : "OK"
                    height: etat.height / 15
                    width: etat.width /3
                    onClicked: {
                        console.log("valid")
                        check.visible = false
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
                        status.visible = true
                        boutons.visible = true
                        error.visible = true
                        check.visible = false
                        console.log("cancel")
                    }
                }
            }
        }
    } //fin Columnlayout
}
