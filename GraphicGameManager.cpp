#include "GraphicGameManager.h"


GraphicGameManager::GraphicGameManager(void)
{

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
	
	//elementy górnej belki
	String strTopBar[TOP_BAR_ELEMENTS];
	const char TopBarTurn = 0, TopBarHP = 1, TopBarPoints = 2, TopBarScoutPoints = 3;
	strTopBar[TopBarTurn] = L"Aktualna tura: " + to_string(_campaign->getOperation()->getNextMission());
	strTopBar[TopBarHP] = L"Wytrzyma³oœæ lotniskowca: " + _gameLogic->getCV()->getHPStatus();
	strTopBar[TopBarPoints] = L"Punkty: " + to_string( _gameLogic->getCV()->getPoints());
	strTopBar[TopBarScoutPoints] = L"Punkty zwiadu: " + to_string( _gameLogic->getCV()->getScoutPoints());
	Text *topBar[TOP_BAR_ELEMENTS]={NULL};	//new Text(strActualTurn, _font, GAME_STANDARD_CHARACTER_SIZE);
	for (int i=0; i<TOP_BAR_ELEMENTS; i++) //aktualizacja elementów górnej belki
	{
		topBar[i] = new Text(strTopBar[i], _font, GAME_STANDARD_TEXT_SIZE);
		int x=10, j=i;
		while (j--)
			x+=topBar[j]->getGlobalBounds().width + 20;
		topBar[i]->setPosition(x, TOP_BAR_HEIGHT-TOP_BAR_HEIGHT/2-topBar[i]->getGlobalBounds().height/2);
	} 


	while (GraphicManager::getGameState() == GAME_SP)
	{
		Vector2f mouse(Mouse::getPosition(*_mainWindow));
		Event event;
		while(_mainWindow->pollEvent(event))
		{
			if (event.type == Event::Closed)
				GraphicManager::setGameState(GAME_END);

		//JEŒLI NOWA TURA TO ZAKTUALIZOWAC LICZNIK TURY!!!!!!!!!!!!!!!!!!!
		}


	_mainWindow->clear();
	//RYSOWANIE
	_mainWindow->draw(backgrondSprite);
	for (int i=0; i<TOP_BAR_ELEMENTS; i++)
		_mainWindow->draw(*topBar[i]);

	_mainWindow->display();
	}
}