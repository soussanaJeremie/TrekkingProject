import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../modules"
import "TrekTracker"

Page {

    id : trekPage

    property bool trek1_visibilite: true
    property bool trek2_visibilite: false
    property bool trek3_visibilite: false

    property string trek1_error: ""
    property bool trek2_loadTrek: false

    header: Label {
        text: qsTr("Trek Tracker")
        font.pixelSize: Qt.application.font.pixelSize * 2
        font.family: "acumin-pro"
        padding: 10
    }

    Etat1 {
        id : etat1
        visible: trek1_visibilite
    }

    Etat2 {
        id : etat2
        visible: trek2_visibilite
    }

    Etat3 {
        id : etat3
        visible: trek3_visibilite
    }
}
