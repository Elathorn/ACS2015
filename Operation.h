#pragma once
#include "GameLogic.h"

class Operation
{
public:
	Operation(GameLogic*, int, int);
	~Operation(void);
	int getMissionWonCount() {return _missionWonCount;}
	int getMissionLostCount() {return _missionLostCount;}

	void startMission(int);

protected:
	GameLogic* _gameLogic;
	vector<int> _missionsList; //lista ID misji w operacji. Nie jest realnie potrzebne operowanie na wektorach misji
	int _missionWonCount;
	int _missionLostCount;

protected:
	static const int MISSIONS_IN_OPERATION = 15;
	static const int NO_MISSION = -1;
};

