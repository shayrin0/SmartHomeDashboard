#include "DeviceListViewModel.h"

/// @brief Constructor for DeviceListViewModel
/// @param parent The parent QObject, defaults to nullptr
DeviceListViewModel::DeviceListViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
   connect(&m_dataProvider, &DeviceDataProvider::devicesUpdated,
           this, &DeviceListViewModel::onDevicesUpdated);
}

/// @brief Returns the number of rows in the model
/// @param parent The parent index, defaults to an invalid index
/// @return The number of devices in the data provider
int DeviceListViewModel::rowCount(const QModelIndex &) const
{
   return m_dataProvider.devices().size();
}

/// @brief Returns the data for a given index and role
/// @param index The model index for which data is requested
/// @param role The role for which data is requested
/// @return The data for the specified index and role, or an invalid QVariant if the index is invalid
QVariant DeviceListViewModel::data(const QModelIndex &index, int role) const
{
   if (!index.isValid() || index.row() >= m_dataProvider.devices().size())
   {
      return QVariant {};
   }

   const Device &device = m_dataProvider.devices().at(index.row());

   QVariant result;

   switch (role)
   {
      case NameRole:
         result = QVariant::fromValue(device.name);
         break;
      case TypeRole:
         result = QVariant::fromValue(device.type);
         break;
      case IsOnRole:
         result = QVariant::fromValue(device.isOn);
         break;
      case ValueRole:
         result = QVariant::fromValue(device.value);
         break;
      default:
         result = QVariant {};
         break;
   }

   return result;
}

/// @brief Returns the role names for the model
/// @return A hash mapping role IDs to their names
QHash<int, QByteArray> DeviceListViewModel::roleNames() const
{
   QHash<int, QByteArray> roles;

   roles[NameRole] = "name";
   roles[TypeRole] = "type";
   roles[IsOnRole] = "isOn";
   roles[ValueRole] = "value";

   return roles;
}

/// @brief Slot that is called when the devices are updated
void DeviceListViewModel::onDevicesUpdated()
{
   emit dataChanged(index(0), index(rowCount() - 1));
}
