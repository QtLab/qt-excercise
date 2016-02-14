#pragma once

#include <QObject>

namespace Weather
{

class City
{
public:

	City(const QString name, quint64 id) : mName(name), mId(id) {}

	QString getName() const { return mName; }
	quint64 getId() const { return mId; }

private:

	QString mName;
	quint64 mId;
};

class ICityProvider : public QObject
{
public:

	virtual ~ICityProvider();

	virtual QList<City> findCities(const QString& query) const = 0;
};

}
