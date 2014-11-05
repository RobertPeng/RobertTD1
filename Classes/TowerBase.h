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
	CC_SYNTHESIZE(int, scope, Scope);			//�������߷�Χ
	CC_SYNTHESIZE(int, lethality, Lethality);	//ɱ����
	CC_SYNTHESIZE(int, towerValue, TowerValue);  //
	CC_SYNTHESIZE(float, rate, Rate);  //

protected:
	EnemyBase* nearestEnemy;    // ������Ұ������ĵ���
};

#endif