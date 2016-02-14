#pragma once

#include <plugin_interfaces_lib/i_plugin.hh>

namespace Weather { namespace StaticCityProvider {

class Plugin : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(Weather::IPlugin)
	Q_PLUGIN_METADATA(IID "maciek.qt-excercise.StaticCityProviderPlugin")

public:

	QString getName() const override { return "Static City Provider"; }
	QString getCategory() const override { return "City Provider"; }
	QString getDescription() const override { return "City source based on a static file"; }

private:
};

}}
