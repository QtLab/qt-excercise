#include "cities_table_model.hh"

#include <QMimeData>
#include <QDebug>

namespace Weather {

CitiesTableModel::CitiesTableModel(QObject* parent)
	: QAbstractItemModel(parent)
{
}

QModelIndex CitiesTableModel::index(int row, int column, const QModelIndex& parent) const
{
	Q_ASSERT(parent == QModelIndex());

	return createIndex(row, column);
}

QVariant CitiesTableModel::data(const QModelIndex& index, int role) const
{
	// TODO real data fetching
	if (role == Qt::DisplayRole)
	{
		return mData[index.row()].mName;
	}

	return {};
}

QVariant CitiesTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		return "City";
	}

	return {};
}

bool CitiesTableModel::dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent)
{
	if (!data->hasFormat(city_data_list_mime))
	{
		return false;
	}
	if (action == Qt::IgnoreAction)
	{
		return true;
	}


	QByteArray encodedData = data->data(city_data_list_mime);
	QDataStream stream(&encodedData, QIODevice::ReadOnly);

	QList<CityData> newData;
	stream >> newData;

	if (newData.empty())
	{
		return false;
	}

	int firstRow = row;
	if (row == -1 && parent.isValid())
	{
		firstRow = parent.row();
	}

	if (firstRow == -1)
	{
		// apends
		beginInsertRows({}, mData.size(), mData.size() + newData.size()-1);
		mData.append(newData);
	}
	else
	{
		// insert in the middle
		beginInsertRows({}, firstRow, firstRow+newData.size()-1);

		for(int i = 0; i < newData.size(); i++)
		{
			mData.insert(firstRow + i, newData[i]);
		}
	}
	endInsertRows();

	return true;
}

bool CitiesTableModel::canDropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent) const
{
	return data->formats().contains(city_data_list_mime);
}

Qt::ItemFlags CitiesTableModel::flags(const QModelIndex& index) const
{
	return QAbstractItemModel::flags(index) | Qt::ItemIsDropEnabled;
//	return QAbstractItemModel::flags(index);
}

}
