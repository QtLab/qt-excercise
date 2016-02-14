#include "applicationtools.hh"

namespace Weather {

ApplicationTools::ApplicationTools(QDir pluginDir)
	: mPluginManager(pluginDir)
{
	mExtensionManager.addExtensionsFromPlugins(mPluginManager.getPlugins());
	mBackendThread.start();
}

ApplicationTools::~ApplicationTools()
{
	mBackendThread.quit();
	mBackendThread.wait();
}

} // namespace Weather
