#include "CoreAppDelegateCocosNodePlusPlus.h"
// Main
#include "StateMachineNote.h"




std::unique_ptr<StateMachineBase> CoreAppDelegateCocosNodePlusPlus::createStateMachine(Core& core)
{
	return std::unique_ptr<StateMachineBase>(new StateMachineNote(core));
}
