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
	return mData[index.row()];
}

bool CitiesTableModel::dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent)
{
	qDebug() << "drop!";
	return true;
}

bool CitiesTableModel::canDropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent) const
{
	qDebug() << "can drop? formats=" << data->formats();
	return true;
}

Qt::ItemFlags CitiesTableModel::flags(const QModelIndex& index) const
{
	return QAbstractItemModel::flags(index) | Qt::ItemIsDropEnabled;
}

}
