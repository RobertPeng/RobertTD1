/*******************************
	AttackTower.cpp

	Robert		2014/09/22


*******************************/
#include "AttackTower.h"
#include "GameManager.h"

AttackTower::AttackTower()
{
	tower = NULL;
}

AttackTower::~AttackTower()
{
}

bool AttackTower::init()
{
	if (!TowerBase::init())
	{
		return false;
	}

	setScope(90);
	setTowerValue(200);
	setLethality(1);
	setRate(2);
	tower = Sprite::createWithSpriteFrameName("attackTower.png");
	addChild(tower);

	schedule(schedule_selector(AttackTower::shoot), 0.8f);
	return true;
}

void AttackTower::shoot(float dt)
{
	GameManager* instance = GameManager::getInstance();
	auto bulletVector = instance->bulletVector;
	checkNearestEnemy();
	if (nearestEnemy != NULL && nearestEnemy->getCurrHp() > 0)
	{
		auto currBullet = createBullet("bullet1.png");
		instance->bulletVector.pushBack(currBullet);
		auto moveDuration = getRate();
		Point shootVector = nearestEnemy->getSprite()->getPosition() - getPosition();
		shootVector.normalize();
		//Point normalizedShootVector = -shootVector.normalize();
		auto farthestDistance = Director::getInstance()->getWinSize().width;
		Point overshotVector = -shootVector * farthestDistance;
		Point offscreenPoint = currBullet->getPosition() - overshotVector;
		currBullet->runAction(Sequence::create(MoveTo::create(moveDuration, offscreenPoint),
											   CallFuncN::create(CC_CALLBACK_1(AttackTower::removeBullet, this)),
											   NULL));
		currBullet = NULL;
	}
}

// void AttackTower::removeBullet(Node* pSender)
// {
// 	GameManager *instance = GameManager::getInstance();   
// 	Sprite *sprite = (Sprite *)pSender;
// 	instance->bulletVector.eraseObject(sprite);
// 	sprite->removeFromParent();
// }

// Sprite* AttackTower::AttackTowerBullet()
// {
// 	Sprite* bullet = Sprite::createWithSpriteFrameName("bullet1.png");
// 	bullet->setPosition(0, tower->getContentSize().height / 4);
// 	addChild(bullet);
// 	return bullet;
// }

Sprite* AttackTower::createBullet(std::string bulletTexName)
{
	Sprite* bullet = TowerBase::createBullet(bulletTexName);
	bullet->setPosition(0, tower->getContentSize().height / 4);
	return bullet;
}
