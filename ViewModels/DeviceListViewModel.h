#ifndef DEVICE_LIST_VIEW_MODEL_H
#define DEVICE_LIST_VIEW_MODEL_H

#include "Models/DeviceDataProvider.h"

#include <QAbstractListModel>
#include <QObject>

/// @brief ViewModel for displaying a list of devices in the smart home dashboard.
/// This class provides the data for the device list view, including device names, types,
/// statuses, and values. It uses the DeviceDataProvider to fetch and update device data.
class DeviceListViewModel : public QAbstractListModel
{
   Q_OBJECT
public:
   enum DeviceRoles
   {
      NameRole = Qt::UserRole + 1,
      TypeRole,
      IsOnRole,
      ValueRole
   };

   explicit DeviceListViewModel(QObject *parent = nullptr);

   int rowCount(const QModelIndex &parent = QModelIndex()) const override;
   QVariant data(const QModelIndex &index, int role) const override;

   QHash<int, QByteArray> roleNames() const override;

private slots:
   void onDevicesUpdated();

private:
   DeviceDataProvider m_dataProvider;
};

#endif // DEVICE_LIST_VIEW_MODEL_H
