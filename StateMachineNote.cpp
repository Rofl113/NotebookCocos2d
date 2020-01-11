#include "StateMachineNote.h"
// Core lib
#include <Core/Core.h>
#include <Core/IRender.h>



StateMachineNote::~StateMachineNote()
{

}

StateMachineNote::StateMachineNote(Core& core)
    : m_core(core)
{

}

PtrMachineAction StateMachineNote::handleEnter()
{
	// TODO: как обрабатывать ответ от базового класса?
	auto action = ClassBase::handleEnter();
	// Get Scene
	m_scene = nullptr;
	if (const auto render = m_core.getRender())
	{
		m_scene = render->loadScene("Main");
	}
	return action;
}

PtrMachineAction StateMachineNote::handleMessage(const MachineMessage& message)
{
	return ClassBase::handleMessage(message);
}

PtrMachineAction StateMachineNote::handleExit()
{
	// TODO: как обрабатывать ответ от базового класса?
	auto action = ClassBase::handleExit();

	return action;
}
