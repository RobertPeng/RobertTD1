/**************************************************
	LogoScene.cpp

	Robert	2014/08/27
**************************************************/
#include "LogoScene.h"
#include "SimpleAudioEngine.h"
#include "LevelScene.h"

using namespace CocosDenshion;

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
}

bool LogoScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	//Background
	Size size = CCDirector::getInstance()->getWinSize();
	Sprite* pSprite = Sprite::create("playbg.png");
	pSprite->setPosition(size.width / 2, size.height / 2);
	addChild(pSprite, -1);

	//Title
	auto titleSprite = Sprite::createWithSpriteFrameName("title.png");
	titleSprite->setPosition(size.width / 3, size.height / 3 * 2);
	addChild(titleSprite);
	auto titleMove = MoveBy::create(1.0f, Vec2(0.0f, 10.0f));
	titleSprite->runAction(RepeatForever::create(Sequence::create(titleMove, titleMove->reverse(), nullptr)));

	//Start Button
	auto startButton = MenuItemImage::create(
		"start_1.png",
		"start_2.png",
		CC_CALLBACK_1(LogoScene::startButtonCallBack, this)
		);
	startButton->setAnchorPoint(Vec2(.5f, 0.5f));
	startButton->setPosition(size.width / 2, size.height / 6);
	auto menu = Menu::create(startButton, nullptr);
	menu->setPosition(Point::ZERO);
	addChild(menu, 1);

	return true;
}

Scene* LogoScene::createScene()
{
	Scene* pScene = Scene::create();
	LogoScene* pLayer = LogoScene::create();
	pScene->addChild(pLayer);

	return pScene;
}

void LogoScene::startButtonCallBack(Ref* pSender)
{
//	CCLOG("hahaha!");
	SimpleAudioEngine::getInstance()->playEffect(FileUtils::getInstance()->fullPathForFilename("sound/button.wav").c_str(), false);
	Director::getInstance()->replaceScene(CCTransitionFade::create(0.5f, LevelScene::create()));
}