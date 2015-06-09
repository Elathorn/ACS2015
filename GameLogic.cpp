#include "GameLogic.h"


GameLogic::GameLogic(void)
{
	_cv = NULL;
	_machine = NULL;
	_busyManager = new BusyManager();
}


GameLogic::~GameLogic(void)
	{
	}


void GameLogic::calculateMission(int missionNumber)
{
	Mission* mission = _MissionsList[missionNumber];
	Weapon* weapon = _machine->getWeapon();
	int missionDificulty = mission->getMissionDifficulty();
	int missionEfficiency=0; //skutecznoœæ na misji, od niej zale¿y, czy siê uda czy nie 
	missionEfficiency = mission->getSoftAttackMod() * weapon->getSoftAttack();
	missionEfficiency+= mission->getHardAttackMod() * weapon->getHardAttack();
	missionEfficiency+= mission->getAirAttackMod() * weapon->getAirAttack();
	missionEfficiency+= mission->getNavalAttackMod() * weapon->getNavalAttack();
	missionEfficiency+= mission->getASWAttackMod() * weapon->getASWAttack();
	missionEfficiency+= mission->getSEADAttackMod() * weapon->getSEADAttack();
	missionEfficiency+= mission->getMobilityMod() * (_machine->getMobility()+weapon->getMobility());
	missionEfficiency+= mission->getViewMod() * _machine->getView();
	if (_machine->getType() == Machine::AIRCRAFT) //jeœli maszyna jest samolotem
		missionEfficiency+= mission->getAircraftMod();
	else
		missionEfficiency+= mission->getHelicopterMod();
	if (missionEfficiency > missionDificulty) //misja udana
	{
	BusyManager* newBusy = new BusyCombatManager(_machine, _cv, NUMBER_OF_TURNS_IN_FIGHT, NO_CHANGE, -mission->getMachineHPLossOnWin(), 
		mission->getPointsReward(), mission->getScoutReward(), MISSION_WON, mission->getMissionWin()); //wartoœci do odjêcia przekazujemy jako ujemne
		_busyManager->addBusy(newBusy);
	}
	else
	{
	BusyManager* newBusy = new BusyCombatManager(_machine, _cv, NUMBER_OF_TURNS_IN_FIGHT, -mission->getCarrierHPLoss(), -mission->getMachineHPLossOnLose(),
		-mission->getPointsLoss(), -mission->getScoutLoss(), MISSION_LOST, mission->getMissionWin());	//wartoœci do odjêcia przekazujemy jako ujemne
		_busyManager->addBusy(newBusy);
	}
	_machine = NULL; //wybrany samolot wylecia³ na misje, wiêc nie ma ¿adnego, który móg³by podj¹æ siê misji
	
}


void GameLogic::createCV (int hp, int points, int scoutPoints, int repairPoints)
{
	delete _cv; //kasujemy poprzedni lotniskowiec jeœli istnieje
	_cv = new AirCarrier(hp, points, scoutPoints, repairPoints); //i tworzymy nowy
}

String GameLogic::getMissionName (int id)
{
	if (id==-1)
		return L"Czas Wolny";
	else
		return _MissionsList[id]->getMissionName();
}