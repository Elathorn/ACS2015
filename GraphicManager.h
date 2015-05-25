#pragma once
#include "IOManager.h"
#include "Campaign.h"
#include "GameLogic.h"
#include <SFML\Graphics.hpp>
using namespace sf;


class GraphicManager
{
protected:
	GraphicManager() {;}
	~GraphicManager(void) {;}

public:
	static int getGameState() {return _gameState;}
	static void setGameState(int gameState) {_gameState=gameState;}

protected:
	Font _font;
	static int _gameState;

public: //magic numbers potrzebne do zarz¹dzania z poziomu GraphicEngine
	static const int GAME_END = 0;
	static const int GAME_SP = 1;
	static const int GAME_MP = 2;
	static const int GAME_MENU = 3;
	
	static const int RES_X = 1280; //resolution X
	static const int RES_Y = 720; //resolution Y

//reszta magic numbers
	static const string GRAPHIC_LOCATION;
	static const string FONTS_LOCATION;
	static const int TITLE_TEXT_SIZE = 80;
	static const int MENU_TEXT_SIZE = 60;



	////////////////////////////////////////////
	//GraphicGameManager magic/////////////////
	//W tamtej klasie nie dzia³a jak powinno//
	/////////////////////////////////////////
	static const int GAME_STANDARD_TEXT_SIZE = 16;
};

