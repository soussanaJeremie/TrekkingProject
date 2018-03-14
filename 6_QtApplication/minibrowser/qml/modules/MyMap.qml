import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.6

import "../javascript/JSControl.js" as JSC

Item{
    property var pathway : []
    anchors.fill: parent
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: currentMap
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(JSC.lastLat(), JSC.lastLng()) // Oslo
        zoomLevel: 18

        MapPolyline {
            id: lineOfPathway
            line.width: 3
            line.color: 'green'
            path: JSC.pathwayToJSon()
        }

        MapPolyline {
            id: lineOfTrace
            line.width: 3
            line.color: 'orange'
            path: JSC.traceToJSon()
        }
    }
}
