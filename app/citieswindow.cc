#include "citieswindow.hh"
#include "ui_citieswindow.h"

#include "applicationtools.hh"

#include <plugin_interfaces_lib/i_city_provider.hh>

#include <QComboBox>

namespace Weather {

CitiesWindow::CitiesWindow(ApplicationTools& tools, QWidget *parent) :
	QDialog(parent),
	mAppTools(tools),
	mUi(new Ui::CitiesWindow)
{
	mUi->setupUi(this);
	populateCityProviderSelector();
}

CitiesWindow::~CitiesWindow()
{
	delete mUi;
}

void CitiesWindow::populateCityProviderSelector()
{
	QComboBox& combo = *mUi->mProviderSelector;

	auto cityProviders = mAppTools.getExtensionManager().findExtensions<ICityProvider>();

	combo.clear();

	for(ICityProvider* provider : cityProviders)
	{
		Q_ASSERT(provider);
		combo.addItem(provider->getName(), QVariant::fromValue<void*>(provider));
	}

	mUi->mSearchButton->setEnabled(combo.count() > 0);
}

} // namespace Weather
