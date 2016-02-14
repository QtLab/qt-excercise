#pragma once

#include <QObject>

namespace Weather {

class IPlugin;

class ExtensionManager
{
public:
	ExtensionManager();


	void addExtensionsFromPlugins(const QList<IPlugin*> plugins);

	void addExtensions(const QList<QObject*> extensions)
	{
		mExtensions.append(extensions);
	}

	template<typename T>
	QList<T*> findExtensions() const
	{
		QList<T*> result;
		for(QObject* extension : mExtensions)
		{
			T* asT = qobject_cast<T*>(extension);
			if (asT)
			{
				result.push_back(asT);
			}
		}
		return result;
	}

private:

	QList<QObject*> mExtensions;
};

} // namespace Weather

