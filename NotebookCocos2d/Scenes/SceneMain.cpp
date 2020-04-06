#include "SceneMain.h"
// Cocos2d lib
#include <cocos/2d/CCScene.h>
#include <cocos/2d/CCLayer.h>
#include <cocos/2d/CCLabel.h>
#include <cocos/ui/UIText.h>
#include <cocos/ui/UIListView.h>
#include <cocos/ui/UIButton.h>

#include <QtCore/QtCore>



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
	auto bg = PtrCocos2d<cocos2d::LayerColor>::create(cocos2d::Color4B::BLUE, 500, 500);
	//
	auto btn = cocos2d::ui::Button::create();
	{
		btn->setContentSize(cocos2d::Size(200, 50));
		btn->setPositionX(250);
		btn->setPositionY(250);
		btn->setTitleText("TEST");
	}
	// Add Child
	auto sceneCocos = this->getSceneCocos();
	sceneCocos->addChild(bg.get());
	sceneCocos->addChild(btn);
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
