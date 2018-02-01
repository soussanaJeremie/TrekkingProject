import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.8
import QtQuick.Controls 1.4

Button {
    property Camera camera

    onClicked: {
        if (camera.lockStatus == Camera.Unlocked)
            camera.searchAndLock();
        else
            camera.unlock();
    }
    text: {
        if (camera.lockStatus == Camera.Unlocked)
            "Focus";
        else if (camera.lockStatus == Camera.Searching)
            "Focusing"
        else
            "Unlock"
    }
}

