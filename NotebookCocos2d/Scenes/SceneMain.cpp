#include "SceneMain.h"
// Cocos2d lib
#include <cocos/2d/CCScene.h>
#include <cocos/2d/CCLayer.h>
#include <cocos/2d/CCLabel.h>



SceneMain::SceneMain(PtrCocos2d<cocos2d::Scene>&& scene, const std::shared_ptr<IDescriptionScene>& description)
    : ClassBase(std::move(scene), description)
{

}

SceneMain::~SceneMain()
{

}

void SceneMain::onLoad()
{
	ClassBase::onLoad();
	if (not m_label)
	{
		// Create
		m_label = PtrCocos2d<cocos2d::Label>::create();
		assert(m_label);
		// Setting
		m_label->setPosition({ 250, 250 });
		m_label->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
		m_label->setContentSize({ 200, 100 });
		m_label->setString("TEXT");
		m_label->setTextColor(cocos2d::Color4B::WHITE);
		// Add Child
		if (auto sceneCocos = this->getSceneCocos())
		{
			sceneCocos->addChild(m_label.get());
		}
	}
}

void SceneMain::onActivate()
{
	ClassBase::onActivate();
}

void SceneMain::onDeactivate()
{
	ClassBase::onDeactivate();
}

void SceneMain::onPause()
{
	ClassBase::onPause();
}

void SceneMain::onResume()
{
	ClassBase::onResume();
}
