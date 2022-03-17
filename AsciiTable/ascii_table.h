//
// Created by David Mrnustik on 14/3/22.
//

#ifndef ASCIITABLE_QT_ASCII_TABLE_H
#define ASCIITABLE_QT_ASCII_TABLE_H
#define DEFAULT_COLUMN_SIZE 5
#define DEFAULT_TABLE_SIZE 128

#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QJsonObject>

typedef QVector<QString> row_type;
typedef QVector<row_type> table_type;
enum class num_base { o, d, h };

class AsciiTable : public QObject{
    Q_OBJECT
    QML_ELEMENT

public:
    Q_PROPERTY(int format READ format WRITE setFormat NOTIFY formatChanged);
    void setFormat(const int &val);
    int format() const { return m_format; }
    Q_SIGNAL void formatChanged();

    explicit AsciiTable(QObject *parent = nullptr);
    void createTable();
    void formatTable();
    Q_INVOKABLE void printTable();
    Q_INVOKABLE table_type getData();
    Q_INVOKABLE int getColumns();

private:
    static std::string getStringFromInt(const std::string &s, num_base base);
    static std::string binString(char a);
    void recalculateColumns();
    table_type m_table;
    int m_format = 1;
    int m_columns;
};

#endif //ASCIITABLE_QT_ASCII_TABLE_H
