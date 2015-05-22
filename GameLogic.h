#pragma once
#include <vector>
#include "Weapon.h"
#include "Machine.h"
#include "AirCarrier.h"
#include "Mission.h"
using namespace std;

class GameLogic //G³ówna klasa gry, odpowiedzialna za wszystko co siê dzieje w niej oraz za komunikacjê gra-pliki, gra-interfejs
{
public:
	GameLogic(void);
	~GameLogic(void);

	//MECHANIKA BRONI
	void addWeapon(Weapon* weapon){_WeaponsList.push_back(weapon);}
	Weapon* getWeapon(int id) {return _WeaponsList[id];}

	//MECHANIKA MASZYN
	void addMachine(Machine* machine) {_MachinesList.push_back(machine);}
	Machine* getMachine (int id) {return _MachinesList[id];}

	//MECHANIKA LOTNISKOWCA
	AirCarrier* getCV() {return _cv;}

	//MECHANIKA MISJI
	void addMission(Mission* mission) {_MissionsList.push_back(mission);}
	Mission* getMission (int id) {return _MissionsList[id];}
protected:
	vector<Weapon*> _WeaponsList;
	vector<Machine*> _MachinesList;
	vector<Mission*> _MissionsList;
	AirCarrier* _cv;

protected:
};

