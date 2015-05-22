#pragma once
#include "GameLogic.h"
#include <string>
#include <fstream>
#include "Mission.h"
using namespace std;

class IOManager // INPUT/OUTPUT manager
{
public:
	IOManager(GameLogic* gameLogic);
	~IOManager(void);

	void loadWeapons(string); //wczytuje bronie z podanej lokalizacji 
	void loadMachines(string); //wczytuje maszyny z podanej lokalizacji
	void loadMachinesOnCarrier(string); //wczytuje zestaw maszyn dla lotniskowca z lokalizacji 
	void loadMissions(string); //wczytuje misje

protected:
	GameLogic* _gameLogic; 
	void jumpOverComment(ifstream& in);

protected: //MAGIC NUMBERS
	static const int NO_WEAPON = -1;
	static const char CHAR_COMMENT_END = '!';
	static const char CHAR_STRING_END = '*';
};

