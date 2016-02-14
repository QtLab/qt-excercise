#include "applicationtools.hh"

namespace Weather {

ApplicationTools::ApplicationTools(QDir pluginDir)
	: mPluginManager(pluginDir)
{
}

} // namespace Weather
