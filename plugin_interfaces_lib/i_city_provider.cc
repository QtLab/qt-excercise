#include "i_city_provider.hh"

namespace Weather
{

ICityProvider::ICityProvider(QObject* parent)
	: QObject(parent)
{
}

ICityProvider::~ICityProvider()
{
}


}
