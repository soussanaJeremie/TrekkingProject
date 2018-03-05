import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import QtWebView 1.1

import "../../modules"

RowLayout {
    property string color: container.color
    property string text: textbox.text

    spacing: 0
    Layout.fillWidth: true
    Layout.fillHeight: true

    Rectangle {
        id: container
        Layout.fillHeight: true
        Layout.fillWidth: true

        TextBox {
            id: textbox
            text : "Etat actuel de la sauvegarde : "
            font.family: "acumin-pro"

            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
