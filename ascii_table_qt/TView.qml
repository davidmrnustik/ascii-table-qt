import QtQuick 2.12
//import Qt.labs.qmlmodels 1.0
import TableModel

TableView {
    property var dataModel
    anchors.top: button.bottom
    width: root.width
    height: root.height
    columnSpacing: 1
    rowSpacing: 1
    clip: true
    model: TableModel { model: dataModel }

//    model: TableModel {
//
//        TableModelColumn {
//            display: function(modelIndex) { return rows[modelIndex.row][0].checked }
//            setDisplay: function(modelIndex, cellData) { rows[modelIndex.row][0].checked = cellData }
//        }
//        TableModelColumn { display: "Dec" }
//        TableModelColumn { display: "Oct" }
//        TableModelColumn { display: "Hex" }
//        TableModelColumn { display: "Binary" }
//        TableModelColumn { display: "C" }
//        TableModelColumn { display: "Dec" }
//        TableModelColumn { display: "Oct" }
//        TableModelColumn { display: "Hex" }
//        TableModelColumn { display: "Binary" }
//        TableModelColumn { display: "C" }
//        TableModelColumn { display: "Dec" }
//        TableModelColumn { display: "Oct" }
//        TableModelColumn { display: "Hex" }
//        TableModelColumn { display: "Binary" }
//        TableModelColumn { display: "C" }
//        TableModelColumn { display: "Dec" }
//        TableModelColumn { display: "Oct" }
//        TableModelColumn { display: "Hex" }
//        TableModelColumn { display: "Binary" }
//        TableModelColumn { display: "C" }

//       rows: [
//            [
//                "A - prvni",
//                "A - druhy",
//                "A - treti"
//            ],
//            [
//                "B - prvni",
//                "B - druhy",
//                "B - treti"
//            ],
//       ]
//        rows: [
//            [
//                { checked: false, checkable: true },
//                { amount: 1 },
//                { fruitType: "Apple" },
//                { fruitName: "Granny Smith" },
//                { fruitPrice: 1.50 }
//            ]
//        ]
//        rows: [
//            {
//                // Each property is one cell/column.
//                checked: false,
//                amount: 1,
//                fruitType: "Apple",
//                fruitName: "Granny Smith",
//                fruitPrice: 1.50
//            },
//            {
//                checked: true,
//                amount: 4,
//                fruitType: "Orange",
//                fruitName: "Navel",
//                fruitPrice: 2.50
//            },
//            {
//                checked: false,
//                amount: 1,
//                fruitType: "Banana",
//                fruitName: "Cavendish",
//                fruitPrice: 3.50
//            }
//        ]
//    }
    delegate: Rectangle {
        implicitWidth: 100
        implicitHeight: 50
        Text {
            text: model.display
        }
    }
}