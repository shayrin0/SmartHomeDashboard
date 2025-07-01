#include "ViewModels/DeviceListViewModel.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

/// @brief Main function for the Smart Home Dashboard application.
/// Initializes the application, sets up the QML engine, and loads the main QML file
/// @param argc
/// @param argv 
/// @return The exit code of the application
int main(int argc, char *argv[])
{
   QGuiApplication app(argc, argv);

   QQmlApplicationEngine engine;

   DeviceListViewModel deviceViewModel;
   engine.rootContext()->setContextProperty("_deviceViewModel", &deviceViewModel);

   QObject::connect(
      &engine,
      &QQmlApplicationEngine::objectCreationFailed,
      &app,
      []()
      { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);
   engine.loadFromModule("SmartHomeDashboard", "Main");

   return app.exec();
}
