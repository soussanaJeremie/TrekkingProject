import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"

RowLayout {
    property alias blank: idBlankR.visible
    property string colorForBlank: idBlankR.color

    property alias textBox: idTextBox.visible
    property string text: idTextBox.text
    property string colorForTextBox: idTextBoxR.color

    property alias button: idButton.visible
    property string textButton: idButton.text
    property string colorForButton: idButtonR.color
    signal buttonClicked

    property alias button2: idButton2.visible
    property string textButton2: idButton2.text
    property string colorForButton2: idButton2R.color
    signal button2Clicked

    property alias errorBox: idErrorBox.visible
    property alias logoAFPA: idLogoAfpa.visible


    spacing: 0
    Layout.fillWidth: true
    Layout.fillHeight: true

    Rectangle {
        id: idBlankR
        visible: false
        Layout.fillHeight: true
        Layout.fillWidth: true
    }

    Rectangle {
        id: idTextBoxR
        visible: (idTextBox.visible)? true : false
        Layout.fillHeight: true
        Layout.fillWidth: true

        TextBox {
            id: idTextBox
            visible: false
        }
    }

    Rectangle {
        id: idButtonR
        visible: (idButton2.visible)? true : false
        Layout.fillHeight: true
        Layout.fillWidth: true

        MyButton {
            id: idButton
            visible: false
            height: buttonHeight
            width: buttonWidth
            onClicked: buttonClicked()
        }
    }

    Rectangle {
        id: idErrorBoxR
        visible: (idErrorBox.visible)? true : false
        Layout.fillHeight: true
        Layout.fillWidth: true

        ErrorBox {
            id: idErrorBox
            visible: false
        }
    }

    Rectangle {
        id: idButton2R
        visible: (idButton2.visible)? true : false
        Layout.fillHeight: true
        Layout.fillWidth: true

        MyButton {
            id: idButton2
            visible: false
            height: buttonHeight
            width: buttonWidth
            onClicked: button2Clicked()
        }
    }

    Rectangle {
        id: idLogoAfpaR
        visible: (idLogoAfpa.visible)? true : false
        Layout.fillHeight: true
        Layout.fillWidth: true

        LogoAFPA {
            id: idLogoAfpa
            visible: false
        }
    }
}
