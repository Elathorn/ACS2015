#pragma once
#include "GameLogic.h"

class Operation
{
public:
	Operation(GameLogic*, int, int);
	~Operation(void);
	//GETtery
	int getMissionWonCount() {return _missionWonCount;}
	int getMissionLostCount() {return _missionLostCount;}
	int getLastScoutedMission() {return _lastScoutedMission;}
	int getMissionFromList(int id) {return _missionsList[id];}
	int getMissionInOperation() {return MISSIONS_IN_OPERATION;}
	int getNextMission() {return _nextMission;}

	//g��wne metody
	void startMission(int);
	void scout();

protected:
	GameLogic* _gameLogic;
	vector<int> _missionsList; //lista ID misji w operacji. Nie jest realnie potrzebne operowanie na wska�nikach do misji
	int _missionWonCount; //ilo�� wygranych misji, do statystyk
	int _missionLostCount; //ilo�� przegranych misji, do statystyk
	int _nextMission; //nast�pna misja w operacji jaka b�dzie wykonana (liczone od 0)
	int _lastScoutedMission; //ostatnia odkryta misja


protected: //magic numbers
	static const int MISSIONS_IN_OPERATION = 15; //ilo�� misji w operacji
	static const int NO_MISSION = -1; //brak misji, czas wolny
	static const int NO_MISSION_CHANCE = 33; //%
	int NUMBER_OF_MISSION_TYPES; //ilo�� r�nych misji
	static const int BASE_SCOUT_CHANCE = 100; 
	static const int SCOUT_POINTS_LOST_PER_SCOUT = 25;
};

