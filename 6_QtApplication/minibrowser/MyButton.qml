import QtQuick 2.7
import QtQuick.Controls 2.2

Button {
    id: control
    font.pixelSize: 14

    background: Rectangle {
        implicitWidth: 225
        implicitHeight: 75
        border.color: "#26282a"
        border.width: 1
        radius: 4
        gradient: Gradient {
            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
        }
    }
}
