#pragma once
#include <QDialog>

namespace Weather {

namespace Ui {
class CitiesWindow;
}

class ApplicationTools;

class CitiesWindow : public QDialog
{
	Q_OBJECT

public:
	explicit CitiesWindow(ApplicationTools& tools, QWidget *parent = 0);
	~CitiesWindow();

private:

	void populateCityProviderSelector();


	ApplicationTools& mAppTools;
	Ui::CitiesWindow *mUi;
};


} // namespace Weather
