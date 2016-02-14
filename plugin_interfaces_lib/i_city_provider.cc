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

QDataStream& operator<<(QDataStream& s, const CityData& city)
{
	return s << city.mId << city.mName << city.mCountry;
}

QDataStream& operator>>(QDataStream& s, CityData& city)
{
	return s >> city.mId >> city.mName >> city.mCountry;
}

}
