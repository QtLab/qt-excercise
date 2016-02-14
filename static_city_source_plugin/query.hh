#include <plugin_interfaces_lib/i_city_provider.hh>

namespace Weather { namespace StaticCityProvider {

class Query : public ICityQuery
{
	Q_OBJECT

public:

	Query();
	~Query();

public slots:

	void startQuery(QString query) override;

private slots:

	void sendResults();
};

}}
