#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MockDataSource.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
	
    // Create and expose MockDataGenerator
    MockDataSource mockDataSource;
    engine.rootContext()->setContextProperty("mockDataSource", &mockDataSource);
	
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Qt6_Practice_VehicleDashboard", "Main");

    return app.exec();
}
