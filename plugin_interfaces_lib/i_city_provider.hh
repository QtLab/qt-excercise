#pragma once

#include <QObject>

namespace Weather
{

class CityData
{
public:

	QString mName;
	quint64 mId = 0;
	QString mCountry;
};

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
