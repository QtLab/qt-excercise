#pragma once

#include <QDialog>

namespace Ui {
class PluginWindow;
}

class QTreeWidget;

namespace Weahter {

class PluginManager;

class PluginWindow : public QDialog
{
	Q_OBJECT

public:
	explicit PluginWindow(const PluginManager& pman, QWidget *parent = 0);
	~PluginWindow();

private:

	void populate(QTreeWidget& widget, const PluginManager& pluginmanager);

	std::unique_ptr<Ui::PluginWindow> mUi;
};

}

