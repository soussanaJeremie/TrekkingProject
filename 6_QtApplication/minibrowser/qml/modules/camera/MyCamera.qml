import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtMultimedia 5.8

Rectangle {
    id: cameraUI

    property alias urlLastPhoto: photoPreview.urlLastPhoto

    color: "black"
    state: "PhotoCapture"

    states: [
        State {
            name: "PhotoCapture"

            StateChangeScript {
                script: {
                    camera.captureMode = Camera.CaptureStillImage
                    camera.start()
                }
            }
        },
        State {
            name: "PhotoPreview"
        }
    ]
    Camera {
        id: camera
        captureMode: Camera.CaptureStillImage
        
        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview
                stillControls.previewAvailable = true
                cameraUI.state = "PhotoPreview"
                focus: visible
            }
        }
        videoRecorder {
            resolution: "640x480"
            frameRate: 30
        }
    }
    ZoomControl {
        x : 0
        y : 0
        width : 100
        height: parent.height

        anchors {
            left: cameraUI.left
        }

        currentZoom: camera.digitalZoom
        maximumZoom: Math.min(4.0, camera.maximumDigitalZoom)
        onZoomTo: camera.setDigitalZoom(value)
    }

    PhotoPreview {
        id : photoPreview
        anchors.fill : parent
        onClosed: cameraUI.state = "PhotoCapture"
        visible: cameraUI.state == "PhotoPreview"
        focus: visible
    }
    ColumnLayout {
        spacing: 10

        VideoOutput {
            id: viewfinder
            visible: cameraUI.state == "PhotoCapture" /*|| cameraUI.state == "VideoCapture"*/

            x: 0
            y: 0
            width: cameraUI.width
            height: cameraUI.height - stillControls.height

            source: camera
            autoOrientation: true
        }
        PhotoCaptureControls {
            id: stillControls

            Layout.alignment: Qt.AlignBottom
            Layout.fillWidth: true

            camera: camera
            visible: cameraUI.state == "PhotoCapture"
            onPreviewSelected: cameraUI.state = "PhotoPreview"

//            onVideoModeSelected: cameraUI.state = "VideoCapture"
        }
    }
}
