#include "query.hh"

#include <QTimer>
#include <QDebug>

namespace Weather { namespace StaticCityProvider {

Query::Query()
{
	qDebug() << "Static city query created";
}

Query::~Query()
{
	qDebug() << "Static city query destroyed";
}

void Query::startQuery(QString query)
{
	qDebug() << "Static city query starts";

	QTimer::singleShot(5000, this, &Query::sendResults);
}

void Query::sendResults()
{
	QList<City>* result = new QList<City>;

	result->push_back(City("aaaa", 1));
	result->push_back(City("bbbb", 2));

	qDebug() << "Sending results";
	emit resultsReceived(result);
	deleteLater();
}

}}
