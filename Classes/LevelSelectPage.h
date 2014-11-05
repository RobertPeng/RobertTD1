/**************************************************
	LevelSelectPage.h

	Robert	2014/09/09
**************************************************/
#ifndef __LEVELSELECTPAGE_H_
#define __LEVELSELECTPAGE_H_

#include "cocos2d.h"
USING_NS_CC;

class LevelSelectPage : public Node
{
public:
	LevelSelectPage();
	virtual ~LevelSelectPage();

	bool initLevelPage(const std::string& bgName, int level);
	static LevelSelectPage* create(const std::string& bgName, int level);
	void menuStartCallBack(Ref* pSender);
};

#endif