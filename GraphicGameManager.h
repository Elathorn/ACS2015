#pragma once
#include "GraphicManager.h"	


class GraphicGameManager: public GraphicManager
{
public:
	GraphicGameManager(RenderWindow&, GameLogic*, Campaign*, IOManager*);
	~GraphicGameManager(void);

	void runGame();
protected:
	GameLogic* _gameLogic;
	IOManager* _ioManager;
	Campaign* _campaign;
	RenderWindow& _mainWindow;

protected: //some magic here, as always :3


};


class TopBar
{
public:
	TopBar (RenderWindow&, Campaign*, GameLogic*);
	void drawTopBar();
	void actualTopBar();

	
protected: //magic 
	static const char TopBarTurn = 0, TopBarHP = 1, TopBarPoints = 2, TopBarScoutPoints = 3;
	static const int TOP_BAR_ELEMENTS = 4;
	static const int TOP_BAR_HEIGHT = 42;

protected:
	RenderWindow& _window;
	Campaign* _campaign;
	GameLogic* _gameLogic;
	String strTopBar[TOP_BAR_ELEMENTS];
	Font _font;
	Text *topBar[TOP_BAR_ELEMENTS];
};