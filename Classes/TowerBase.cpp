/*******************************
	TowerBase.cpp

	Robert		2014/09/20


*******************************/
#include "TowerBase.h"
#include "GameManager.h"

TowerBase::TowerBase()
{
	scope = 0;
	lethality = 0;
	towerValue = 0;
	rate = 0;
	nearestEnemy = NULL;
}

TowerBase::~TowerBase()
{
}

bool TowerBase::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}

void TowerBase::checkNearestEnemy()
{
	auto enemyVector = GameManager::getInstance()->enemyVector;
	auto currMinDis = scope;
	EnemyBase* enemyTemp = NULL;
	for (int i = 0; i < enemyVector.size(); ++i)
	{
		auto enemy = enemyVector.at(i);
		float dis = getPosition().getDistance(enemy->getSprite()->getPosition());;
		if (dis < currMinDis)
		{
			currMinDis = dis;
			enemyTemp = enemyVector.at(i);
		}
	}
	nearestEnemy = enemyTemp;
}

void TowerBase::removeBullet(Node* pSender)
{
	GameManager *instance = GameManager::getInstance();
	auto bulletVector = instance->bulletVector;

	Sprite *sprite = (Sprite *)pSender;
	instance->bulletVector.eraseObject(sprite);
	sprite->removeFromParent();
}

Sprite* TowerBase::createBullet(std::string bulletTexName)
{
	Sprite* bullet = Sprite::createWithSpriteFrameName(bulletTexName);
	addChild(bullet);
	return bullet;
}