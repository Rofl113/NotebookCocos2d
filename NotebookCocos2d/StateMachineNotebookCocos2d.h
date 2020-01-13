#pragma once
#include <StateMachine/StateMachineBase.h>


class Core;
class IScene;


class StateMachineNotebookCocos2d : public StateMachineBase
{
	using ClassBase = StateMachineBase;
	StateMachineNotebookCocos2d() = delete;
public:
	virtual ~StateMachineNotebookCocos2d() override;
	StateMachineNotebookCocos2d(Core& core);

private:
	virtual PtrMachineAction handleEnter() override;
	virtual PtrMachineAction handleMessage(const MachineMessage& message) override;
	virtual PtrMachineAction handleExit() override;

private:
	Core& m_core;

private:
	std::shared_ptr<IScene> m_scene;
};
