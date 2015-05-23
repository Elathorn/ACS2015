#pragma once
#include "GameLogic.h"
#include "Mission.h"
#include "Campaign.h"
#include <string>
#include <fstream>
using namespace std;


class IOManager // INPUT/OUTPUT manager
{
public:
	IOManager(GameLogic*, Campaign*);
	~IOManager(void);

	void loadWeapons(string); //wczytuje bronie z podanej lokalizacji 
	void loadMachines(string); //wczytuje maszyny z podanej lokalizacji
	void loadMachinesOnCarrier(string); //wczytuje zestaw maszyn dla lotniskowca z lokalizacji 
	void loadMissions(string); //wczytuje misje
	void loadCarrierStats(string); //wczytuje statystyki lotniskowca (hp, punkty, punkty zwiadu etc)
	void loadCampaign(string);

protected:
	GameLogic* _gameLogic; 
	Campaign* _campaign;
	void jumpOverComment(ifstream& in);

protected: //MAGIC NUMBERS
	static const int NO_WEAPON = -1;
	static const char CHAR_COMMENT_END = '!';
	static const char CHAR_STRING_END = '*';
	static const char CHAR_STRING_START = '*';
	static const string DATA_FILES_LOCATION;
};

