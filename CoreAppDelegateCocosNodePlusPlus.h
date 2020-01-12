#pragma once
// CoreCococ2d lib
#include <CoreCocos2d/CoreAppDelegateCocos2d.h>


class CoreAppDelegateCocosNodePlusPlus : public CoreAppDelegateCocos2d
{
	using ClassBase = CoreAppDelegateCocos2d;
public:
	virtual std::unique_ptr<SessionApp> createSessionApp(const int argc, const char* argv[]) override;
	virtual std::unique_ptr<IManagerDescriptionScene> createManagerDescriptionScene(const SessionApp& sessionApp) override;
	virtual std::unique_ptr<IFactoryScene> createFactoryScene(const SessionApp& sessionApp) override;
	virtual std::unique_ptr<StateMachineBase> createStateMachine(Core& core) override;
};
