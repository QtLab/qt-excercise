#include "citieswindow.hh"
#include "ui_citieswindow.h"

#include "applicationtools.hh"

#include <plugin_interfaces_lib/i_city_provider.hh>

#include <QComboBox>
#include <QMessageBox>

#include <memory>

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

	if (mQueryInProgress)
	{
		cancelQuery();
	}
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

void CitiesWindow::on_mSearchButton_clicked()
{
	if (mQueryInProgress)
	{
		cancelQuery();
		resetSearchForm();
	}
	else
	{
		beginQuery();
	}
}

void CitiesWindow::queryResults(QList<City>* cities)
{
	Q_ASSERT(mQueryInProgress);

	mQueryInProgress = nullptr;

	std::unique_ptr<QList<City>> results(cities);
	resetSearchForm();

	displayResults(*results);
}

void CitiesWindow::cancelQuery()
{
	Q_ASSERT(mQueryInProgress);

	disconnect(mQueryInProgress);
	QMetaObject::invokeMethod(mQueryInProgress, "deleteLater");
	mQueryInProgress = nullptr;
}

void CitiesWindow::beginQuery()
{
	Q_ASSERT(!mQueryInProgress);

	QString queryText = mUi->mQueryLineEdit->text().trimmed();
	if (queryText.isEmpty())
	{
		QMessageBox::critical(
			this, "Query error", "Query can't be empty!");
		return;
	}

	void* data = mUi->mProviderSelector->currentData().value<void*>();
	ICityProvider* provider = static_cast<ICityProvider*>(data);

	mQueryInProgress = provider->createQuery(mAppTools.getBackendThread());

	connect(mQueryInProgress, SIGNAL(resultsReceived(QList<City>*)), SLOT(queryResults(QList<City>*)));

	QMetaObject::invokeMethod(mQueryInProgress, "startQuery", Q_ARG(QString, queryText));

	mUi->mQueryLineEdit->setEnabled(false);
	mUi->mProviderSelector->setEnabled(false);
	mUi->mSearchButton->setText("Cancel query");
}

void CitiesWindow::resetSearchForm()
{
	mUi->mQueryLineEdit->setEnabled(true);
	mUi->mProviderSelector->setEnabled(true);
	mUi->mSearchButton->setText("Search");
}

void CitiesWindow::displayResults(const QList<City>& results)
{
	mUi->mResultList->clear();

	for(const City& city : results)
	{
		new QListWidgetItem(city.getName(), mUi->mResultList);
	}
}

} // namespace Weather

