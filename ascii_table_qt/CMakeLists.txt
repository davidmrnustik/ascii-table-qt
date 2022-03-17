cmake_minimum_required(VERSION 3.21)
project(ascii_table_qt)

set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /Users/davidmrnustik/Qt/6.3.0/macos/lib/cmake)

find_package(Qt6 6.3 COMPONENTS Core Quick Widgets REQUIRED)

qt_add_executable(appascii_table_qt main.cpp)
qt_add_qml_module(appascii_table_qt
        URI ascii_table_qt
        VERSION 1.0
        QML_FILES main.qml View.qml
)

add_subdirectory(AsciiTable)
add_subdirectory(TableModel)

target_link_libraries(appascii_table_qt PRIVATE Qt6::Core Qt6::Quick Qt6::Widgets ascii_tableplugin table_modelplugin)
