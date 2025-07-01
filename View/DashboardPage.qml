import QtQuick 2.15

/// @file DashboardPage.qml
/// @brief The main dashboard page displaying a list of devices
Item
{
   id: item

   property var deviceViewModel

   ListView
   {
      id: listView

      anchors.fill: parent
      model: item.deviceViewModel

      delegate: DeviceCard
      {
         required property var modelData
         name: modelData.name
         type: modelData.type
         isOn: modelData.isOn
         value: modelData.value
      }
   }
}
