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

    id : captureControls

    Rectangle {
        id: buttonPaneShadow
        width: parent.width
        height: buttonsRow.height

        color: Qt.rgba(0.08, 0.08, 0.08, 1)

        anchors.horizontalCenter: parent.horizontalCenter

        RowLayout {
            id: buttonsRow
            anchors.fill: parent

            layoutDirection: Qt.LeftToRight

            spacing: 8

            FocusButton {
                Layout.alignment: Qt.AlignCenter
                camera: captureControls.camera
                visible: camera.cameraStatus == Camera.ActiveStatus && camera.focus.isFocusModeSupported(Camera.FocusAuto)
            }

            Button {
                text: "Capture"
                Layout.alignment: Qt.AlignCenter

                visible: camera.imageCapture.ready
                onClicked: {
                    camera.imageCapture.capture();
                }
            }

            Button {
                text: "View"
                Layout.alignment: Qt.AlignCenter

                onClicked: captureControls.previewSelected()
                visible: captureControls.previewAvailable
            }

            Button {
                text: "Edit"
                Layout.alignment: Qt.AlignCenter

                onClicked: {
                    camera.stop();
                    var path = "file:///" + camera.imageCapture.capturedImagePath;
                    MyContext.saveLastImageTakenUrl(path);
                    console.log("photoTaken: url -> " + path);
                    urlLastPhoto = path;
                    console.log("photoPreview.urlLastPhoto -> " + urlLastPhoto)
                    photo1_visibilite = false;
                    photo2_visibilite = true;
                }
            }
        }
    }
}

