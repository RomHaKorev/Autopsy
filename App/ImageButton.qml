import QtQuick 2.7
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    property alias source: img.source
    property alias label: label.text
    signal clicked()
    Item {
        anchors.fill: parent
        anchors.margins: 4
        Image {
            anchors.top: parent.top
            anchors.bottom: label.visible?label.top: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            id: img
            smooth: true
            antialiasing: true
            fillMode: Image.PreserveAspectFit

            ColorOverlay {
                    anchors.fill: img
                    source: img
                    color: parent.enabled? "#FFFFFF": "AAAAAA"
            }
        }
        Text {
            visible: text !== ""
            id: label
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: ""
            color: parent.enabled? "#FFFFFF": "AAAAAA"
        }
    }

    Rectangle {
        id: background
        z: -1
        anchors.fill: parent
        color: "#202020"
        visible: mouseArea.pressed
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            parent.clicked()
        }
    }
}
