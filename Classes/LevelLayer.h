/**************************************************
	LevelLayer.h

	Robert	2014/08/29
**************************************************/
#ifndef __LEVELLAYER_H_
#define __LEVELLAYER_H_

#include "cocos2d.h"
USING_NS_CC;

class LevelLayer : public Layer
{
public:
	LevelLayer();
	virtual ~LevelLayer();
	virtual bool init();
	CREATE_FUNC(LevelLayer);

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void addNode(Node *level);
private:
	void goToCurrNode();

private:
	int pageNode;
	int curPageNode;
	Point touchDownPoint;
	Point touchUpPoint;
	Point touchCurPoint;
	float WINDOW_WIDTH;
	float WINDOW_HEIGHT;
};

#endif