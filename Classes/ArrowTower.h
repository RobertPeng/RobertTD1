/*******************************
	ArrowTower.h

	Robert		2014/09/23


*******************************/
#ifndef __ARROWTOWER_H_
#define __ARROWTOWER_H_

#include "cocos2d.h"
#include "TowerBase.h"
USING_NS_CC;

class ArrowTower : public TowerBase
{
public:
	ArrowTower();
	virtual ~ArrowTower();

	virtual bool init();
	CREATE_FUNC(ArrowTower);
	void rotateAndShoot(float dt);
	void shoot();
	//void removeBullet(Node* pSender);
	virtual Sprite* createBullet(std::string bulletTexName);

private:
	Sprite* rotateArrow;
};

#endif