#pragma once
// CoreCococ2d lib
#include <CoreCocos2d/CoreAppDelegateCocos2d.h>


class CoreAppDelegateCocosNodePlusPlus : public CoreAppDelegateCocos2d
{
public:
	virtual std::unique_ptr<StateMachineBase> createStateMachine(Core& core) override;
};
