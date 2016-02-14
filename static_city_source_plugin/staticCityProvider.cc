#include "staticCityProvider.hh"

#include "query.hh"

namespace Weather { namespace StaticCityProvider {

CityProvider::CityProvider(QObject* parent)
	: ICityProvider(parent)
{
}

ICityQuery* CityProvider::createQuery(QThread* queryThread)
{
	Query* query = new Query;
	query->moveToThread(queryThread);

	return query;
}

}}
