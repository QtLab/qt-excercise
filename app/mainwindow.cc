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


void Weather::MainWindow::on_actionPlugin_list_triggered()
{
	if (!mPluginWindow)
	{
		mPluginWindow = new PluginWindow(mAppTools.getPluginManager());
		mPluginWindow->setAttribute(Qt::WA_DeleteOnClose, true);
		mPluginWindow->show();
	}
	else
	{
		mPluginWindow->raise();
	}
}
