#pragma once

#include <plugin_interfaces_lib/i_city_provider.hh>

#include <QAbstractListModel>

namespace Weather {

class CitiesListModel : public QAbstractListModel
{
	Q_OBJECT
public:

	void setData(const QList<CityData>& data);

	// QAbstractListModel

	int rowCount(const QModelIndex& parent = QModelIndex()) const override { return mData.size(); }
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	// drag'n'drop support
	QStringList mimeTypes() const override;
	QMimeData* mimeData(const QModelIndexList& indexes) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;

private:

	QList<CityData> mData;
};

}
