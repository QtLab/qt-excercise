#pragma once

#include "pluginwindow.hh"
#include "citieswindow.hh"

#include <QMainWindow>
#include <QPointer>

#include <memory>

namespace Weather {

namespace Ui {
class MainWindow;
}

class ApplicationTools;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(ApplicationTools& tools, QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_actionE_xit_triggered();

	void on_actionPlugin_list_triggered();

	void on_actionSearch_cities_triggered();

private:
	Ui::MainWindow* mUi;
	Weather::ApplicationTools& mAppTools;
	QPointer<PluginWindow> mPluginWindow;
	QPointer<CitiesWindow> mCitiesWindow;
};

} // namespace Weather
