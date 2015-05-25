#include "GraphicGameManager.h"

TopBar::TopBar(RenderWindow& window, Campaign* campaign, GameLogic* gameLogic) : _window(window)
{
	_gameLogic=gameLogic;
	_campaign=campaign;
	_font.loadFromFile(GraphicManager::FONTS_LOCATION+"arial.ttf");
	for (int i=0; i<TOP_BAR_ELEMENTS; i++) //stworzenie elementów górnej belki
		topBar[i] = new Text("", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	actualTopBar(); //ustalenie tekstu
	for (int i=0; i<TOP_BAR_ELEMENTS; i++) //oraz pozycji
	{
		int x=10, j=i;
		while (j--)
			x+=topBar[j]->getGlobalBounds().width + 20;
		topBar[i]->setPosition(x, TOP_BAR_HEIGHT-TOP_BAR_HEIGHT/2-topBar[i]->getGlobalBounds().height/2);
	} 

}

void TopBar::actualTopBar()
{
	strTopBar[TopBarTurn] = L"Aktualna tura: " + to_string(_campaign->getOperation()->getNextMission());
	strTopBar[TopBarHP] = L"Wytrzyma³oœæ lotniskowca: " + _gameLogic->getCV()->getHPStatus();
	strTopBar[TopBarPoints] = L"Punkty: " + to_string( _gameLogic->getCV()->getPoints());
	strTopBar[TopBarScoutPoints] = L"Punkty zwiadu: " + to_string( _gameLogic->getCV()->getScoutPoints());
	for (int i=0; i<TOP_BAR_ELEMENTS; i++)
		topBar[i]->setString(strTopBar[i]);
}

void TopBar::drawTopBar()
{
		for (int i=0; i<TOP_BAR_ELEMENTS; i++)
		_window.draw(*topBar[i]);
}


GraphicGameManager::GraphicGameManager(RenderWindow& window, GameLogic* gameLogic, Campaign* campaign, IOManager* ioManager): _mainWindow(window)
{
	_font.loadFromFile(FONTS_LOCATION+"arial.ttf");
	_gameLogic=gameLogic;
	_campaign=campaign;
	_ioManager=ioManager;
}


GraphicGameManager::~GraphicGameManager(void)
	{
	}


void::GraphicGameManager::runGame()
{
	Texture backgroundImage; 
	backgroundImage.loadFromFile(GRAPHIC_LOCATION+"game_background.jpg");
	Sprite backgrondSprite;
	backgrondSprite.setTexture(backgroundImage);
	TopBar* topBar = new TopBar(_mainWindow, _campaign, _gameLogic);
	topBar->actualTopBar();

	while (GraphicManager::getGameState() == GAME_SP)
	{
		Vector2f mouse(Mouse::getPosition(_mainWindow));
		Event event;
		while(_mainWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				GraphicManager::setGameState(GAME_END);

		//JEŒLI NOWA TURA TO ZAKTUALIZOWAC LICZNIK TURY!!!!!!!!!!!!!!!!!!!
		}


	_mainWindow.clear();
	//RYSOWANIE
	_mainWindow.draw(backgrondSprite);
	topBar->drawTopBar();
	_mainWindow.display();
	}
}