import QtQuick
import QtQuick.Controls.Basic
import QmlCppExample

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML and Cpp integration")

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Lumber mill control center"
            anchors.horizontalCenter: parent.horizontalCenter

            font.pointSize: 18
        }


        Row {
            spacing: 20

            LumberMillBlock {
                name: "Saw 1"

                controller: LumberSawController {
                    id : sawController1
                    sawSpeed: 2
                }
            }

            LumberMillBlock {
                name: "Saw 2"

                controller: LumberSawController {
                    id : sawController2
                    sawSpeed: 5
                }
            }

        }
    }

    Image {
        width: 100
        height: 24

        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 10
        }

        source: "assets/built-with-qt-badge.png"
    }
}
