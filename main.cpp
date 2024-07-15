#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "appConfig.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    AppConfig config;
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qtApp/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
