#include "DeviceDataProvider.h"

#include <QRandomGenerator>

/// @brief Constructor for DeviceDataProvider
/// @param parent The parent QObject, defaults to nullptr
DeviceDataProvider::DeviceDataProvider(QObject *parent)
   : QObject(parent)
{
   // Initialize with sample devices
   m_devices = {
      {"Living Room Light", DeviceType::Light, false, 0.0},
      {"Bedroom Thermostat", DeviceType::Thermostat, true, 22.5},
      {"Basement Humidity", DeviceType::HumiditySensor, false, 45.0},
      {"Front Door Motion", DeviceType::MotionDetector, false, 0.0}
   };

   // Setup timer to update sensor values every 3 seconds
   connect(&m_updateTimer, &QTimer::timeout, this, &DeviceDataProvider::updateSensorValues);
   m_updateTimer.start(3000);
}

/// @brief This function returns the list of devices managed by the provider
/// @return A constant reference to the QVector of Device objects
const QVector<Device> &DeviceDataProvider::devices() const
{
   return m_devices;
}

/// @brief Updates the sensor values for devices periodically
void DeviceDataProvider::updateSensorValues()
{
   // Simulate sensor updates for humidity, temperature, motion randomly
   for (Device &device : m_devices)
   {
      switch (device.type)
      {
         case DeviceType::HumiditySensor:
            device.value = 40 + QRandomGenerator::global()->bounded(20); // 40-60%
            break;

         case DeviceType::Thermostat:
            device.value = 20 + QRandomGenerator::global()->bounded(5); // 20-25°C
            break;

         case DeviceType::MotionDetector:
            device.value = QRandomGenerator::global()->bounded(2); // 0 or 1 (no motion/motion)
            break;

         case DeviceType::Light:
            // Lights don't change value here, status toggled manually later
            break;

         default:
            break;
      }
   }

   emit devicesUpdated();
}
