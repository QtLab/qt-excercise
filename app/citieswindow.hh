#pragma once

#include "cities_list_model.hh"

#include <QDialog>

namespace Weather {

namespace Ui {
class CitiesWindow;
}

class ApplicationTools;
class ICityQuery;
class CityData;

class CitiesWindow : public QDialog
{
	Q_OBJECT

public:
	explicit CitiesWindow(ApplicationTools& tools, QWidget *parent = 0);
	~CitiesWindow();

private slots:
	void on_mSearchButton_clicked();
	void queryResults(QList<CityData>* cities, QString error);

private:

	void populateCityProviderSelector();
	void cancelQuery();
	void beginQuery();
	void resetSearchForm();
	void displayResults(const QList<CityData>& results);

	ApplicationTools& mAppTools;
	Ui::CitiesWindow *mUi;
	ICityQuery* mQueryInProgress = nullptr;
	CitiesListModel mCitiesModel;
};


} // namespace Weather
