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
	static const int GAP_BEETWEN_ELEMENTS = 25;

protected:
	RenderWindow& _window;
	Campaign* _campaign;
	GameLogic* _gameLogic;
	String strTopBar[TOP_BAR_ELEMENTS];
	Font _font;
	Text *topBar[TOP_BAR_ELEMENTS];
};

class MissionsBar
{
public:
	MissionsBar (RenderWindow&, Campaign*, GameLogic*);
	void draw();
	void actualisation();
	void checkClick(Vector2f&, Event&);

protected:
	RenderWindow& _mainWindow;
	Campaign* _campaign;
	GameLogic* _gameLogic;
	Font _font; 
	Text* _text[Operation::MISSIONS_IN_OPERATION];

	

protected: //magic
	static const int GAP_BEETWEN_ELEMENTS = 10;
	static const int BAR_TOP_END = 81;
};