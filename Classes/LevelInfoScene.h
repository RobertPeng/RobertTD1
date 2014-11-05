/*******************************
	LevelInfoScene.h

	Robert		2014/09/09


*******************************/
#ifndef __LEVELINFOSCENE_H_
#define __LEVELINFOSCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class LevelInfoScene : public Layer
{
public:
	LevelInfoScene();
	virtual ~LevelInfoScene();
	bool init();
	CREATE_FUNC(LevelInfoScene);
};

#endif