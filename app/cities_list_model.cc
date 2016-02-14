#include "cities_list_model.hh"

#include <QMimeData>

namespace Weather {

void CitiesListModel::setData(const QList<CityData>& data)
{
	beginResetModel();
	mData = data;
	endResetModel();
}

QVariant CitiesListModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		const CityData& city = mData[index.row()];
		return city.mName + ", " + city.mCountry;
	}
	return {};
}

QStringList CitiesListModel::mimeTypes() const
{
	return {city_data_list_mime};
}

QMimeData* CitiesListModel::mimeData(const QModelIndexList& indexes) const
{
	QList<CityData> cities;
	cities.reserve(indexes.size());

	for(const QModelIndex& index : indexes)
	{
		cities.push_back(mData[index.row()]);
	}

	QByteArray data;
	QDataStream stream(&data, QIODevice::WriteOnly);
	stream << cities;

	QMimeData *mimeData = new QMimeData();
	mimeData->setData(city_data_list_mime, data);
	return mimeData;
}

Qt::ItemFlags CitiesListModel::flags(const QModelIndex& index) const
{
	return QAbstractListModel::flags(index) | Qt::ItemIsDragEnabled;
}

}
