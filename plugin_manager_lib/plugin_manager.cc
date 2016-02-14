#include "plugin_manager.hh"

#include <QDebug>

namespace Weather
{

PluginManager::PluginManager(QDir directory)
{
	qDebug() << "Looking for plugins in " << directory.absolutePath();

	QFileInfoList pluginFiles = directory.entryInfoList(
		QStringList{"*.so"}, QDir::Files);

	for(QFileInfo info : pluginFiles)
	{
		qDebug() << "Plugin found: " << info.absoluteFilePath();

		QPluginLoader loader(info.absoluteFilePath());

		QObject* instance = loader.instance();
		IPlugin* plugin = qobject_cast<IPlugin*>(instance);
		if (plugin)
		{
			qDebug() << "Loaded! name=" << plugin->getName() << ", category=" << plugin->getCategory();
		}
		else
		{
			qDebug() << "error loading plugin " << loader.errorString();
		}

	}
}

}
