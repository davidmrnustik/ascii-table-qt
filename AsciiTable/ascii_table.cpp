//
// Created by David Mrnustik on 14/3/22.
//

#include <iostream>
#include <sstream>
#include "ascii_table.h"

AsciiTable::AsciiTable(QObject *parent) : QObject(parent)
{
    createTable();
}

table_type AsciiTable::getData()
{
    return m_table;
}

void AsciiTable::formatTable()
{
    if (m_table.empty())
        createTable();

    table_type formatted_table;
    row_type header;

    for(int i = 0; i < m_format; i++)
        header.append(m_table[0]);

    formatted_table.append(header);
    m_table.pop_front();

    size_t table_size = m_table.size();
    size_t row_size = table_size / m_format;

    for(size_t i = 0; i < row_size; i++)
    {
        row_type row;
        for(int f = 0; f < m_format; f++)
        {
            for(auto & c : m_table[i  + row_size * f])
                row.append(c);
        }
        formatted_table.append(row);
    }
    m_table = formatted_table;
    recalculateColumns();
}

void AsciiTable::createTable()
{
    for(int i = 0; i < DEFAULT_TABLE_SIZE + 1; i++)
    {
        row_type row;
        std::string s = std::to_string(i);
        QString n8 = QString::fromStdString(getStringFromInt(s, num_base::o));
        QString n16 = QString::fromStdString(getStringFromInt(s, num_base::h));
        QChar c = i > 31 ? QChar(i) : '-';
        QString qs = QString::fromStdString(s);
        row.append({ qs, n8, n16, QString::fromStdString(binString(i)), c});
        m_table.push_back(row);
    }

    row_type header {{"Dec", "Oct", "Hex", "Binary", "C"}};
    m_table.prepend(header);
    recalculateColumns();
}

void AsciiTable::printTable()
{
    for(const row_type& row: m_table)
    {
        for(const QString& col: row)
            std::cout << col.toStdString() << " | ";
        std::cout << "\n";
    }
}

std::string AsciiTable::getStringFromInt(const std::string &s, num_base base)
{
    std::istringstream iss(s);
    std::ostringstream oss;

    int number;
    std::string result;
    iss >> std::dec >> number;

    switch (base) {
        case num_base::o:
            oss << std::oct << number;
            result = oss.str();
            break;
        case num_base::h:
            oss << std::hex << number;
            result = oss.str();
            break;
        default:
            iss >> std::dec >> result;
    }

    return result;
}

std::string AsciiTable::binString(char a)
{
    static char b[9];
    int i;

    i = 0;

    while(i<8)
    {
        b[i] = a&0x80 ? '1' : '0';
        a <<= 1;
        i++;
    }
    b[i] = '\0';

    return b;
}

void AsciiTable::setFormat(const int &val)
{
    m_format = val;
    emit formatChanged();

    formatTable();
}

void AsciiTable::recalculateColumns()
{
    m_columns = DEFAULT_COLUMN_SIZE * m_format;
}

int AsciiTable::getColumns()
{
    return m_columns;
}
