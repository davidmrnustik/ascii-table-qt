//
// Created by David Mrnustik on 16/3/22.
//

#ifndef ASCIITABLE_QT_TABLEMODEL_H
#define ASCIITABLE_QT_TABLEMODEL_H

#include <QAbstractTableModel>
#include <QtQml/qqmlregistration.h>
#include <algorithm>

typedef QVector<QString> row_type;
typedef QVector<row_type> table_type;

class TableModel : public QAbstractTableModel {
    Q_OBJECT
    QML_ELEMENT

public:
    Q_PROPERTY(table_type model READ model WRITE setModel NOTIFY modelChanged);
    void setModel(const table_type &val);
    table_type model() const { return m_model; }
    Q_SIGNAL void modelChanged();

    Q_INVOKABLE QVector<int> getColumnWidths(int columns, int width);

    int rowCount(const QModelIndex & = QModelIndex()) const override
    {
        return m_model.size();
    }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    {
        return m_model[0].size();
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        switch (role) {
            case Qt::DisplayRole:
                return m_model[index.row()][index.column()];
            default:
                break;
        }

        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override
    {
        return { {Qt::DisplayRole, "display"} };
    }

private:
    table_type m_model;
};

#endif //ASCIITABLE_QT_TABLEMODEL_H
