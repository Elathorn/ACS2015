#include "IOManager.h"


IOManager::IOManager(GameLogic* gameLogic)
{
	_gameLogic = gameLogic;
	loadWeapons("data/weapons.txt"); //wczytanie layoutów broni do systemu
	loadMachines("data/machines.txt"); //wczytanie layoutów maszyn
	loadMachinesOnCarrier("data/carrier_base_layout.txt");
	loadMissions("data/missions.txt");
}


IOManager::~IOManager(void)
	{
	}

void IOManager::jumpOverComment(ifstream& in)
{
	string temp;
	getline(in, temp, CHAR_COMMENT_END);
}

void IOManager::loadWeapons(string location)
{
	ifstream in (location.c_str()); 
	jumpOverComment(in); //metoda pozwalaj¹ca przeskoczyæ ponad komentarz do pliku z danymi
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
	jumpOverComment(in);
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

void IOManager::loadMachinesOnCarrier (string location)
{
	ifstream in(location.c_str());
	jumpOverComment(in);
	int machineID, weaponID; char status;
	Machine* machine;
	while (!in.eof())
	{
		in >> machineID >> weaponID >> status;
		machine = new Machine(*_gameLogic->getMachine(machineID), status); //kopiujemy maszyne z layoutu
		machine->setWeapon(_gameLogic->getWeapon(weaponID)); //dajemy jej broñ
		_gameLogic->getCV()->addMachine(machine);
	}

}

void IOManager::loadMissions (string location)
{
	ifstream in(location.c_str());
	jumpOverComment(in);
	string name; 
	int missionDif, soft, hard, naval, asw, sead, view, mobility, aircraft, heli, pointsReward, scoutReward, machineHPLossOnWin; 
	int pointsLoss, scoutLoss, machineHPLossOnLose, carrierHPLoss; 
	string missionInfo, missionWin, missionLose;
	while(!in.eof())
	{
		getline(in, name, CHAR_STRING_END);
		name.erase(0,1); //usuwanie znaku pocz¹tku nowej linii
		in >> missionDif;
		in >> soft >> hard >> naval >> asw >> sead;
		in >> view >> mobility >> aircraft >> heli;
		in >> pointsReward >> scoutReward >> machineHPLossOnWin;
		in >> pointsLoss >> scoutLoss >> machineHPLossOnLose >> carrierHPLoss;
		getline(in, missionInfo, CHAR_STRING_END);
		missionInfo.erase(0,1); //usuwanie znaku pocz¹tku nowej linii
		getline(in, missionWin, CHAR_STRING_END);
		missionWin.erase(0,1); //usuwanie znaku pocz¹tku nowej linii
		getline(in, missionLose, CHAR_STRING_END);
		missionLose.erase(0,1); //usuwanie znaku pocz¹tku nowej linii
		Mission* mission = new Mission(name, missionDif, soft, hard, naval, asw, sead, view, mobility, aircraft, heli, pointsReward, 
			scoutReward, machineHPLossOnWin, pointsLoss, scoutLoss, machineHPLossOnLose, carrierHPLoss, missionInfo, missionWin, missionLose);
		_gameLogic->addMission(mission);
	}
}