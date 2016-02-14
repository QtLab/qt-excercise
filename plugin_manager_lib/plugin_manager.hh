#pragma once

#include "i_plugin.hh"

#include <QObject>
#include <QDir>
#include <QPluginLoader>

namespace Weather
{

class PluginManager : public QObject
{
	Q_OBJECT
public:

	PluginManager(QDir directory);

private:

};

}
