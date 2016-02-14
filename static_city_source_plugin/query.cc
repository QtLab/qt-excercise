#include "query.hh"

#include "static_data.hh"

#include <QDebug>

namespace Weather { namespace StaticCityProvider {

Query::Query(StaticData& staticData)
	: mStaticData(staticData)
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

	try
	{
		mStaticData.ensureLoaded();

		QList<CityData>* result = new QList<CityData>;
		*result = mStaticData.search(query);

		qDebug() << "Query completed, results: " << result->size();
		emit resultsReceived(result, {});
	}
	catch(const std::exception& e)
	{
		emit resultsReceived(nullptr, e.what());
	}
}

}}
