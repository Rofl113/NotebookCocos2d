#include <iostream>
// Qt lib
#include <QApplication>
// Core lib
#include <Core/Core.h>
// Main
#include "NotebookCocos2d/CoreAppDelegateNotebookCocos2d.h"
#include "NotebookCocos2d/Scenes/MainWindow.h"

namespace
{

enum class ErrorApp
{
	NONE = 0,
	BAD_INIT = -1
};

} // END namespace


int main(const int argc, const char** argv)
{
	auto argcTemp = argc;
	auto argvTemp = const_cast<char**>(argv);
	QApplication app (argcTemp, argvTemp);
	// Создаем главное окно
	MainWindow w;
	// Создаем Ядро
	Core core (std::unique_ptr<ICoreAppDelegate>(new CoreAppDelegateNotebookCocos2d(w.getViewCore())));
	/// Initialize
	{
		const bool status = core.initialize(argc, argv);
		if (not status)
		{
			// Error Initialize
			return static_cast<int>(ErrorApp::BAD_INIT);
		}
	}
	// Показываем Окно
	w.show();
	// Запуск Ядро
	return core.run();
}
