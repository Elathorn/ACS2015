#pragma once
#include <vector>
#include "Weapon.h"
#include "Machine.h"
#include "AirCarrier.h"
#include "Mission.h"
#include "BusyManager.h"
#include <stdlib.h>  
using namespace std;

class GameLogic //G³ówna klasa gry, odpowiedzialna za wszystko co siê dzieje w niej oraz za komunikacjê gra-pliki, gra-interfejs
{
public:
	GameLogic(void);
	~GameLogic(void);

	//GETTERY i ADDERY
	void addWeapon(Weapon* weapon){_WeaponsList.push_back(weapon);}
	Weapon* getWeapon(int id) {return _WeaponsList[id];}

	void addMachine(Machine* machine) {_MachinesList.push_back(machine);}
	Machine* getMachine (int id) {return _MachinesList[id];}

	AirCarrier* getCV() {return _cv;}

	void addMission(Mission* mission) {_MissionsList.push_back(mission);}
	Mission* getMission (int id) {return _MissionsList[id];}
	int getNumberOfMissionTypes() {return _MissionsList.size();}

	//misje
	void calculateMission(int missionID);

	//
	void createCV(int, int, int, int);


	void setMachine(Machine* machine) {_machine=machine;}
protected:
	vector<Weapon*> _WeaponsList;
	vector<Machine*> _MachinesList;
	vector<Mission*> _MissionsList;
	
	Machine* _machine;

	AirCarrier* _cv;
	BusyManager* _busyManager;

protected: //magic words
	static const bool MISSION_WON = true;
	static const bool MISSION_LOST = false;
	static const int NO_CHANGE = 0;
	static const int NUMBER_OF_TURNS_IN_FIGHT = 3;
};

