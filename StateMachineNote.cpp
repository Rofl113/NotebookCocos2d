#include "StateMachineNote.h"
#include <cassert>
// Core lib
#include <Core/Core.h>
#include <Core/IManagerScene.h>



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
	if (const auto manager = m_core.getManagerScene())
	{
		m_scene = manager->loadScene("Main");
		const bool result = manager->push(m_scene);
		assert(result);
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
	if (m_scene)
	{
		if (const auto manager = m_core.getManagerScene())
		{
			const bool result = manager->pop(m_scene);
			assert(result);
		}
		m_scene = nullptr;
	}
	return action;
}
