/*******************************
	TowerPanelLayer.cpp

	Robert		2014/09/23


*******************************/
#include "TowerPanelLayer.h"

TowerPanelLayer::TowerPanelLayer()
{
	chooseTowerType = INVALID_TOWER;
	sprite1 = NULL;
	sprite2 = NULL;
	sprite3 = NULL;
}

TowerPanelLayer::~TowerPanelLayer()
{
}

bool TowerPanelLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	setChooseTowerType(INVALID_TOWER);
	auto sprite = Sprite::createWithSpriteFrameName("towerPos.png");
	sprite->setPosition(Point(0, 0));
	addChild(sprite);

	sprite1 = Sprite::createWithSpriteFrameName("ArrowTower1.png");
	sprite1->setAnchorPoint( Point(0.5f, 0));
	sprite1->setPosition(Point(-sprite->getContentSize().width, sprite->getContentSize().height/2));
	addChild(sprite1);

	sprite2 = Sprite::createWithSpriteFrameName("AttackTower1.png");
	sprite2->setAnchorPoint( Point(0.5f, 0));
	sprite2->setPosition(Point(0, sprite->getContentSize().height/2));
	addChild(sprite2);

	sprite3 = Sprite::createWithSpriteFrameName("MultiDirTower1.png");
	sprite3->setAnchorPoint( Point(0.5f, 0));
	sprite3->setPosition(Point(sprite->getContentSize().width, sprite->getContentSize().height/2));
	this->addChild(sprite3);

	sprite1 = Sprite::createWithSpriteFrameName("ArrowTower1.png");
	sprite1->setAnchorPoint(Point(0.5f, 0));

	return true;
}

bool TowerPanelLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void TowerPanelLayer::onTouchEnded(Touch *touch, Event *unused_event)
{

}