/*******************************
	GameManager.h

	Robert		2014/09/20


*******************************/
#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "cocos2d.h"
#include "EnemyBase.h"
USING_NS_CC;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();
	static GameManager* getInstance();

	Vector<EnemyBase*> enemyVector;
	Vector<Sprite*> bulletVector;
private:
	static GameManager* instance;
};

#endif