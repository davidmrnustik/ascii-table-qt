import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./"
import AsciiTable

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    AsciiTable {
       id: asciiTable
       format: 4
    }

    ColumnLayout {
        anchors.fill: parent

        Row {
            Text {
                id: title
                height: parent.height
                text: "ASCII TABLE"
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }
            Button {
                id: button
                text: "Click me"
                onClicked: asciiTable.printTable()
            }
        }

        View {
            Layout.fillWidth: true
            Layout.fillHeight: true
            boundsMovement: Flickable.StopAtBounds
            dataModel: asciiTable.getData()
        }
    }
}
