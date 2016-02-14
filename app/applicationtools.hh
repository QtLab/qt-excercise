#pragma once

#include <plugin_manager_lib/plugin_manager.hh>
#include <plugin_manager_lib/extension_manager.hh>

#include <QThread>

namespace Weather {

class ApplicationTools
{
public:
	ApplicationTools(QDir pluginDir);
	~ApplicationTools();

	const PluginManager& getPluginManager() const { return mPluginManager; }
	const ExtensionManager& getExtensionManager() const { return mExtensionManager; }
	QThread* getBackendThread() { return &mBackendThread; }

private:

	PluginManager mPluginManager;
	ExtensionManager mExtensionManager;
	QThread mBackendThread;
};

} // namespace Weather
