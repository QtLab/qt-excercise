#pragma once

#include <plugin_interfaces_lib/i_city_provider.hh>

#include <QAbstractItemModel>

namespace Weather {

class CitiesTableModel : public QAbstractItemModel
{
	Q_OBJECT
public:

	CitiesTableModel(QObject* parent = nullptr);

	QModelIndex index(int row, int column,
					const QModelIndex& parent = QModelIndex()) const override;

	QModelIndex parent(const QModelIndex& child) const override { return QModelIndex(); }
	int rowCount(const QModelIndex& parent = QModelIndex()) const override { return mData.size(); }
	int columnCount(const QModelIndex& parent = QModelIndex()) const override { return 1; }

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	Qt::DropActions supportedDropActions() const override { return Qt::CopyAction|Qt::MoveAction; }

	bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex & parent) override;
	bool canDropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex & parent) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;

private:

	// TODO actual, live data source goes here
	QList<CityData> mData;
};

}
