import QtQuick
import com.PlayerController

Window {
    id: root

    width: 640
    height: 480

    visible: true

    title: qsTr("Media Player")

    Rectangle {
        id: topbar

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: 50
        color: "#5F8575"
    }

    Rectangle {
        id: mainSection

        anchors {
            top: topbar.bottom
            bottom: bottombar.top
            left: parent.left
            right: parent.right
        }

        color: "#1e1e1e"

        AudioInfoBox {
            id: firstSong

            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                right: parent.right
                margins: 20
            }

            infoProvider {
                songIndex: 0
                title: "Eine Kleine Nachtmusik"
                authorName: "Wolfgang Amadeus Mozart"
                imageSource: "assets/images/song_1.jpg"
                audioSource: "D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/audio/AnothersArmsRingtone.m4a"
            }
        }

        AudioInfoBox {
            id: secondSong

            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                right: parent.right
                margins: 20
            }

            infoProvider{
                songIndex: 1
                title: "Symphone No. 5"
                authorName: "Ludwig Van Beethoven"
                imageSource: "assets/images/song_2.jpg"
                audioSource: "D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/audio/AuRevoirRingtone.m4a"
            }
        }

        AudioInfoBox {
            id: thirdSong

            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                right: parent.right
                margins: 20
            }

            infoProvider {
                songIndex: 2
                title: "Air on the G String"
                authorName: "Johann Sebastian Bach"
                imageSource: "assets/images/song_3.jpg"
                videoSource: "D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/videos/video_1.avi"
                audioSource: "D:/Workspaces_Git/MyGitHub/Qt_Projects/Qt6_App_MediaPlayer/assets/audio/BurningBridgesRingtone.m4a"
            }
        }
    }

    Rectangle {
        id: bottombar

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }

        height: 100
        color: "#333333"

        Row {
            anchors.centerIn: parent

            spacing: 20

            ImageButton {
                id: previousButton

                width: 64
                height: 64

                source: "assets/icons/previous_icon.png"

                onClicked: PlayerController.switchToPreviousSong()
            }

            ImageButton {
                id: playPauseButton

                width: 64
                height: 64

                source: PlayerController.playing ? "assets/icons/pause_icon.png" : "assets/icons/play_icon.png"

                onClicked: PlayerController.playPause()
            }

            ImageButton {
                id: nextButton

                width: 64
                height: 64

                source: "assets/icons/next_icon.png"

                onClicked: PlayerController.switchToNextSong()
            }
        }
    }
}
