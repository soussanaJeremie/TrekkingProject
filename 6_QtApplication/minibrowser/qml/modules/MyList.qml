import QtQuick 2.0
import "../javascript/JSControl.js" as MyScript

Rectangle {
    id : myListView

    property bool active : trekPage.trek2_visibilite

    ListModel {
        id: treksModel
        ListElement {
            label: "Titre du trek"
            length: 00
            time : "00:00:00"
            pathway: ""
        }
    }

    Component {
        id: treksDelegate

        Item {
            anchors { left: parent.left; right: parent.right }
            height: column.implicitHeight + 4

            Column {
                id: column
                anchors { fill: parent; margins: 2 }

                Text { text: label
                    font.family: "acumin-pro"
                    font.pixelSize: Qt.application.font.pixelSize * 1.5
                }
                Text { text: length + " km" + "\t" + time
                    font.family: "acumin-pro"
                    font.pixelSize: Qt.application.font.pixelSize * 1
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: view.currentIndex = index
            }
        }
    }

    ListView {
        id : view
        anchors { fill: parent; margins: 2 }

        model: treksModel
        delegate: treksDelegate

        highlight: Rectangle { color: 'orange' ; radius : 4 }
        focus: true
        onCurrentItemChanged: {
            labelTrek = treksModel.get(view.currentIndex).label;
            lengthTrek = treksModel.get(view.currentIndex).length;
            timeTrek = treksModel.get(view.currentIndex).time;
            pathwayTrek = treksModel.get(view.currentIndex).pathway;

            mapPage.leafletTrace = treksModel.get(view.currentIndex).pathway;
        }
        spacing: 4
    }

    onActiveChanged : {
        if (active) {
            getTreksJSON()
        }
    }

    function getTreksJSON() {
        var uri = "http://localhost:3000/api-rest/users/" + MyContext.getIdUser();

        var request = new XMLHttpRequest()
        request.open('GET', uri, true);

        request.onreadystatechange = function() {
            if (request.readyState === XMLHttpRequest.DONE && request.status == 200) {

                treksModel.clear();

                var result = JSON.parse(request.responseText)

                for (var ligne in result.treks) {
                    treksModel.append({
                                          "label": result.treks[ligne].label,
                                          "length": result.treks[ligne].length,
                                          "time": result.treks[ligne].time,
                                          "pathway": result.treks[ligne].pathway
                                      });
                    MyContext.setWellDoneMessage("\n" + result.treks[ligne].pathway);
                }

            } else {
                MyContext.debug("HTTP:", request.status, request.statusText)
            }
        }

        request.send()
    }
}
