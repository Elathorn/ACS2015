#include "IOManager.h"

const string IOManager::DATA_FILES_LOCATION = "data/";

IOManager::IOManager(GameLogic* gameLogic, Campaign* campaign)
{
	_gameLogic = gameLogic;
	_campaign = campaign;
	loadWeapons(DATA_FILES_LOCATION+"weapons.txt"); //wczytanie layoutów broni do systemu
	loadMachines(DATA_FILES_LOCATION+"machines.txt"); //wczytanie layoutów maszyn
	loadMissions(DATA_FILES_LOCATION+"missions.txt"); //wczytanie misji
	loadCarrierStats(DATA_FILES_LOCATION+"carrier_stats.txt");  //stworzenie i ustawienie statystyk lotniskowca
	loadMachinesOnCarrier(DATA_FILES_LOCATION+"carrier_layout.txt"); //wyposa¿enie lotniskowca w maszyny
	loadCampaign(DATA_FILES_LOCATION+"campaign.txt");
}


IOManager::~IOManager(void)
	{
	}

void IOManager::jumpOverComment(ifstream& in)
{
	string comment;
	getline(in, comment, CHAR_COMMENT_END);
}

void IOManager::loadWeapons(string location)
{
	ifstream in (location.c_str()); 
	jumpOverComment(in); //metoda pozwalaj¹ca przeskoczyæ ponad komentarz do pliku z danymi
	string name; //zmienne tymczasowe do wczytywania danych z pliku
	int soft, hard, air, naval, asw, sead, mov;
	char av;
	while (in >> name >> soft >> hard >> air >> naval >> asw >> sead >> mov >> av) //g³ówna pêtla metody, wczytujemy dane
	{
		Weapon* weapon = new Weapon (name, soft, hard, air, naval, asw, sead, mov, av); //tworzymy layout
		_gameLogic->addWeapon(weapon); //i zapisujemy go w game logic
	}
}

void IOManager::loadMachines (string location)
{
	ifstream in(location.c_str());
	jumpOverComment(in);
	string name;
	int hp; char type; int weapon, mobility, view; char av;
	while (in >> name >> hp >> type >> weapon >> mobility >> view >> av)
	{
		Machine* machine;
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
	int i=0;
	while (in >> machineID >> weaponID >> status)
	{
		i++;
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
	int missionDif, soft, hard, air, naval, asw, sead, view, mobility, aircraft, heli, pointsReward, scoutReward, machineHPLossOnWin; 
	int pointsLoss, scoutLoss, machineHPLossOnLose, carrierHPLoss; 
	string missionInfo, missionWin, missionLose;
	while(!in.eof())
	{
		string temp;
		getline(in, temp, CHAR_STRING_START); //zczyszczenie wczeœniejszych znaków z bufora, w tym znaków nowej linii
		getline(in, name, CHAR_STRING_END); //i wczytanie w³aœciwego stringa
		in >> missionDif;
		in >> soft >> hard >> air >> naval >> asw >> sead;
		in >> view >> mobility >> aircraft >> heli;
		in >> pointsReward >> scoutReward >> machineHPLossOnWin;
		in >> pointsLoss >> scoutLoss >> machineHPLossOnLose >> carrierHPLoss;
		getline(in, temp, CHAR_STRING_START);
		getline(in, missionInfo, CHAR_STRING_END);
		getline(in, temp, CHAR_STRING_START);
		getline(in, missionWin, CHAR_STRING_END);
		getline(in, temp, CHAR_STRING_START);
		getline(in, missionLose, CHAR_STRING_END);
		Mission* mission = new Mission(name, missionDif, soft, hard, air, naval, asw, sead, view, mobility, aircraft, heli, pointsReward, 
			scoutReward, machineHPLossOnWin, pointsLoss, scoutLoss, machineHPLossOnLose, carrierHPLoss, missionInfo, missionWin, missionLose);
		_gameLogic->addMission(mission);
	}
}

void IOManager::loadCarrierStats (string location)
{
	ifstream in(location.c_str());
	jumpOverComment(in);
	int hp, points, scoutPoints, repairPoints;
	in >> hp >> points >> scoutPoints >> repairPoints;
	_gameLogic->createCV(hp, points, scoutPoints, repairPoints);
}

void IOManager::loadCampaign (string location)
{
	ifstream in(location.c_str());
	jumpOverComment(in);
	int countWon, countLost;
	in >> countWon >> countLost;
	_campaign->creatNewOperation(countWon, countLost);
}