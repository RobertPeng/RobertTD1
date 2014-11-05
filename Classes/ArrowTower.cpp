/*******************************
	ArrowTower.cpp

	Robert		2014/09/23


*******************************/
#include "ArrowTower.h"
#include "GameManager.h"

ArrowTower::ArrowTower()
{
}

ArrowTower::~ArrowTower()
{
}

bool ArrowTower::init()
{
	if (!TowerBase::init())
	{
		return false;
	}

	setScope(90);
	setLethality(2);
	setTowerValue(250);
	setRate(2);
	auto baseplate = Sprite::createWithSpriteFrameName("baseplate.png");
	addChild(baseplate);

	rotateArrow = Sprite::createWithSpriteFrameName("arrow.png");
	rotateArrow->setPosition(0, baseplate->getContentSize().height /4  );
	addChild(rotateArrow);

	schedule(schedule_selector(ArrowTower::rotateAndShoot), 0.8f);
	return true;
}


// Sprite* ArrowTower::ArrowTowerBullet()
// {
// 	Sprite* bullet = Sprite::createWithSpriteFrameName("arrowBullet.png");
// 	bullet->setPosition(rotateArrow->getPosition());
// 	bullet->setRotation(rotateArrow->getRotation());
// 	addChild(bullet);
// 
// 	return bullet;
// }

Sprite* ArrowTower::createBullet(std::string bulletTexName)
{
	Sprite* bullet = TowerBase::createBullet(bulletTexName);
	bullet->setPosition(rotateArrow->getPosition());
	bullet->setRotation(rotateArrow->getRotation());
	return bullet;
}

void ArrowTower::rotateAndShoot(float dt)
{
	checkNearestEnemy();
	if (nearestEnemy != NULL)
	{
		auto rotateVector = nearestEnemy->getSprite()->getPosition() - this->getPosition();
		auto rotateRadians = rotateVector.getAngle();
		auto rotateDegrees = CC_RADIANS_TO_DEGREES(-1 * rotateRadians);

		auto speed = 0.5 / M_PI;
		auto rotateDuration = fabs(rotateRadians * speed);
		rotateArrow->runAction( Sequence::create(RotateTo::create(rotateDuration, rotateDegrees),
			CallFunc::create(CC_CALLBACK_0(ArrowTower::shoot, this)),
			NULL));
	}
}

void ArrowTower::shoot()
{
	GameManager *instance = GameManager::getInstance();
	auto bulletVector = instance->bulletVector;

	if(nearestEnemy!=NULL && nearestEnemy->getCurrHp() > 0 )
	{
		auto currBullet = createBullet("arrowBullet.png");
		instance->bulletVector.pushBack(currBullet);

		auto moveDuration = getRate();
		Point shootVector = nearestEnemy->getSprite()->getPosition() - this->getPosition();
		shootVector.normalize();

		auto farthestDistance = Director::getInstance()->getWinSize().width;
		Point overshotVector = -shootVector * farthestDistance;
		Point offscreenPoint = (rotateArrow->getPosition() - overshotVector);

		currBullet->runAction(Sequence::create(MoveTo::create(moveDuration, offscreenPoint),
			CallFuncN::create(CC_CALLBACK_1(ArrowTower::removeBullet, this)),
			NULL));
		currBullet = NULL;
	}
}

// void ArrowTower::removeBullet(Node* pSender)
// {
// 	GameManager *instance = GameManager::getInstance();
// 
// 	auto bulletVector = instance->bulletVector;
// 
// 	Sprite *sprite = (Sprite *)pSender;
// 	instance->bulletVector.eraseObject(sprite);
// 	sprite->removeFromParent();
// }

