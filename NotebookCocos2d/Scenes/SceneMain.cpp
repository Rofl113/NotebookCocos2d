#include "SceneMain.h"
// Cocos2d lib
#include <cocos/2d/CCScene.h>
#include <cocos/2d/CCLayer.h>
#include <cocos/2d/CCLabel.h>
#include <cocos/ui/UIText.h>
#include <cocos/ui/UIListView.h>



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
	// Create
	auto bg = PtrCocos2d<cocos2d::LayerColor>::create(cocos2d::Color4B::BLUE, 200, 500);
	auto listView = PtrCocos2d<cocos2d::ui::ListView>::create();
	{
		// Setting
		listView->setPosition({ 0, 0 });
		listView->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
		listView->setContentSize({ 200, 500 });
		for (size_t i = 0; i < 100; ++i)
		{
			auto label = cocos2d::ui::Text::create();
			label->setTextColor(cocos2d::Color4B::BLACK);
			label->setString("TEST # " + std::to_string(i));
			listView->pushBackCustomItem(label);
		}
	}
	// Add Child
	auto sceneCocos = this->getSceneCocos();
	sceneCocos->addChild(bg.get());
	sceneCocos->addChild(listView.get());
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
