import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../modules"
import "PhotoPage"

Page {
    id : photoPage

    property bool photo1_visibilite: false
    property bool photo2_visibilite: true
    property bool photo3_visibilite: false
    property alias urlLastPhoto: etat1.urlLastPhoto

    header: Label {
        text: qsTr("Photo")
        font.pixelSize: Qt.application.font.pixelSize * 2
        font.family: "acumin-pro"
        padding: 10
    }

    Etat1 {
        id : etat1
        visible: photo1_visibilite
        onUrlSet: {
            etat2.currenturl = urlLastPhoto
            console.log("etat2.currenturl -> " + etat2.currenturl)
            etat3.currenturl = etat2.currenturl
            console.log("etat3.currenturl -> " + etat3.currenturl)
        }
    }

    Etat2 {
        id : etat2
        visible: photo2_visibilite
    }

    Etat3 {
        id : etat3
        visible: photo3_visibilite
    }
}


