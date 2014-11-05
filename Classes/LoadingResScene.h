/**************************************************
	LoadingResScene.h

	Robert	2014/08/27
**************************************************/
#ifndef __LOADINGRESSCENE_H_
#define __LOADINGRESSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class LoadingResScene : public Layer
{
public:
	LoadingResScene();
	virtual ~LoadingResScene();
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(LoadingResScene);

private:
	void progressBarInit();
	void loadRes();
	void loadingCallBack(Texture2D* pTexture);
	void logic(float dt);

private:
	ProgressTimer* _progressBar;
	int _loadedRes;
	int _totalRes;
};

#endif