/*******************************
	Thief.cpp

	Robert		2014/09/20


*******************************/
#include "Thief.h"

Thief::Thief()
{
}

Thief::~Thief()
{
}

Thief* Thief::createThief(Vector<Node*> points, int hp)
{
	Thief* pThief = new Thief();
	if (pThief && pThief->init())
	{
		pThief->setPointsVector(points);
		pThief->setCurrHp(hp);
		pThief->setMaxHp(hp);
		pThief->runFollowPoint();
		pThief->autorelease();
		return pThief;
	}
	else
	{
		delete pThief;
		pThief = NULL;
		return NULL;
	}
}

bool Thief::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	setRunSpeed(25);
	setVaule(10);
	sprite = Sprite::createWithSpriteFrameName("enemyRight1_1.png");
	addChild(sprite);
	animationRight = createAnimation("enemyRight1", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationRight, "runRight1");
	animationLeft = createAnimation("enemyLeft1", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationLeft, "runLeft1");
	animationExplode = createAnimation("explode1", 6, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationExplode, "explode1");
	createAndSetHpBar();
	schedule(schedule_selector(Thief::changeDirection), 0.4f);
	return true;
}

void Thief::changeDirection(float dt)
{
	auto curr = currPoint();
	if (curr == NULL)
	{
		return;
	}
	if(curr->getPositionX() > sprite->getPosition().x )
	{
		sprite->runAction( Animate::create(AnimationCache::getInstance()->getAnimation("runRight1"))) ;
	}else{
		sprite->runAction( Animate::create(AnimationCache::getInstance()->getAnimation("runLeft1"))  );
	}
}

void Thief::enemyExploade()
{
	hpBgSprite->setVisible(false);
	sprite->stopAllActions();
	unschedule(schedule_selector(Thief::changeDirection));
	sprite->setAnchorPoint(Point(0.5f, 0.25f));
	sprite->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("explode1"))
		,CallFuncN::create(CC_CALLBACK_0(EnemyBase::removeFromParent, this))
		, NULL));
}

//Pirate
Pirate::Pirate()
{
}

Pirate::~Pirate()
{
}

Pirate* Pirate::createPirate(Vector<Node*> points, int hp)
{
	Pirate* pPirate = new Pirate();
	if (pPirate && pPirate->init())
	{
		pPirate->setPointsVector(points);
		pPirate->setCurrHp(hp);
		pPirate->setMaxHp(hp);
		pPirate->runFollowPoint();
		pPirate->autorelease();
		return pPirate;
	}
	else
	{
		delete pPirate;
		pPirate = NULL;
		return NULL;
	}
}

bool Pirate::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	setRunSpeed(25);
	setVaule(10);
	sprite = Sprite::createWithSpriteFrameName("enemyRight2_1.png");
	addChild(sprite);
	animationRight = createAnimation("enemyRight2", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationRight, "runRight2");
	animationLeft = createAnimation("enemyLeft2", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationLeft, "runLeft2");
	animationExplode = createAnimation("explode2", 6, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationExplode, "explode2");
	createAndSetHpBar();
	schedule(schedule_selector(Pirate::changeDirection), 0.4f);
	return true;
}

void Pirate::changeDirection(float dt)
{
	auto curr = currPoint();
	if (curr == NULL)
	{
		return;
	}
	if(curr->getPositionX() > sprite->getPosition().x )
	{
		sprite->runAction( Animate::create(AnimationCache::getInstance()->getAnimation("runRight2"))) ;
	}else{
		sprite->runAction( Animate::create(AnimationCache::getInstance()->getAnimation("runLeft2"))  );
	}
}

void Pirate::enemyExploade()
{
	hpBgSprite->setVisible(false);
	sprite->stopAllActions();
	unschedule(schedule_selector(Pirate::changeDirection));
	sprite->setAnchorPoint(Point(0.5f, 0.25f));
	sprite->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("explode2"))
		,CallFuncN::create(CC_CALLBACK_0(EnemyBase::removeFromParent, this))
		, NULL));
}

//Bandit
Bandit::Bandit()
{
}

Bandit::~Bandit()
{
}

Bandit* Bandit::createBandit(Vector<Node*> points, int hp)
{
	Bandit* pBandit = new Bandit();
	if (pBandit && pBandit->init())
	{
		pBandit->setPointsVector(points);
		pBandit->setCurrHp(hp);
		pBandit->setMaxHp(hp);
		pBandit->runFollowPoint();
		pBandit->autorelease();
		return pBandit;
	}
	else
	{
		delete pBandit;
		pBandit = NULL;
		return NULL;
	}
}

bool Bandit::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	setRunSpeed(25);
	setVaule(10);
	sprite = Sprite::createWithSpriteFrameName("enemyRight3_1.png");
	addChild(sprite);
	animationRight = createAnimation("enemyRight3", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationRight, "runRight3");
	animationLeft = createAnimation("enemyLeft3", 4, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationLeft, "runLeft3");
	animationExplode = createAnimation("explode3", 6, 0.1f);
	AnimationCache::getInstance()->addAnimation(animationExplode, "explode3");
	createAndSetHpBar();
	schedule(schedule_selector(Bandit::changeDirection), 0.4f);
	return true;
}

void Bandit::changeDirection(float dt)
{
	auto curr = currPoint();
	if (curr == NULL)
	{
		return;
	}
	if(curr->getPositionX() > sprite->getPosition().x )
	{
		sprite->runAction( Animate::create(AnimationCache::getInstance()->getAnimation("runRight3"))) ;
	}else{
		sprite->runAction( Animate::create(AnimationCache::getInstance()->getAnimation("runLeft3"))  );
	}
}

void Bandit::enemyExploade()
{
	hpBgSprite->setVisible(false);
	sprite->stopAllActions();
	unschedule(schedule_selector(Bandit::changeDirection));
	sprite->setAnchorPoint(Point(0.5f, 0.25f));
	sprite->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("explode3"))
		,CallFuncN::create(CC_CALLBACK_0(EnemyBase::removeFromParent, this))
		, NULL));
}