#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    engine.load(QUrl("ascii_table_qt/main.qml"));
    engine.addImportPath(":qrc/ascii_table_qt/");
    engine.load(QUrl("qrc:/ascii_table_qt/main.qml"));

    return app.exec();
}
