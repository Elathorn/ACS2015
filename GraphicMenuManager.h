#pragma once
#include "GraphicManager.h"
class GraphicMenuManager: public GraphicManager
{
public:
	GraphicMenuManager(RenderWindow&, GameLogic*, Campaign*, IOManager*);
	~GraphicMenuManager(void);
	void runMenu();

protected:
	GameLogic* _gameLogic;
	IOManager* _ioManager;
	Campaign* _campaign;
	RenderWindow& _mainWindow; 
};

