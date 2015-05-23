#include "Operation.h"


Operation::Operation(GameLogic* gameLogic, int missionWonCount, int missionLostCount)
{
	_gameLogic = gameLogic; //dostêp do gameLogic
	_missionWonCount = missionWonCount;
	_missionLostCount = missionLostCount;
	//generowanie operacji

}


Operation::~Operation(void)
	{
	}

void Operation::startMission(int id)
{
	if (!NO_MISSION)
		return; //nie ma misji, nie ma zabawy :(
	bool missionWon = _gameLogic->calculateMission(id);
	if (missionWon)
	{
		_missionWonCount++;
	}
	else
	{
		_missionLostCount++;
	}
}