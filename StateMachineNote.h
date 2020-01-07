#pragma once
#include <StateMachine/StateMachineBase.h>


class Core;


class StateMachineNote : public StateMachineBase
{
	StateMachineNote() = delete;
public:
	virtual ~StateMachineNote() override;
	StateMachineNote(Core& core);

private:
	Core& m_core;
};
