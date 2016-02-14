#include "plugin.hh"

#include "staticCityProvider.hh"

namespace Weather { namespace StaticCityProvider {

QList<QObject*> Plugin::getExtensions()
{
	return { new CityProvider(this) };
}

}}
