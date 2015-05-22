#pragma once
#include "GameLogic.h"
#include <string>
#include <fstream>
using namespace std;

class IOManager
{
public:
	IOManager(GameLogic* gameLogic);
	~IOManager(void);

	void loadWeapons(string); //wczytuje bronie z podanej lokalizacji 
	void loadMachines(string); //wczytuje maszyny z podanej lokalizacji


protected:
	GameLogic* _gameLogic; 


protected: //MAGIC NUMBERS
	static const int NO_WEAPON = -1;
};

