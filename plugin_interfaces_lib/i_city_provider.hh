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

class ICityQuery : public QObject
{
	Q_OBJECT
signals:

	void resultsReceived(QList<City>* cities);

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
