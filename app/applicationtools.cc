#include "applicationtools.hh"

namespace Weather {

ApplicationTools::ApplicationTools(QDir pluginDir)
	: mPluginManager(pluginDir)
{
	mExtensionManager.addExtensionsFromPlugins(mPluginManager.getPlugins());
}

} // namespace Weather
