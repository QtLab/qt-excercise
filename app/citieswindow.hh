#pragma once
#include <QDialog>

namespace Weather {

namespace Ui {
class CitiesWindow;
}

class ApplicationTools;
class ICityQuery;
class City;

class CitiesWindow : public QDialog
{
	Q_OBJECT

public:
	explicit CitiesWindow(ApplicationTools& tools, QWidget *parent = 0);
	~CitiesWindow();

private slots:
	void on_mSearchButton_clicked();
	void queryResults(QList<City>* cities);

private:

	void populateCityProviderSelector();
	void cancelQuery();
	void beginQuery();
	void resetSearchForm();
	void displayResults(const QList<City>& results);

	ApplicationTools& mAppTools;
	Ui::CitiesWindow *mUi;
	ICityQuery* mQueryInProgress = nullptr;
};


} // namespace Weather
