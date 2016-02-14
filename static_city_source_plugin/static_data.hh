#pragma once
#include <plugin_interfaces_lib/i_city_provider.hh>

namespace Weather { namespace StaticCityProvider {

class StaticData
{
public:

	void ensureLoaded();

	QList<CityData> search(const QString& query) const;

private:

	void load();

	bool mLoaded = false;

	QList<CityData> mData;

};

}}
