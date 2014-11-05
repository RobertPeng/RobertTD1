/*******************************
	MultiDirTower.h

	Robert		2014/09/23


*******************************/
#ifndef __MULTIDIRTOWER_H_
#define __MULTIDIRTOWER_H_

#include "cocos2d.h"
#include "TowerBase.h"
USING_NS_CC;

class MultiDirTower : public TowerBase
{
public:
	MultiDirTower();
	virtual ~MultiDirTower();

	virtual bool init();
	CREATE_FUNC(MultiDirTower);
	void shoot(float dt);
	//void removeBullet(Node* pSender);
	virtual Sprite* createBullet(std::string bulletTexName);
	void createBullet6(float dt);

private:
	Sprite* tower;
};

#endif