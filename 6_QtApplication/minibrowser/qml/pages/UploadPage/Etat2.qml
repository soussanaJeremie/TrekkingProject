import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"

ColumnLayout {
    spacing: 0
    
    anchors.fill: parent
    Layout.fillHeight: true
    Layout.fillWidth: true
    
    MyRow {
        blank: true
        colorForBlank: "white"
        Layout.preferredHeight: (1/12)*parent.height
    }
    
    MyRow {
        textBox: true
        colorForTextBox: "lightgrey"
        text : "Etat actuel de la sauvegarde : "
    }
    
    MyRow {
        id: status
        textBox: true
        visible : true
        Layout.preferredHeight: (1/3)*parent.height
        text : MyContext.storageStatus
    }
    
    MyRow {
        id: boutons
        visible : true
        Layout.preferredHeight: (1/8)*parent.height
        button: true
        textButton: "Sauvegarder"
        
        onButtonClicked: {
            MyContext.testUploadPhoto();
            console.log("sauvegarde de la photo & edition du LocalFile")
        }
        
        button2: true
        textButton2 : "Supprimer"
        
        onButton2Clicked: {
            status.visible = false
            boutons.visible = false
            error.visible = false
            check.visible = true
        }
    }
    
    //    MyRow {
    //        id: error
    //        visible : true
    //        Layout.preferredHeight: (1/8)*parent.height
    //        errorBox: true
    //    }
    
    
    //    Check {
    //        id: check
    //    }
    
    //    MyRow {
    //        logoAFPA: true
    //    }
}
