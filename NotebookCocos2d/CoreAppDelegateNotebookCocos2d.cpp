#include "CoreAppDelegateNotebookCocos2d.h"
// Core lib
#include <Core/SessionApp.h>
#include <Core/IManagerDescriptionScene.h>
// CoreCocos2d lib
#include <CoreCocos2d/FactorySceneCocos2d.h>
#include <CoreCocos2d/DescriptionSceneCocos2d.h>
// Json lib
#include <nlohmann/json.hpp>
// Main
#include "StateMachineNotebookCocos2d.h"
#include "Scenes/SceneMain.h"





std::unique_ptr<SessionApp> CoreAppDelegateNotebookCocos2d::createSessionApp(const int argc, const char* argv[])
{
	auto sessionApp = ClassBase::createSessionApp(argc, argv);
	// TODO: fake
	sessionApp->setName("CocosNodePlusPlus");
	sessionApp->setSize({ 500, 500 });
	return sessionApp;
}

std::unique_ptr<IManagerDescriptionScene> CoreAppDelegateNotebookCocos2d::createManagerDescriptionScene(const SessionApp& sessionApp)
{
	auto managerDescriptionScene = ClassBase::createManagerDescriptionScene(sessionApp);
	// TODO: fake
	managerDescriptionScene->registerDescription("Main", std::shared_ptr<IDescriptionScene>{ new DescriptionSceneCocos2d("Main", "SceneMain", {}, {}) });
	return managerDescriptionScene;
}

std::unique_ptr<IFactoryScene> CoreAppDelegateNotebookCocos2d::createFactoryScene(const SessionApp& sessionApp)
{
	auto factoryScene = ClassBase::createFactoryScene(sessionApp);
	if (auto factorySceneCocos2d = dynamic_cast<FactorySceneCocos2d*>(factoryScene.get()))
	{
		factorySceneCocos2d->registerScene<SceneMain>("SceneMain");
	}
	return factoryScene;
}

std::unique_ptr<StateMachineBase> CoreAppDelegateNotebookCocos2d::createStateMachine(Core& core)
{
	return std::unique_ptr<StateMachineBase>(new StateMachineNotebookCocos2d(core));
}
