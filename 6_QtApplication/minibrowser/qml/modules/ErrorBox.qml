import QtQuick 2.9
import QtQuick.Controls 2.2


Rectangle {

    property string content: "value = message d'erreur"
    property string mycolor: "red"

    Text {
        id : errorBox
        text : content

        color : mycolor
        font.family: "acumin-pro"
        font.pixelSize: Qt.application.font.pixelSize * 1.25
        font.bold: true

        anchors.centerIn : parent

    }

}
