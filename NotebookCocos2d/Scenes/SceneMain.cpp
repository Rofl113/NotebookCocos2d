#include "SceneMain.h"
// Cocos2d lib
#include <cocos/2d/CCLayer.h>
#include <cocos/2d/CCScene.h>



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
	if (not m_bg)
	{
		// Create
		m_bg = PtrCocos2d<cocos2d::LayerColor>::create();
		assert(m_bg);
		// Setting
		m_bg->setContentSize(cocos2d::Size(500, 500));
		m_bg->setColor(cocos2d::Color3B::RED);
		// Add Child
		if (auto sceneCocos = this->getSceneCocos())
		{
			sceneCocos->addChild(m_bg.get());
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
