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
#include "CoreAppDelegateCocosNodePlusPlus.h"

namespace
{

enum Error
{
	NONE = 0,
	BAD_INIT = -1
};

} // END namespace


int main(const int argc, const char* argv[])
{
	Core core (std::unique_ptr<ICoreAppDelegate>(new CoreAppDelegateCocosNodePlusPlus()));
	const bool status = core.initialize(argc, argv);
	if (status)
	{
		// TODO: добавить выход по ошибке
		core.run();
	}
	else
	{
		// Error Initialize
		return BAD_INIT;
	}
	return NONE;
}
