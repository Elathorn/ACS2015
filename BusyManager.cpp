#include "BusyManager.h"


BusyManager::BusyManager(void)
	{
	}


BusyManager::~BusyManager(void)
{
	for (list<BusyManager*>::const_iterator iterator = _busyManagers.begin(); iterator != _busyManagers.end(); ++iterator)
		{
			(*iterator)->busyEnd(); //wywo�ujemy natychmiastowe zako�czenie wszelkich dzia�a�
			delete *iterator; //i kasujemy wska�nik
		}
}

void BusyManager::busyEndTurnCheck()
{
	for (list<BusyManager*>::const_iterator iterator = _busyManagers.begin(); iterator != _busyManagers.end();)
	{
		BusyManager* actualBusy = *iterator;
		if (!--actualBusy->_turns) //je�li sko�czy� si� okres w kt�rym maszyna jest zaj�ta
		{
			actualBusy->busyEnd(); //wywo�ujemy funkcje odpowiadaj�c� za koniec busy
			delete *iterator;
			iterator = _busyManagers.erase(iterator);
		}
		else
			++iterator;
	}
}

BusyCombatManager::BusyCombatManager(Machine* machine, AirCarrier* cv, int turns, int carrierHPChange, int machineHPChange, int pointsChange, 
									 int scoutPointsChange, bool victory)
{
	_machine=machine;
	_cv=cv;
	_turns=turns;
	_carrierHPChange=carrierHPChange;
	_machineHPChange=machineHPChange;
	_pointsChange=pointsChange;
	_scoutPointsChange=scoutPointsChange;
	_victory=victory;
	_machine->setStatus(BUSY); //ustawiamy status maszyny na busy
}

void BusyCombatManager::busyEnd()
{
	_cv->changeHP(_carrierHPChange);
	_cv->changePoints(_pointsChange);
	_cv->changeScoutPoints(_scoutPointsChange);
	_machine->changeHP(_machineHPChange);
	_machine->setStatus(AVAILABLE);
	//TO DO
		//PRZEKAZANIE INFORMACJI DO INTERFEJSU
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TO DO
	//przekazanie informacji do operations o wygranej/przegranej
}

BusyRearmManager::BusyRearmManager(Weapon* weapon, int turns)
{
	_weapon=weapon;
	_turns=turns;
}

void BusyRearmManager::busyEnd()
{
	_machine->setWeapon(_weapon); //zmieniamy bro�
	_machine->setStatus(AVAILABLE); //i nasza maszyna jest gotowa do boju
	//TO DO
		//PRZEKAZANIE INFORMACJI DO INTERFEJSU
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}