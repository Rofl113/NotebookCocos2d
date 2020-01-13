#include <iostream>
// Sm lib
#include <StateMachine/ManagerMessages.h> ///< TODO: надо разобраться по чему без этого не собирается!
// Core lib
#include <Core/Core.h>
#include <Core/SessionApp.h> ///< TODO: надо разобраться по чему без этого не собирается!
#include <Core/IFactoryScene.h> ///< TODO: надо разобраться по чему без этого не собирается!
#include <Core/IManagerDescriptionScene.h> ///< TODO: надо разобраться по чему без этого не собирается!
#include <Core/IRender.h> ///< TODO: надо разобраться по чему без этого не собирается!
#include <Core/IManagerScene.h> ///< TODO: надо разобраться по чему без этого не собирается!
// Main
#include "NotebookCocos2d/CoreAppDelegateNotebookCocos2d.h"

namespace
{

enum class ErrorApp
{
	BAD_INIT = -1
};

} // END namespace


int main(const int argc, const char* argv[])
{
	Core core (std::unique_ptr<ICoreAppDelegate>(new CoreAppDelegateNotebookCocos2d()));
	/// Initialize
	{
		const bool status = core.initialize(argc, argv);
		if (not status)
		{
			// Error Initialize
			return static_cast<int>(ErrorApp::BAD_INIT);
		}
	}
	// Запуск
	return core.run();
}
