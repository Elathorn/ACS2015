#include "GraphicEngine.h"


GraphicEngine::GraphicEngine(GameLogic* gameLogic, Campaign* campaign, IOManager* ioManager)
{
	_gameLogic=gameLogic;
	_campaign=campaign;
	_ioManager=ioManager;
	GraphicManager::setGameState(GraphicManager::GAME_MENU);
	runGraphic(); //odpalamy grafike
}


GraphicEngine::~GraphicEngine(void)
{
	
}


void GraphicEngine::runGraphic()
{
	_mainWindow = new RenderWindow(VideoMode(GraphicManager::RES_X,GraphicManager::RES_Y),"Aircraft Carrier Simulator 2015!",Style::Titlebar | Style::Close);
	GraphicGameManager* gameManager = new GraphicGameManager(*_mainWindow, _gameLogic, _campaign, _ioManager);
	GraphicMenuManager* menuManager = new GraphicMenuManager(*_mainWindow, _gameLogic, _campaign, _ioManager);

	while (_graphicManager->getGameState()!=GraphicManager::GAME_END)
	{
		switch(_graphicManager->getGameState())
		{
			case GraphicManager::GAME_MENU: 
				menuManager->runMenu();
			case GraphicManager::GAME_SP:
				gameManager->runGame();
			case GraphicManager::GAME_END:
				return;
		}
	}
	_mainWindow->close();
}