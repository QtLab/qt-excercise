#pragma once

#include <QObject>

namespace Weather
{

class IPlugin : public QObject
{
	Q_OBJECT
public:

	virtual ~IPlugin();

	virtual QString getName() const = 0;
	virtual QString getCategory() const = 0;

private:
};

}

Q_DECLARE_INTERFACE(Weather::IPlugin, "maciek.qt-excercise.IPlugin")
