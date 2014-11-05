/*******************************
	EnemyBase.h

	Robert		2014/09/20


*******************************/
#ifndef __ENEMYBASE_H_
#define __ENEMYBASE_H_

#include "cocos2d.h"
USING_NS_CC;

class EnemyBase : public Sprite
{
public:
	EnemyBase();	
	virtual ~EnemyBase();
	CREATE_FUNC(EnemyBase);
	virtual bool init();
	virtual void changeDirection(float dt) {};
	virtual void enemyExploade() {};
	Animation* createAnimation(std::string prefixName, int framesNum, float delay);
	Node* currPoint();
	Node* nextPoint();
	void runFollowPoint();
	void setPointsVector(Vector<Node*> points);
	void createAndSetHpBar();

protected:
	int pointCounter;
	Animation *animationRight;
	Animation *animationLeft;
	Animation *animationExplode;
	CC_SYNTHESIZE(float, runSpeed, RunSpeed);
	CC_SYNTHESIZE(float, maxHp, MaxHp);
	CC_SYNTHESIZE(float, vaule, Vaule);
	CC_SYNTHESIZE(float, currHp, CurrHp);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);
	CC_SYNTHESIZE(bool, enemySuccessful, EnemySuccessful);
	CC_SYNTHESIZE_READONLY(Sprite*, sprite, Sprite);
	CC_SYNTHESIZE_READONLY(Sprite*, hpBgSprite, HpBgSprite);

private:
	Vector<Node*> pointsVector;
};

#endif