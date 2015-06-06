#pragma once
#include "GraphicManager.h"
#include "GraphicEngine.h"
using namespace sf;

class GraphicMachinesManager
{
public:
	GraphicMachinesManager (RenderWindow&, GameLogic*);
	~GraphicMachinesManager(void);
	void runWindow();
	void draw();
	void actualisation();
	void checkClick(Vector2f&, Event&);





protected: //magic
	static const int GAP_BEETWEN_ELEMENTS_Y = 18; //na osi Y
	static const int GAP_BEETWEN_ELEMENTS_X = 10; //na osi X
	static const int Y_COORD_TEXT_START = 150;
	
	static const int X_COORD_MACHINE_START = 65;
	static const int X_COORD_MACHINE_STATS_START = 225;
	static const int X_COORD_WEAPON_START = 325;
	static const int X_COORD_WEAPON_STATS_START = 485;
	const int AMOUNT_OF_MACHINES;

	//teksty informacyjne
	static const int INFO_TEXTS_AMOUNT = 7;
	static const int INFO_TEXT_MACHINE_AVAIBLE = 0, INFO_TEXT_MACHINE_BUSY = 1, INFO_TEXT_MACHINE_DESTROYED = 2, INFO_TEXT_WEAPON = 3, 
		INFO_TEXT_WEAPON_STATS = 4, INFO_TEXT_MACHINE_STATS = 5, INFO_TEXT_ACTIVE_MACHINE = 6;
protected:
	void actualTexts(); //aktualizuje teksty broni
	void setPosition(); //ustawia pozycje dla tekstów
	Weapon* changeWeapon(char); //zmienia broñ na maszynie
	string WeaponStatsToString(Weapon*); 


	RenderWindow& _mainWindow;
	GameLogic* _gameLogic;
	AirCarrier* _cv;
	Font _font; 
	Text* _infoTexts[INFO_TEXTS_AMOUNT];
	vector<Text*> _machines;
	vector<Text*> _weapons; //bronie maszyn, to samo ID w vectorze odpowiada parom
	vector<Text*> _weaponsStats; //statystyki broni, to samo ID w vectorze odpowiada parom
	vector<Text*> _machinesStats; //statystyki samolotów, to samo ID w vectorze odpowiada parom


	vector<Text*> _VIEW;
};