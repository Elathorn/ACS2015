#pragma once
#include <vector>
#include "Weapon.h"
#include "Machine.h"
using namespace std;

class GameLogic //G��wna klasa gry, odpowiedzialna za wszystko co si� dzieje w niej oraz za komunikacj� gra-pliki, gra-interfejs
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

private:
	vector<Weapon*> _WeaponsList;
	vector<Machine*> _MachinesList;

protected:
};

