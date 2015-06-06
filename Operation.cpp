#include "Operation.h"


Operation::Operation(GameLogic* gameLogic, int missionWonCount, int missionLostCount)
{
	_gameLogic = gameLogic; //dost�p do gameLogic
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
		//TO DO? ^ odwo�anie do interfejsu o tym, �e nic si� nie sta�o?
	}
	else
	{
		_gameLogic->calculateMission(_missionsList[id]);
	}
	if (++_nextMission == MISSIONS_IN_OPERATION)
		return; //TO DO metoda zwracaj�ca kampanii informacji o zako�czeniu operacji
	//TO DO zczyszczenie znacznik�w busy na potrzeb� nast�pnej operacji
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}


void Operation::scout()
{
	if (_lastScoutedMission == MISSIONS_IN_OPERATION) //je�eli wyspotowano wszystkie misje
		return; //metoda nic nie robi
	int lastScoutedMission=_nextMission; //pierwsza wyscoutowana misja
	//musi to by� nast�pna misja, �eby gracz m�g� 
	int scoutPointsValue = BASE_SCOUT_CHANCE+_gameLogic->getCV()->getScoutPoints(); //liczymy ilo�c "punkt�w zwiadu"
	while (scoutPointsValue > 0)
	{
		if (rand()%100+1 < scoutPointsValue) //losujemy czy uda�o si� odkry� misje, je�li tak
		{
			lastScoutedMission++; //zwi�kszamy licznik, misje musz� by� odkrywane po kolei
			scoutPointsValue-=SCOUT_POINTS_LOST_PER_SCOUT; //zmniejszamy szans� na odkrycie nast�pnej misji
		}
		else
			scoutPointsValue=0; //misj� musz� by� wykonywane po kolei, wi�c uniemo�liwiamy nast�pne odkrycie

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
	if (_gameLogic->getActualMachine() == NULL) //je�li nie wybrano maszyny
		return; //nic nie robimy
	startMission(_nextMission); //startujemy misje, nextMission ro�nie o jeden
	scout(); //przeprowadzamy zwiad
	_gameLogic->getBusyManager()->busyEndTurnCheck(); //zajmujemy si� "zaj�tymi" samolotami
}