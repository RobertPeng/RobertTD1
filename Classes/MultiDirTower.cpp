/*******************************
	MultiDirTower.cpp

	Robert		2014/09/23


*******************************/
#include "MultiDirTower.h"
#include "GameManager.h"

MultiDirTower::MultiDirTower()
{
}

MultiDirTower::~MultiDirTower()
{
}

bool MultiDirTower::init()
{
	if (!TowerBase::init())
	{
		return false;
	}

	setScope(60);
	setTowerValue(600);
	setLethality(0.5);
	setRate(3);
	tower= Sprite::createWithSpriteFrameName("multiDirTower.png");
	this->addChild(tower);

	this->schedule(schedule_selector(MultiDirTower::createBullet6), 0.8f);
	return true;
}


// Sprite* MultiDirTower::MultiDirTowerBullet()
// {
// 	Sprite* bullet = Sprite::createWithSpriteFrameName("bullet.png");
// 	bullet->setPosition(0, tower->getContentSize().height /4 );
// 	this->addChild(bullet);
// 
// 	return bullet;
// }

Sprite* MultiDirTower::createBullet(std::string bulletTexName)
{
	Sprite* bullet = Sprite::createWithSpriteFrameName(bulletTexName);
	bullet->setPosition(0, tower->getContentSize().height /4 );
	return bullet;
}

void MultiDirTower::createBullet6(float dt)
{
	GameManager *instance = GameManager::getInstance();
	auto bulletVector = instance->bulletVector;
	int dirTotal = 10;
	this->checkNearestEnemy();
	if(nearestEnemy != NULL && nearestEnemy->getCurrHp() > 0 )
	{
		for(int i = 0; i < dirTotal; i++)
		{
			auto currBullet = createBullet("bullet.png");
			instance->bulletVector.pushBack(currBullet);

			auto moveDuration = getRate();

			Point shootVector;
			shootVector.x = 1;
			shootVector.y = tan( i * 2 * M_PI / dirTotal );
			shootVector.normalize();
			Point normalizedShootVector;
			if( i >= dirTotal / 2 )
			{
				normalizedShootVector = shootVector;
			}else{
				normalizedShootVector = -shootVector;
			}
			auto farthestDistance = Director::getInstance()->getWinSize().width;
			Point overshotVector = normalizedShootVector * farthestDistance;
			Point offscreenPoint = (currBullet->getPosition() - overshotVector);

			currBullet->runAction(Sequence::create(MoveTo::create(moveDuration, offscreenPoint),
				CallFuncN::create(CC_CALLBACK_1(MultiDirTower::removeBullet, this)),
				NULL));
			currBullet = NULL;
		}
	}
}
