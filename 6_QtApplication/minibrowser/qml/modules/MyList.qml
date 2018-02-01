import QtQuick 2.0
import "../javascript/JSControl.js" as MyScript

Rectangle {
    id : myListView

    //    property bool active : trekPage.trek2_visibilite
    property bool active : trekPage.trek2_loadTrek

    ListModel {
        id: treksModel
        ListElement {
            label: "Titre du trek"
            length: 00
            time : "00:00:00"
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
            console.log(treksModel.get(view.currentIndex).label)
            labelTrek = treksModel.get(view.currentIndex).label;
            lengthTrek = treksModel.get(view.currentIndex).length;
            timeTrek = treksModel.get(view.currentIndex).time;
        }


        spacing: 4
    }


    onActiveChanged : {
        if (active) {
            console.log("ok")
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

                //console.log("response", request.responseText)
                var result = JSON.parse(request.responseText)

                for (var ligne in result.treks) {

                    treksModel.append({
                                          "label": result.treks[ligne].label,
                                          "length": result.treks[ligne].length,
                                          "time": result.treks[ligne].time
                                      })
                }

                trekPage.trek1_visibilite = false;
                trekPage.trek2_visibilite = true;


            } else {
                console.log("HTTP:", request.status, request.statusText)
                trek1_error = "erreur de connexion"

                trek1_visibilite = true;
                trek2_visibilite = false;
            }
        }

        request.send()
    }
}
