/*******************************
	TowerBase.h

	Robert		2014/09/20


*******************************/
#ifndef __TOWERBASE_H_
#define __TOWERBASE_H_

#include "cocos2d.h"
#include "EnemyBase.h"
USING_NS_CC;

class TowerBase : public Sprite
{
public:
	TowerBase();
	virtual ~TowerBase();
	virtual bool init();
	CREATE_FUNC(TowerBase);
	void checkNearestEnemy();
	virtual void removeBullet(Node* pSender);
	virtual Sprite* createBullet(std::string bulletTexName);
	CC_SYNTHESIZE(int, scope, Scope);			//塔的视线范围
	CC_SYNTHESIZE(int, lethality, Lethality);	//杀伤力
	CC_SYNTHESIZE(int, towerValue, TowerValue);  //
	CC_SYNTHESIZE(float, rate, Rate);  //

protected:
	EnemyBase* nearestEnemy;    // 塔子视野内最近的敌人
};

#endif