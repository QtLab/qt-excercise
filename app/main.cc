#include <plugin_manager_lib/plugin_manager.hh>

#include <QApplication>

#include <iostream>


int main(int argc, char** argv)
{
	std::cout << "Hello, world" << std::endl;

	QApplication app(argc, argv);

	Weather::PluginManager manager(app.applicationFilePath());

	return app.exec();
}

