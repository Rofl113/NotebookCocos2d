#pragma once
// CoreCocos2d lib
#include <CoreCocos2d/SceneCocos2d.h>
// Common
#include "ISceneMain.h"


namespace cocos2d { class LayerColor; }


class SceneMain : public SceneCocos2d, public ISceneMain
{
	using ClassBase = SceneCocos2d;
	SceneMain() = delete;
public:
	SceneMain(PtrCocos2d<cocos2d::Scene>&& scene, const std::shared_ptr<IDescriptionScene>& description);
	virtual ~SceneMain() override;

public: /// SceneCocos2d
	virtual void onLoad() override;
	virtual void onActivate() override;
	virtual void onDeactivate() override;
	virtual void onPause() override;
	virtual void onResume() override;

private:
	PtrCocos2d<cocos2d::LayerColor> m_bg;
};
