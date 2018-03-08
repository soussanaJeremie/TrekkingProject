import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.8

Item {
    id : test

    property string urlLastPhoto: "aaa"
    property alias source : preview.source
    signal closed

    Image {
        id: preview
        anchors.fill : parent
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    
    MouseArea {
        anchors.fill: parent
        onClicked: {
            var path = "file:///" + camera.imageCapture.capturedImagePath;
            MyContext.saveLastImageTakenUrl(path);
            MyContext.debug("photoTaken: url -> " + path);
            parent.closed();
            urlLastPhoto = path;
            MyContext.debug("photoPreview.urlLastPhoto -> " + urlLastPhoto)

            if(!camera.ActiveStatus)
                camera.start()
        }
    }
}
