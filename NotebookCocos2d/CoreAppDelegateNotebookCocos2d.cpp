#include "CoreAppDelegateNotebookCocos2d.h"
// Core lib
#include <Core/SessionApp.h>
#include <Core/IManagerDescriptionScene.h>
// CoreCocos2d lib
#include <CoreCocos2d/FactorySceneCocos2d.h>
#include <CoreCocos2d/DescriptionSceneCocos2d.h>
#include <CoreCocos2d/RenderCocos2d.h>
// Cocos2dxViaQt lib
#include <Cocos2dxViaQt/GLViewQt.h>
#include <Cocos2dxViaQt/QtWidgetCocos2d.h>
// Json lib
#include <nlohmann/json.hpp>
// Main
#include "StateMachineNotebookCocos2d.h"
#include "Scenes/SceneMain.h"





CoreAppDelegateNotebookCocos2d::CoreAppDelegateNotebookCocos2d(QtWidgetCocos2d* viewQt)
    : m_viewQt(viewQt)
{

}

std::unique_ptr<SessionApp> CoreAppDelegateNotebookCocos2d::createSessionApp(const int argc, const char* argv[])
{
	auto sessionApp = ClassBase::createSessionApp(argc, argv);
	// TODO: fake
	sessionApp->setName("NotebookCocos2d");
	sessionApp->setSize({ 500, 500 });
	sessionApp->setResizable(true);
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

std::unique_ptr<IRender> CoreAppDelegateNotebookCocos2d::createRender(const SessionApp& sessionApp, const IFactoryScene& factoryScene, const IManagerDescriptionScene& managerDescriptionScene)
{
	PtrCocos2d<cocos2d::GLView> glView (GLViewQt::create(sessionApp.getName(), m_viewQt));
	assert(glView);
	return std::unique_ptr<IRender>(new RenderCocos2d(std::move(glView), factoryScene, managerDescriptionScene));
}

std::unique_ptr<StateMachineBase> CoreAppDelegateNotebookCocos2d::createStateMachine(Core& core)
{
	return std::unique_ptr<StateMachineBase>(new StateMachineNotebookCocos2d(core));
}
