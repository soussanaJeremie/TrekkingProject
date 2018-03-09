import QtQuick 2.0
import "../../images"


Image {
    id: logoAfpa
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom
    source: "../../images/icon/logoAFPA.png"

    height: (1/10) * mainPage.height
    fillMode: Image.PreserveAspectFit
    }
