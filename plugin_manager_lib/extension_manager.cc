#include "extension_manager.hh"

#include <plugin_interfaces_lib/i_plugin.hh>

namespace Weather {

ExtensionManager::ExtensionManager()
{
}

void ExtensionManager::addExtensionsFromPlugins(const QList<IPlugin*> plugins)
{
	for(IPlugin* plugin : plugins)
	{
		Q_ASSERT(plugin);
		addExtensions(plugin->getExtensions());
	}
}

} // namespace Weather
