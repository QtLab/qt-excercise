#pragma once

#include <plugin_manager_lib/plugin_manager.hh>

#include <QThread>

namespace Weather {

class ApplicationTools
{
public:
	ApplicationTools(QDir pluginDir);

	const PluginManager& getPluginManager() const { return mPluginManager; }

private:

	PluginManager mPluginManager;
	QThread mBackedThread;
};

} // namespace Weather
