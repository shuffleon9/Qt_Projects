#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include "PlayerController.h"
#include "ArtistModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon("./Qt6_App_MediaPlayer/assets/icons/app_icon.ico"));

    PlayerController* playerController = new PlayerController(&app);
    qmlRegisterSingletonInstance("com.PlayerController", 1, 0, "PlayerController", playerController);

    ArtistModel artistModel;
    qmlRegisterSingletonInstance("com.ArtistModel", 1, 0, "ArtistModel", &artistModel);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Qt6_App_MediaPlayer", "Main");

    return app.exec();
}
