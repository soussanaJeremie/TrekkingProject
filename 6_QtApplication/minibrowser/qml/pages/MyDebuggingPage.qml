import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../modules"
import "DebugPage"

Page {

    id : myDebugPage

    header: Label {
        text: qsTr("Debug")
        font.pixelSize: Qt.application.font.pixelSize * 2
        font.family: "acumin-pro"
        padding: 10
    }

    Etat1 {
        id: etat1
        visible: true
    }

    Etat1 {
        id: etat2
        visible: false
    }
}
