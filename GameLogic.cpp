#include "GameLogic.h"


GameLogic::GameLogic(void)
{
	_cv = NULL;
}


GameLogic::~GameLogic(void)
	{
	}


bool GameLogic::calculateMission(int missionNumber)
{
	//TO DO
	Machine* machine = _cv->getMachine(0);
	//METODA DO WYBIERANIA SAMOLOTU
	//
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Mission* mission = _MissionsList[missionNumber];
	Weapon* weapon = machine->getWeapon();
	int missionDificulty = mission->getMissionDifficulty();
	int missionEfficiency=0; //skutecznoœæ na misji, od niej zale¿y, czy siê uda czy nie 
	missionEfficiency = mission->getSoftAttackMod() * weapon->getSoftAttack();
	missionEfficiency+= mission->getHardAttackMod() * weapon->getHardAttack();
	missionEfficiency+= mission->getAirAttackMod() * weapon->getAirAttack();
	missionEfficiency+= mission->getNavalAttackMod() * weapon->getNavalAttack();
	missionEfficiency+= mission->getASWAttackMod() * weapon->getASWAttack();
	missionEfficiency+= mission->getSEADAttackMod() * weapon->getSEADAttack();
	if (missionEfficiency > missionDificulty) //misja udana
	{
		_cv->changePoints(mission->getPointsReward()); 
		_cv->changeScoutPoints(mission->getScoutReward());
		machine->changeHP(- mission->getMachineHPLossOnWin()); //odejmujemy HP 
		//TO DO
		//PRZEKAZANIE INFORMACJI DO INTERFEJSU
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		return MISSION_WON;
	}
	else
	{
		_cv->changePoints(- mission->getPointsLoss());  //odejmujemy iloœæ punktów za przegran¹
		_cv->changeScoutPoints(- mission->getScoutLoss()); 
		machine->changeHP(- mission->getMachineHPLossOnLose());
		_cv->changeHP(- mission->getCarrierHPLoss());
		//TO DO
		//PRZEKAZANIE INFORMACJI DO INTERFEJSU
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		return MISSION_LOST;
	}

	
}


void GameLogic::createCV (int hp, int points, int scoutPoints)
{
	delete _cv; //kasujemy poprzedni lotniskowiec jeœli istnieje
	_cv = new AirCarrier(hp, points, scoutPoints); //i tworzymy nowy
}