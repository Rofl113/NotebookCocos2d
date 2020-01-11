#pragma once
#include <StateMachine/StateMachineBase.h>


class Core;
class IScene;


class StateMachineNote : public StateMachineBase
{
	using ClassBase = StateMachineBase;
	StateMachineNote() = delete;
public:
	virtual ~StateMachineNote() override;
	StateMachineNote(Core& core);

private:
	virtual PtrMachineAction handleEnter() override;
	virtual PtrMachineAction handleMessage(const MachineMessage& message) override;
	virtual PtrMachineAction handleExit() override;

private:
	Core& m_core;

private:
	std::shared_ptr<IScene> m_scene;
};
