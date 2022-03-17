qt_add_library(ascii_table STATIC)
qt_add_qml_module(ascii_table
    URI AsciiTable
    VERSION 1.0
    SOURCES
    ascii_table.h ascii_table.cpp
)
