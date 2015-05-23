#include "GameLogic.h"


GameLogic::GameLogic(void)
{
	_cv = NULL;
	_busyManager = new BusyManager();
}


GameLogic::~GameLogic(void)
	{
	}


void GameLogic::calculateMission(int missionNumber)
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
	BusyManager* newBusy = new BusyCombatManager(_cv, NUMBER_OF_TURNS_IN_FIGHT, NO_CHANGE, -mission->getMachineHPLossOnWin(), 
		mission->getPointsReward(), mission->getScoutReward(), MISSION_WON); //wartoœci do odjêcia przekazujemy jako ujemne
		_busyManager->addBusy(newBusy);
	}
	else
	{
	BusyManager* newBusy = new BusyCombatManager(_cv, NUMBER_OF_TURNS_IN_FIGHT, -mission->getCarrierHPLoss(), -mission->getMachineHPLossOnLose(),
		-mission->getPointsLoss(), -mission->getScoutLoss(), MISSION_LOST);	//wartoœci do odjêcia przekazujemy jako ujemne
		_busyManager->addBusy(newBusy);
	}

	
}


void GameLogic::createCV (int hp, int points, int scoutPoints, int repairPoints)
{
	delete _cv; //kasujemy poprzedni lotniskowiec jeœli istnieje
	_cv = new AirCarrier(hp, points, scoutPoints, repairPoints); //i tworzymy nowy
}