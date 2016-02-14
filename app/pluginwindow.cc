#include "pluginwindow.hh"
#include "ui_pluginwindow.h"

#include <plugin_manager_lib/plugin_manager.hh>

#include <plugin_interfaces_lib/i_plugin.hh>

#include <QTreeWidget>
#include <QMap>

namespace Weather {

PluginWindow::PluginWindow(const PluginManager& pluginManager, QWidget *parent) :
	QDialog(parent),
	mUi(new Ui::PluginWindow)
{
	mUi->setupUi(this);
	populate(*mUi->mPluginTreeWidget, pluginManager);
}

PluginWindow::~PluginWindow()
{
}

void PluginWindow::populate(QTreeWidget& widget, const PluginManager& pluginManager)
{
	widget.clear();

	QMap<QString, QTreeWidgetItem*> categoryItems;

	for(IPlugin* plugin : pluginManager.getPlugins())
	{
		Q_ASSERT(plugin);

		QTreeWidgetItem* categoryItem = nullptr;
		auto it = categoryItems.find(plugin->getCategory());
		if (it == categoryItems.end())
		{
			categoryItem = new QTreeWidgetItem(&widget);
			categoryItem->setText(0, plugin->getCategory());
			categoryItem->setExpanded(true);

			categoryItems.insert(plugin->getCategory(), categoryItem);
		}
		else
		{
			categoryItem = it.value();
		}
		new QTreeWidgetItem(categoryItem, QStringList{plugin->getName(), plugin->getDescription()});
	}
}

}

