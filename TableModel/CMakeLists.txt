qt_add_library(table_model STATIC)
qt_add_qml_module(table_model
    URI TableModel
    VERSION 1.0
    SOURCES
    TableModel.h TableModel.cpp
)
