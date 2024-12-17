import QtQuick
import QtQuick.Controls.Basic

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

        Text {
            text: "Saw 1"
            anchors.horizontalCenter: parent.horizontalCenter

            font.pointSize: 14
        }

        AnimatedImage {
            id: sawImage
            width: 200
            height: 200

            playing: false
            source: "assets/circular-saw.gif"
            speed: slider.value
        }

        Row {
            spacing: 10

            Button {
                text: "Start"

                onClicked: {
                    sawImage.playing = true
                }
            }

            Button {
                text: "Stop"

                onClicked: {
                    sawImage.playing = false
                }
            }
        }

        Slider {
            id: slider

            width: 200

            from: 0
            to: 5

            value: 1
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
