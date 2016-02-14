#pragma once
#include <plugin_interfaces_lib/i_city_provider.hh>

namespace Weather { namespace StaticCityProvider {

class StaticData;

class Query : public ICityQuery
{
	Q_OBJECT

public:

	Query(StaticData& staticData);
	~Query();

public slots:

	void startQuery(QString query) override;

private:

	StaticData& mStaticData;
};

}}
