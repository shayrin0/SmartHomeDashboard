import QtQuick 2.15
import QtQuick.Controls 2.15

/// @file Main.qml
/// @brief Main entry point for the Smart Home Dashboard application
ApplicationWindow
{
   visible: true
   width: 640
   height: 480
   title: "Smart Home Dashboard"

   DashboardPage
   {
      anchors.fill: parent
      deviceViewModel: _deviceViewModel
   }
}
