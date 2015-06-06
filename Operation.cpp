#include "Operation.h"


Operation::Operation(GameLogic* gameLogic, int missionWonCount, int missionLostCount)
{
	_gameLogic = gameLogic; //dostêp do gameLogic
	_missionWonCount = missionWonCount;
	_missionLostCount = missionLostCount;
	NUMBER_OF_MISSION_TYPES = gameLogic->getNumberOfMissionTypes();
	_nextMission = 0; 
	_lastScoutedMission = 0;
	srand(time(NULL));
	//generowanie operacji
	for (int i=0; i<MISSIONS_IN_OPERATION; i++)
	{
		_missionsList.push_back(rand()%NUMBER_OF_MISSION_TYPES-1); //losowanie misji na dany moment
		if ((rand()%100+1)<NO_MISSION_CHANCE)
			_missionsList[i]=NO_MISSION;
	}
}



Operation::~Operation(void)
	{
	}


void Operation::startMission(int id)
{
	if (NO_MISSION==_missionsList[id])
	{
		 //nie ma misji, nie ma zabawy :(
		//TO DO? ^ odwo³anie do interfejsu o tym, ¿e nic siê nie sta³o?
	}
	else
	{
		_gameLogic->calculateMission(_missionsList[id]);
	}
	if (++_nextMission == MISSIONS_IN_OPERATION)
		return; //TO DO metoda zwracaj¹ca kampanii informacji o zakoñczeniu operacji
	//TO DO zczyszczenie znaczników busy na potrzebê nastêpnej operacji
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}


void Operation::scout()
{
	if (_lastScoutedMission == MISSIONS_IN_OPERATION) //je¿eli wyspotowano wszystkie misje
		return; //metoda nic nie robi
	int lastScoutedMission=_nextMission; //pierwsza wyscoutowana misja
	//musi to byæ nastêpna misja, ¿eby gracz móg³ 
	int scoutPointsValue = BASE_SCOUT_CHANCE+_gameLogic->getCV()->getScoutPoints(); //liczymy iloœc "punktów zwiadu"
	while (scoutPointsValue > 0)
	{
		if (rand()%100+1 < scoutPointsValue) //losujemy czy uda³o siê odkryæ misje, jeœli tak
		{
			lastScoutedMission++; //zwiêkszamy licznik, misje musz¹ byæ odkrywane po kolei
			scoutPointsValue-=SCOUT_POINTS_LOST_PER_SCOUT; //zmniejszamy szansê na odkrycie nastêpnej misji
		}
		else
			scoutPointsValue=0; //misjê musz¹ byæ wykonywane po kolei, wiêc uniemo¿liwiamy nastêpne odkrycie

		if (lastScoutedMission == MISSIONS_IN_OPERATION)
		{
		_lastScoutedMission = lastScoutedMission;
		return;
		}
	}
	if (_lastScoutedMission < lastScoutedMission)
		_lastScoutedMission = lastScoutedMission;
}

void Operation::proceedTurn()
{
	if (_gameLogic->getActualMachine() == NULL) //jeœli nie wybrano maszyny
		return; //nic nie robimy
	startMission(_nextMission); //startujemy misje, nextMission roœnie o jeden
	scout(); //przeprowadzamy zwiad
	_gameLogic->getBusyManager()->busyEndTurnCheck(); //zajmujemy siê "zajêtymi" samolotami
}