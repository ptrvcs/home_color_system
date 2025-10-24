#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "lighting_viewmodel.hpp"
#include "dmx_controller.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    DmxController dmx;
    LightingViewModel viewModel(&dmx);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("viewModel", &viewModel);
    engine.load(QUrl(QStringLiteral("qrc:/app/ui/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
