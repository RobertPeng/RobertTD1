/*******************************
	AttackTower.h

	Robert		2014/09/22


*******************************/
#ifndef __ATTACKTOWER_H_
#define __ATTACKTOWER_H_

#include "cocos2d.h"
#include "TowerBase.h"
USING_NS_CC;

class AttackTower : public TowerBase
{
public:
	AttackTower();
	virtual ~AttackTower();

	virtual bool init();
	CREATE_FUNC(AttackTower);
	void shoot(float dt);
	//void removeBullet(Node* pSender);
	virtual Sprite* createBullet(std::string bulletTexName);

private:
	Sprite* tower;
};

#endif