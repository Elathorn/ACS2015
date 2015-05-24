#pragma once
#include "IOManager.h"
#include "Campaign.h"
#include "GameLogic.h"
#include <SFML\Graphics.hpp>

using namespace sf;


class GraphicManager
{
public:
	GraphicManager(GameLogic*, Campaign*, IOManager*);
	~GraphicManager(void);


protected:
	GameLogic* _gameLogic;
	IOManager* _ioManager;
	Campaign* _campaign;
	RenderWindow* _mainWindow; 
	enum GameState {MENU,GAME,GAME_OVER,END}; //Menu, game, game_over, end
	GameState _gameState;
	Font _font;

	void runMenu();
	void runGraphic();
	void runGame();

protected: //nioch nioch, magic
	static const int RES_X = 1280; //resolution X
	static const int RES_Y = 720; //resolution Y
	static const string GRAPHIC_LOCATION;
	static const string FONTS_LOCATION;
	static const int TITLE_TEXT_SIZE = 80;
	static const int MENU_TEXT_SIZE = 60;
	static const int GAME_STANDARD_TEXT_SIZE = 16;
	//górna belka ekranu gry
	static const int TOP_BAR_ELEMENTS = 4;
	static const int TOP_BAR_HEIGHT = 42;
};

