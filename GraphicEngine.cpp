#include "GraphicEngine.h"


GraphicEngine::GraphicEngine(GameLogic* gameLogic, Campaign* campaign, IOManager* ioManager)
{
	_gameLogic=gameLogic;
	_campaign=campaign;
	_ioManager=ioManager;
	_graphicManager = new GraphicManager(gameLogic, campaign, ioManager);//tworzymy GraphicManager (który tworzy okno gry)
	runGraphic(); //odpalamy grafike
}


GraphicEngine::~GraphicEngine(void)
{
	
}


void GraphicEngine::runGraphic()
{
	GraphicGameManager* gameManager = new GraphicGameManager();
	GraphicMenuManager* menuManager = new GraphicMenuManager();

	while (_graphicManager->getGameState()!=GraphicManager::GAME_END)
	{
		switch(_graphicManager->getGameState())
		{
			case GraphicManager::GAME_MENU: 
				menuManager->runMenu();
			case GraphicManager::GAME_SP:
				gameManager->runGame();
			case GraphicManager::GAME_END:
				delete _graphicManager; return;
		}
	}
}