#include "Campaign.h"


Campaign::Campaign(GameLogic* gameLogic)
{
	_gameLogic = gameLogic;
	_currentOperation = NULL;
}


Campaign::~Campaign(void)
	{
	}

void Campaign::creatNewOperation(int missionWonCount, int missionLostCount)
{
	delete _currentOperation; //kasujemy ew. star¹ operacje
	_currentOperation = new Operation (_gameLogic, missionWonCount, missionLostCount);
}