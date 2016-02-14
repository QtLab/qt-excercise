#include <plugin_interfaces_lib/i_city_provider.hh>

namespace Weather { namespace StaticCityProvider {

class CityProvider : public ICityProvider
{
	Q_OBJECT

public:
	CityProvider(QObject* parent = nullptr);

	virtual QString getName() const { return "Static City Provider"; }

	virtual ICityQuery* createQuery(QThread* queryThread);
};

}}
