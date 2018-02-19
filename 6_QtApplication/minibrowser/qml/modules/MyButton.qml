import QtQuick 2.7
import QtQuick.Controls 2.2

Button {
    property double buttonHeight: etat.height / 15
    property double buttonWidth: etat.width / 3

    id: control
    font.pixelSize: Qt.application.font.pixelSize * 1.25
    font.family: "acumin-pro"

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter

    background: Rectangle {

        border.color: "#26282a"
        border.width: 1
        radius: 4


        gradient: Gradient {
            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
        }
    }
}
