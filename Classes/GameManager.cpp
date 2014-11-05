/*******************************
	GameManager.cpp

	Robert		2014/09/20


*******************************/
#include "GameManager.h"

GameManager* GameManager::instance = NULL;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

GameManager* GameManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new GameManager();
	}
	return instance;
}