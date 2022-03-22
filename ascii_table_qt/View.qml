import QtQuick 2.12
import TableModel

TableView {
    id: tableView
    property var dataModel
    columnSpacing: 1
    rowSpacing: 1
    clip: true
    model: TableModel {
        id: tableModel
        model: dataModel
    }
    property var columnWidths: tableModel.getColumnWidths(asciiTable.getColumns(), root.width)
    columnWidthProvider: function (column) { return tableView.model ? tableView.width/tableView.model.columnCount() : 0 }
//    columnWidthProvider: function (column) { return columnWidths[column] }

    onWidthChanged: {
        tableView.columnWidths = tableModel.getColumnWidths(asciiTable.getColumns(), root.width)
        console.log(asciiTable.getColumns())
        tableView.forceLayout()
    }

    delegate: Rectangle {
        implicitWidth: tableView.columnWidthProvider(column)
        implicitHeight: 50
        Text {
            anchors.centerIn: parent
            text: model.display
        }
    }
}