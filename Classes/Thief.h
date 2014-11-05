/*******************************
	Thief.h

	Robert		2014/09/20


*******************************/
#ifndef __THIEF_H_
#define __THIEF_H_

#include "cocos2d.h"
#include "EnemyBase.h"
USING_NS_CC;

class Thief : public EnemyBase
{
public:
	Thief();
	virtual ~Thief();
	static Thief* createThief(Vector<Node*> points, int hp);
	virtual bool init();
	virtual void changeDirection(float dt);
	virtual void enemyExploade();
};

class Pirate : public EnemyBase
{
public:
	Pirate();
	virtual ~Pirate();
	static Pirate* createPirate(Vector<Node*> points, int hp);
	virtual bool init();
	virtual void changeDirection(float dt);
	virtual void enemyExploade();
};

class Bandit : public EnemyBase
{
public:
	Bandit();
	virtual ~Bandit();
	static Bandit* createBandit(Vector<Node*> points, int hp);
	virtual bool init();
	virtual void changeDirection(float dt);
	virtual void enemyExploade();
};

#endif