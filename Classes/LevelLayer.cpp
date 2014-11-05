/**************************************************
	LevelLayer.cpp

	Robert	2014/08/29
**************************************************/
#include "LevelLayer.h"
#include "LevelScene.h"

#define SHORTEST_SLIDE_LENGTH (0)

LevelLayer::LevelLayer()
:pageNode(0)
,curPageNode(0)
{
}

LevelLayer::~LevelLayer()
{
}

bool LevelLayer::onTouchBegan(Touch* touch, Event* event)
{
	touchDownPoint = touch->getLocation();
	touchCurPoint = touchDownPoint;
	return true;
}

void LevelLayer::onTouchMoved(Touch* touch, Event* event)
{
	Point touchPoint = touch->getLocation();
	auto curX = getPositionX() + touchPoint.x - touchCurPoint.x;
	Point posPoint = Point(curX, getPositionY());
	auto dis = fabsf(touchPoint.x - touchCurPoint.x);
	if (dis >= SHORTEST_SLIDE_LENGTH ) {
		setPosition(posPoint);
	}
	touchCurPoint = touchPoint;
}

void LevelLayer::onTouchEnded(Touch* touch, Event* event)
{
	touchUpPoint = touch->getLocation();
	auto dis = touchUpPoint.getDistance(touchDownPoint);
	auto sprite1 = Sprite::createWithSpriteFrameName("page_mark1.png");
	auto width = sprite1->getContentSize().width;
	if (dis >= SHORTEST_SLIDE_LENGTH)
	{
		int offset = getPositionX() - curPageNode * (-WINDOW_WIDTH);
		if (offset > width)
		{
			if (curPageNode > 0)
			{
				--curPageNode;
				Sprite* sprite = (Sprite*)LevelScene::getInstance()->getChildByTag(888);
				sprite->setPosition(Vec2(sprite->getPositionX() - width, sprite->getPositionY()));
			}
		}
		else if (offset < -width)
		{
			if (curPageNode < (pageNode - 1))
			{
				++curPageNode;
				Sprite* sprite = (Sprite*)LevelScene::getInstance()->getChildByTag(888);
				sprite->setPosition(Vec2(sprite->getPositionX() + width, sprite->getPositionY()));
			}
		}
		goToCurrNode();
	}
}

void LevelLayer::addNode(Node* level)
{
	if (level)
	{
		level->setContentSize(Size(WINDOW_WIDTH, WINDOW_HEIGHT));
		level->setPosition(Vec2(WINDOW_WIDTH * pageNode, 0));
		addChild(level);
		pageNode++;
	}
}

bool LevelLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(LevelLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LevelLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LevelLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	WINDOW_WIDTH = Director::getInstance()->getWinSize().width;  
	WINDOW_HEIGHT = Director::getInstance()->getWinSize().height;
	
	return true;
}

void LevelLayer::goToCurrNode()
{
	runAction(MoveTo::create(0.5f, Vec2(-curPageNode * WINDOW_WIDTH, 0)));
}