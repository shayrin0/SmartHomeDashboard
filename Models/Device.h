#ifndef DEVICE_H
#define DEVICE_H

#include <QString>

/// @brief Enumeration for different types of devices in the smart home system.
enum class DeviceType
{
   Light,
   Thermostat,
   HumiditySensor,
   MotionDetector
};

/// @brief Structure representing a device in the smart home system.
/// Contains the device's name, type, status (on/off), and a value
struct Device
{
   QString name;
   DeviceType type;
   bool isOn;
   double value;
};

#endif // DEVICE_H
