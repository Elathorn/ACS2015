#pragma once
#include <vector>
#include "Weapon.h"
#include "Machine.h"
#include "AirCarrier.h"
#include "Mission.h"
#include <stdlib.h>  
using namespace std;

class GameLogic //G��wna klasa gry, odpowiedzialna za wszystko co si� dzieje w niej oraz za komunikacj� gra-pliki, gra-interfejs
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
	bool calculateMission(int missionID);

	//
	void createCV(int, int, int);
protected:
	vector<Weapon*> _WeaponsList;
	vector<Machine*> _MachinesList;
	vector<Mission*> _MissionsList;
	AirCarrier* _cv;

protected: //magic words
	static const bool MISSION_WON = true;
	static const bool MISSION_LOST = false;
};

