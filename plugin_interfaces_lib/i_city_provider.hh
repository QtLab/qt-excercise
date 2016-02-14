#pragma once

#include <QObject>
#include <QDataStream>

namespace Weather
{

class CityData
{
public:

	QString mName;
	quint64 mId = 0;
	QString mCountry;
};

QDataStream& operator<<(QDataStream& s, const CityData& city);
QDataStream& operator>>(QDataStream& s, CityData& city);
static constexpr const char* city_data_mime = "application/x-weather-city-data";
static constexpr const char* city_data_list_mime = "application/x-weather-city-data-list";

class ICityQuery : public QObject
{
	Q_OBJECT
signals:

	void resultsReceived(QList<CityData>* cities, QString error);

public slots:

	virtual void startQuery(QString query) = 0;
};

class ICityProvider : public QObject
{
	Q_OBJECT
public:

	ICityProvider(QObject* parent);

	virtual ~ICityProvider();

	virtual QString getName() const = 0;
	virtual ICityQuery* createQuery(QThread* queryThread) = 0;
};

}
