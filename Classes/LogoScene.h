/**************************************************
	LogoScene.h

	Robert	2014/08/27
**************************************************/
#ifndef __LOGOSCENE_H_
#define __LOGOSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class LogoScene : public Layer
{
public:
	LogoScene();
	virtual ~LogoScene();
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(LogoScene);

private:
	void startButtonCallBack(Ref* pSender);
};

#endif