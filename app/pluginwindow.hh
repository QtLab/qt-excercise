#pragma once

#include <QDialog>

#include <memory>

class QTreeWidget;

namespace Weather {

namespace Ui {
class PluginWindow;
}

class PluginManager;

class PluginWindow : public QDialog
{
	Q_OBJECT

public:
	explicit PluginWindow(const PluginManager& pman, QWidget *parent = 0);
	~PluginWindow();

private:

	void populate(QTreeWidget& widget, const PluginManager& pluginManager);

	std::unique_ptr<Ui::PluginWindow> mUi;
};

}

