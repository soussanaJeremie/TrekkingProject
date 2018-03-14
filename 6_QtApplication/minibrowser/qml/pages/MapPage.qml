import QtQuick 2.9
import QtQuick.Controls 2.2
//import QtWebView 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
import QtPositioning 5.8

import "MapPage"
import "../javascript/JSControl.js" as JSC

Page {

    id : mapPage

    property bool gpsActive : false
    property bool startNewTrek : false
    property var trekName : ""
    property var leafletTrace: ""
    property bool map0_visibilite: false
    property bool map1_visibilite: true

    Etat0 {
        id : etat0
        visible: map0_visibilite
    }

    Etat1 {
        id : etat1
        visible: map1_visibilite

    }

    footer: Label {

        text: "lat: " + JSC.lastLat() + ", lng: " + JSC.lastLng()
        font.pixelSize: Qt.application.font.pixelSize * 1.25
        font.family: "Calibri"
    }

    PositionSource{
        id: gpsPosition
        updateInterval: 3000
        active: mapPage.gpsActive

        onActiveChanged: {
            var coord = gpsPosition.position.coordinate;
            if (mapPage.gpsActive && startNewTrek)
            {
                MyContext.startTrek(trekName, coord.latitude, coord.longitude, leafletTrace);
                startNewTrek = false;
            }
        }

        onPositionChanged: {
            var coord = gpsPosition.position.coordinate;
            if (mapPage.gpsActive)
            {
                MyContext.updateTrek(coord.latitude, coord.longitude);
            }
        }
    }
}
