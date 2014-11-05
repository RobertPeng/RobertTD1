/*******************************
	TowerPanelLayer.h

	Robert		2014/09/23


*******************************/
#ifndef __TOWERPANELLAYER_H_
#define __TOWERPANELLAYER_H_

#include "cocos2d.h"
USING_NS_CC;

class TowerPanelLayer : public Layer
{
	typedef enum
	{
		INVALID_TOWER,
		ARROW_TOWER,
		ATTACK_TOWER, 
		MULTIDIR_TOWER,
		ANOTHER,
	}TowerType;
public:
	TowerPanelLayer();
	virtual ~TowerPanelLayer();
	virtual bool init();
	CREATE_FUNC(TowerPanelLayer);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	CC_SYNTHESIZE(TowerType, chooseTowerType, ChooseTowerType);

private:
	Sprite* sprite1;
	Sprite* sprite2;
	Sprite* sprite3;
};

#endif