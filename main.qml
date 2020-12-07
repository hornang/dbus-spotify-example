import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.12
import MediaPlayer 1.0

ApplicationWindow {
    visible: true
    title: qsTr("dbus-spotify-example")

    MediaPlayer {
        id: mediaPlayer
    }

    Column {
        anchors.centerIn: parent

        GridLayout
        {
            columns: 2
            Label {
                text: "Song:"
            }
            Label {
                text: mediaPlayer.song
                font.pixelSize: 30
            }
            Label {
                text: "Artist:"
            }
            Label {
                text: mediaPlayer.artist
                font.pixelSize: 30
            }
        }

        Row {
            Button {
                text: "Stop"
                onClicked: mediaPlayer.stop()
            }
            Button {
                text: "Play/pause"
                onClicked: mediaPlayer.playPause()
            }
            Button {
                text: "Previous"
                onClicked: mediaPlayer.previous()
            }
            Button {
                text: "Next"
                onClicked: mediaPlayer.next()
            }
        }
    }
}
