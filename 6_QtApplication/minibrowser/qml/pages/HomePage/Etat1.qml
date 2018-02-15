import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

import "../../modules"
import "../../../images"

ColumnLayout {
    id : etat

    anchors.fill: parent
//    anchors.top : header.bottom
    spacing: 0

    RowLayout {
        spacing: 0
        Layout.preferredHeight: 0.25*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"
        }
    }

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "grey"

            InputBox {
                id : mail
                placeholderText: "Entrez votre mail"
                validator: RegExpValidator{ regExp: /([a-z A-Z 0-9 _.-]+)([@])([a-z A-Z])+([.])([a-z])+/ }
            }
        }
    } //fin rowlayout

    RowLayout {
        spacing: 0
        Layout.preferredHeight: (1/8)*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            InputBox {
                id : mdp
                placeholderText: "Entrez votre mot de passe"
            }
        }
    } //fin rowlayout

    RowLayout {
        spacing: 0
        Layout.preferredHeight: 0.25*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            MyButton {
                text : "Sign In"
                height: etat.height / 15
                width: etat.width /3
                onClicked: {
                    console.log("# check datas and save profil in localFile : " + mail.text + " " + mdp.text);

                    var uri = "http://localhost:3000/api-rest/users/auth";
                    var datas = {
                        mail : mail.text,
                        password : mdp.text};

                    console.log(datas)

                    var req = new XMLHttpRequest();

                    req.open("POST", uri, true);

                    req.setRequestHeader('Content-type','application/json; charset=utf-8');
                    req.onreadystatechange = function() {

                        if (req.readyState === XMLHttpRequest.DONE && req.status == 200) {
                            console.log("#" + req.responseText);

                            var result = JSON.parse(req.responseText);
                            console.log("++" + JSON.stringify(result.user.id));

                            MyContext.saveUser(JSON.stringify(result.user.id), JSON.stringify(result.user.username), mdp.text, JSON.stringify(result.user.mail))

                            home1_visibilite = false;
                            home2_visibilite = true;

                        }
                        else {
                            console.log("error: " + req.status);
                        }
                    }
                            req.send(JSON.stringify(datas));


                }
            }
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "red"

            MyButton {
                text : "Sign Up"
                height: etat.height / 15
                width: etat.width /3
                onClicked: {
                    console.log("connexion to webAppli");
                    home1_visibilite = false;
                    home3_visibilite = true;
                }

            }
        }
    } //fin rowlayout

    RowLayout {
        spacing: 0
        Layout.preferredHeight: 0.25*parent.height
        Layout.fillHeight: true
        Layout.fillWidth: true

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true
            //color: "blue"

            Image {
                id: logoAfpa
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                source: "../../../images/logoAfpa.jpg"
            }
        }
    } // fin RowLayout

} //fin columnlayout



