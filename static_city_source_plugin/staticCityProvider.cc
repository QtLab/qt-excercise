#include "staticCityProvider.hh"

namespace Weather { namespace StaticCityProvider {

CityProvider::CityProvider(QObject* parent)
	: ICityProvider(parent)
{
}

ICityQuery* CityProvider::createQuery(QThread* queryThread)
{
	throw std::logic_error("Not implemented");
}

}}
