//
// Created by David Mrnustik on 16/3/22.
//
#include "TableModel.h"

void TableModel::setModel(const table_type &val) {
    if (m_model == val)
        return;

    m_model = val;
    emit modelChanged();
}

QVector<int> TableModel::getColumnWidths(int columns, int width) {
    QVector<int> base { 50, 50, 50, 100, 25 };
    QVector<float> coefficient;
    QVector<int> widths(width/columns, columns);

    for(int i = 0; i < base.size(); i++)
    {
        float max = *std::max_element(base.begin(), base.end());
        coefficient.push_back(base[i]/max);
    }

    return widths;
}
