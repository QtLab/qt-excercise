#pragma once

#include <QObject>
#include <QDir>
#include <QPluginLoader>

namespace Weather
{

class IPlugin;

class PluginManager : public QObject
{
	Q_OBJECT
public:

	PluginManager(QDir directory);

	const QList<IPlugin*> getPlugins() const { return mPlugins; }

private:

	QList<IPlugin*> mPlugins;

};

}
