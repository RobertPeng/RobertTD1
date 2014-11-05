/**************************************************
	LoadingResScene.cpp

	Robert	2014/08/27
**************************************************/
#include "LoadingResScene.h"
#include "LogoScene.h"

using namespace CocosDenshion;

LoadingResScene::LoadingResScene()
{
	_progressBar = nullptr;
	_loadedRes = 0;
	_totalRes = 0;
}

LoadingResScene::~LoadingResScene()
{
}

bool LoadingResScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	progressBarInit();
	loadRes();
	schedule(schedule_selector(LoadingResScene::logic));
	
	return true;
}

Scene* LoadingResScene::createScene()
{
	Scene* pScene = Scene::create();
	LoadingResScene* pLayer = LoadingResScene::create();
	pScene->addChild(pLayer);

	return pScene;
}

void LoadingResScene::progressBarInit()
{
	Size size = Director::getInstance()->getWinSize();
	auto progressBarBg = Sprite::create("load.png");
	progressBarBg->setPosition(size.width / 2, size.height / 2);
	addChild(progressBarBg);

	_progressBar = ProgressTimer::create(Sprite::create("loadBar.png"));
	_progressBar->setType(ProgressTimer::Type::BAR);
	_progressBar->setMidpoint(Vec2(0, 0.5f));
	_progressBar->setBarChangeRate(Vec2(1, 0));
	_progressBar->setPercentage(0);
	_progressBar->setAnchorPoint(Vec2(0.5f, 0.5f));
	_progressBar->setPosition(progressBarBg->getContentSize().width / 2, progressBarBg->getContentSize().height / 6);
	progressBarBg->addChild(_progressBar);
}

void LoadingResScene::loadingCallBack(Texture2D* pTexture)
{
	++_loadedRes;
	if (_loadedRes >= _totalRes)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(0.1f, LogoScene::createScene()));
	}
}

void LoadingResScene::loadRes()
{
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(FileUtils::getInstance()->fullPathForFilename("sound/music.mp3").c_str() );
	_loadedRes++;
	SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/dead.wav" ).c_str());
	_loadedRes++;
	SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/button.wav").c_str() );
	_loadedRes++;
	SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/comeout.wav").c_str() );
	_loadedRes++;
	SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/shoot.wav").c_str() );
	_loadedRes++;
	SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/tip.wav").c_str() );
	_loadedRes++;
	SimpleAudioEngine::getInstance()->preloadEffect(FileUtils::getInstance()->fullPathForFilename("sound/dead.mp3").c_str() );
	_loadedRes++;
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Play.plist");
	_loadedRes++;

	Director::getInstance()->getTextureCache()->addImageAsync("playbg.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("playbg1.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("successfulBg.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("btn_back.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("btn_back_press.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("card_1.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("card_2.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("card_3.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("LevelInfoPanel.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("House.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("selectLevelBg.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("selectLevelBg1.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("selectLevelBg2.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("start_1.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("start_2.png", CC_CALLBACK_1(LoadingResScene::loadingCallBack, this));
}

void LoadingResScene::logic(float dt)
{
	float percent = (float)_loadedRes / (float)_totalRes * 100;
	_progressBar->setPercentage(percent);
}