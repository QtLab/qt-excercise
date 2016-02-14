#include "pluginwindow.hh"
#include "ui_pluginwindow.h"

#include <QTreeWidget>

namespace Weahter {

PluginWindow::PluginWindow(const PluginManager& pluginManager, QWidget *parent) :
	QDialog(parent),
	mUi(new Ui::PluginWindow)
{
	mUi->setupUi(this);
	populate(pluginManager);
}

PluginWindow::~PluginWindow()
{
}

void PluginWindow::populate(QTreeWidget& widget, const PluginManager& pluginmanager)
{
	widget.clear();


}

}

