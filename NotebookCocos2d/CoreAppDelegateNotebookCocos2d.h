#pragma once
// CoreCococ2d lib
#include <CoreCocos2d/CoreAppDelegateCocos2d.h>


class QtWidgetCocos2d;


class CoreAppDelegateNotebookCocos2d : public CoreAppDelegateCocos2d
{
	using ClassBase = CoreAppDelegateCocos2d;
	CoreAppDelegateNotebookCocos2d() = delete;
public:
	CoreAppDelegateNotebookCocos2d(QtWidgetCocos2d* viewQt);

public: /// CoreAppDelegateCocos2d
	virtual std::unique_ptr<SessionApp> createSessionApp(const int argc, const char* argv[]) override;
	virtual std::unique_ptr<IManagerDescriptionScene> createManagerDescriptionScene(const SessionApp& sessionApp) override;
	virtual std::unique_ptr<IFactoryScene> createFactoryScene(const SessionApp& sessionApp) override;
	virtual std::unique_ptr<IRender> createRender(const SessionApp& sessionApp, const IFactoryScene& factoryScene, const IManagerDescriptionScene& managerDescriptionScene) override;
	virtual std::unique_ptr<StateMachineBase> createStateMachine(Core& core) override;

private:
	QtWidgetCocos2d* m_viewQt = nullptr;
};
