import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtMultimedia 5.8

FocusScope {
    property Camera camera
    property bool previewAvailable : false

    property int buttonsPanelWidth: buttonPaneShadow.width

    signal previewSelected
//    signal videoModeSelected
    id : captureControls

    Rectangle {
        id: buttonPaneShadow
        width: parent.width
        height: buttonsRow.height

        color: Qt.rgba(0.08, 0.08, 0.08, 1)

        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            id: buttonsRow
            anchors.fill: parent

            layoutDirection: Qt.LeftToRight

            spacing: 8

            FocusButton {
                camera: captureControls.camera
                visible: camera.cameraStatus == Camera.ActiveStatus && camera.focus.isFocusModeSupported(Camera.FocusAuto)
            }
            Button {
                text: "Capture"
                visible: camera.imageCapture.ready
                onClicked: {
                    camera.imageCapture.capture();
                }
            }
            Button {
                text: "View"
                onClicked: captureControls.previewSelected()
                visible: captureControls.previewAvailable
            }
            Button {
                text: "Edit"
                onClicked: {
                    camera.stop();
                    photo1_visibilite = false;
                    photo2_visibilite = true;
                }
            }
        }
    }
}

