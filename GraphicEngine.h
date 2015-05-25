#pragma once
#include "IOManager.h"
#include "Campaign.h"
#include "GameLogic.h"
#include <SFML\Graphics.hpp>
#include "GraphicGameManager.h"
#include "GraphicMenuManager.h"
using namespace sf;

class GraphicEngine
{
public:
	GraphicEngine(GameLogic*, Campaign*, IOManager*);
	~GraphicEngine(void);


protected:
	GameLogic* _gameLogic;
	IOManager* _ioManager;
	Campaign* _campaign;
	RenderWindow* _mainWindow; 
	GraphicManager* _graphicManager;

	void runGraphic();

protected: //nioch nioch, magic
};
