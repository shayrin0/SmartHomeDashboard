import QtQuick 2.15

/// @file DeviceCard.qml
/// @brief A card component to display device information in the Smart Home Dashboard
Rectangle
{
   id: card

   width: parent.width
   height: 80

   color: "#f5f5f5"
   border.color: "#cccccc"
   radius: 10

   property string name
   property int type
   property bool isOn
   property double value

   Column
   {
      spacing: 4

      Text
      {
         text: card.name
         font.bold: true
      }

      Text
      {
         text:
         {
            switch (card.type)
            {
               case 0: return "Light: " + (card.isOn ? "On" : "Off")
               case 1: return "Thermostat: " + card.value.toFixed(1) + "°C"
               case 2: return "Humidity: " + card.value.toFixed(0) + "%"
               case 3: return "Motion: " + (card.value > 0 ? "Detected" : "None")
               default: return "Unknown"
            }
         }
      }
   }
}
