#include "mainwindow.hh"
#include "applicationtools.hh"

#include <QApplication>

#include <iostream>


int main(int argc, char** argv)
{
	std::cout << "Hello, world" << std::endl;

	QApplication app(argc, argv);

	Weather::ApplicationTools tools(app.applicationDirPath());
	Weather::MainWindow mainWindow(tools);

	mainWindow.show();

	return app.exec();
}

