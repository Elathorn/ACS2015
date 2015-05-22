#include "IOManager.h"


IOManager::IOManager(GameLogic* gameLogic)
{
	_gameLogic = gameLogic;
	loadWeapons("data/weapons.txt"); //wczytanie layoutów broni do systemu
	loadMachines("data/machines.txt"); //wczytanie layoutów maszyn
}


IOManager::~IOManager(void)
	{
	}


void IOManager::loadWeapons(string location)
{
	ifstream in (location.c_str()); 
	string name; //zmienne tymczasowe do wczytywania danych z pliku
	int soft, hard, naval, asw, sead, mov;
	char av;
	while (!in.eof()) //g³ówna pêtla metody
	{
		in >> name >> soft >> hard >> naval >> asw >> sead >> mov >> av; //wczytujemy dane
		Weapon* weapon = new Weapon (name, soft, hard, naval, asw, sead, mov, av); //tworzymy layout
		_gameLogic->addWeapon(weapon); //i zapisujemy go w game logic
	}
}

void IOManager::loadMachines (string location)
{
	ifstream in(location.c_str());
	string name;
	int hp; char type; int weapon, mobility, view; char av;
	while (!in.eof())
	{
		Machine* machine;
		in >> name >> hp >> type >> weapon >> mobility >> view >> av;
		if (weapon != NO_WEAPON) //jeœli maszyna posiada zapisan¹ wczeœniej broñ
			machine = new Machine(name, hp, type, _gameLogic->getWeapon(weapon), mobility, view, av); //to wczytujemy j¹ i zapisujemy z
		else
			machine = new Machine(name, hp, type, NULL, mobility, view, av); //rzucamy pusty wskaŸnik na broñ
		_gameLogic->addMachine(machine); //zapisujemy w game logic
	}
}