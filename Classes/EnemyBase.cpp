/*******************************
	EnemyBase.cpp

	Robert		2014/09/20


*******************************/
#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
	pointCounter = 0;
	animationRight = NULL;
	animationLeft = NULL;
	animationExplode = NULL;
	runSpeed = 0;
	maxHp = 0;
	vaule = 0;
	currHp = 0;
	hpPercentage = 0;
	hpBar = NULL;
	enemySuccessful = false;
	sprite = NULL;
	hpBgSprite = NULL;
}

EnemyBase::~EnemyBase()
{
}

bool EnemyBase::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

Animation* EnemyBase::createAnimation(std::string prefixName, int framesNum, float delay)
{
	Vector<SpriteFrame*> animFrames;
	for (int i = 1; i <= framesNum; ++i)
	{
		char buffer[20] = {0};
		sprintf(buffer, "_%i.png", i);
		std::string str = prefixName + buffer;
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}
	return Animation::createWithSpriteFrames(animFrames, delay);
}

Node* EnemyBase::currPoint()
{
	if (pointsVector.size() > 0)
		return pointsVector.at(pointCounter);
	else
		return NULL;
}

Node* EnemyBase::nextPoint()
{
	int maxCount = pointsVector.size();
	pointCounter++;
	if (pointCounter < maxCount)
	{
		auto node = pointsVector.at(pointCounter);
		return node;
	}
	else
		setEnemySuccessful(true);
	return NULL;
}

void EnemyBase::runFollowPoint()
{
	auto temp = currPoint();
	sprite->setPosition(temp->getPosition());
	auto point = nextPoint();

	if (point != NULL)
	{
		auto duration = temp->getPosition().getDistance(point->getPosition()) / getRunSpeed();
		sprite->runAction(Sequence::create(MoveTo::create(duration, point->getPosition()),
										   CallFuncN::create(CC_CALLBACK_0(EnemyBase::runFollowPoint, this)),
										   NULL));
	}
}

void EnemyBase::setPointsVector(Vector<Node*> points)
{
	pointsVector = points;
}

void EnemyBase::createAndSetHpBar()
{
	hpBgSprite = Sprite::createWithSpriteFrameName("hpBg1.png");
	hpBgSprite->setPosition(Point(sprite->getContentSize().width / 2, sprite->getContentSize().height));
	sprite->addChild(hpBgSprite);
	hpBar = CCProgressTimer::create(Sprite::createWithSpriteFrameName("hp1.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));
	hpBar->setBarChangeRate(Point(1, 0));
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 3 * 2));
	hpBgSprite->addChild(hpBar);
}