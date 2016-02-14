#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include "applicationtools.hh"

namespace Weather {

MainWindow::MainWindow(ApplicationTools& tools, QWidget *parent) :
	QMainWindow(parent),
	mUi(new Ui::MainWindow),
	mAppTools(tools)
{
	mUi->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete mUi;
}

void MainWindow::on_actionE_xit_triggered()
{
	close();
}

} // namespace Weather

template<typename DialogType, typename ... Args>
void showOrCreateDialog(QPointer<DialogType>& pointer, Args&& ... args)
{
	if (!pointer)
	{
		pointer = new DialogType(std::forward<Args>(args)...);
		pointer->setAttribute(Qt::WA_DeleteOnClose, true);
		pointer->show();
	}
	else
	{
		pointer->raise();
	}
}

void Weather::MainWindow::on_actionPlugin_list_triggered()
{
	showOrCreateDialog(mPluginWindow, mAppTools.getPluginManager());
}

void Weather::MainWindow::on_actionSearch_cities_triggered()
{
	showOrCreateDialog(mCitiesWindow, mAppTools);
}
