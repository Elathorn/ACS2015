#include "GraphicManager.h"
const string GraphicManager::GRAPHIC_LOCATION = "graphic/";
const string GraphicManager::FONTS_LOCATION = "graphic/fonts/";
int GraphicManager::_gameState = GAME_MENU;

GraphicManager::GraphicManager(GameLogic* gameLogic, Campaign* campaign, IOManager* ioManager)
{
	_gameLogic=gameLogic;
	_campaign=campaign;
	_ioManager=ioManager;
	_mainWindow = new RenderWindow(VideoMode(RES_X,RES_Y),"Aircraft Carrier Simulator 2015!",Style::Titlebar | Style::Close);
	_font.loadFromFile(FONTS_LOCATION+"arial.ttf"); //wczytanie czcionki
	
	_gameState=GraphicManager::GAME_MENU; //ustawiamy status na menu
}


GraphicManager::~GraphicManager(void)
{
	_mainWindow->close();
}

