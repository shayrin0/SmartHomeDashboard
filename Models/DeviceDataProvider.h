#ifndef DEVICE_DATA_PROVIDER_H
#define DEVICE_DATA_PROVIDER_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include "Device.h"

/// @brief Class that provides device data for the smart home dashboard.
/// It simulates device updates and provides a list of devices.
/// The data is updated periodically to simulate real-time changes.
class DeviceDataProvider : public QObject
{
   Q_OBJECT
public:
   explicit DeviceDataProvider(QObject *parent = nullptr);

   const QVector<Device> &devices() const;

signals:
   void devicesUpdated();

private slots:
   void updateSensorValues();

private:
   QVector<Device> m_devices;
   QTimer m_updateTimer;
};

#endif // DEVICE_DATA_PROVIDER_H
