#include "static_data.hh"

#include <QFile>
#include <QtEndian>
#include <QJsonDocument>
#include <QJsonObject>

#include <exception>
#include <string>

namespace Weather { namespace StaticCityProvider {

void StaticData::ensureLoaded()
{
	if(!mLoaded)
	{
		load();
	}
}

QList<CityData> StaticData::search(const QString& query) const
{
	QList<CityData> result;

	QString queryLower = query.toLower();

	for(const CityData& city : mData)
	{
		if (city.mName.toLower().startsWith(queryLower))
		{
			result.push_back(city);
		}
	}

	return result;
}


static CityData cityFromJson(const QJsonDocument& doc)
{
	CityData city;
	QJsonObject obj = doc.object();

	city.mId = obj["_id"].toInt();
	city.mCountry = obj["country"].toString();
	city.mName = obj["name"].toString();

	return city;
}

void StaticData::load()
{
	QFile dataFile(":/static_city_source_plugin/city.list.json");
	if (!dataFile.open(QFile::ReadOnly))
	{
		throw std::runtime_error("Failed to load file: " + dataFile.errorString().toStdString());
	}

	// every line of the file contains separate JSON object
	QList<CityData> data;
	QByteArray line = dataFile.readLine();
	unsigned lineNum = 1;
	while(!line.isEmpty())
	{
		QJsonParseError parseError;
		QJsonDocument document = QJsonDocument::fromJson(line, &parseError);
		if (parseError.error != QJsonParseError::NoError)
		{
			throw std::runtime_error("Failed to parse JSON data: " + parseError.errorString().toStdString()
				+ " at line " + std::to_string(lineNum));
		}

		data.push_back(cityFromJson(document));

		line = dataFile.readLine();
		lineNum++;
	}

	mLoaded = true;
	mData.swap(data);
}

}}
