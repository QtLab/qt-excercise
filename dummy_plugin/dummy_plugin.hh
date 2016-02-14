#pragma once

#include <plugin_interfaces_lib/i_plugin.hh>

namespace Weather {

class DummyPlugin : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(Weather::IPlugin)
	Q_PLUGIN_METADATA(IID "maciek.qt-excercise.DummyPlugin")

public:

	QString getName() const override { return "Dummy"; }
	QString getCategory() const override { return "Dummy"; }
	QString getDescription() const override { return "Dummy plugin"; }

private:
};

}
