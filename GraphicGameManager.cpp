#include "GraphicGameManager.h"

/////////////////////////////////
//TOP BAR///////////////////////
///////////////////////////////

TopBar::TopBar(RenderWindow& window, Campaign* campaign, GameLogic* gameLogic) : _window(window)
{
	_gameLogic=gameLogic;
	_campaign=campaign;
	_font.loadFromFile(GraphicManager::FONTS_LOCATION+"arial.ttf");
	for (int i=0; i<TOP_BAR_ELEMENTS; i++) //stworzenie elementów górnej belki
		topBar[i] = new Text("", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	actualTopBar(); //ustalenie tekstu oraz pozycji

	
}

void TopBar::actualTopBar()
{
	strTopBar[TopBarTurn] = L"Aktualna tura: " + to_string(_campaign->getOperation()->getNextMission());
	strTopBar[TopBarHP] = L"Wytrzyma³oœæ lotniskowca: " + _gameLogic->getCV()->getHPStatus();
	strTopBar[TopBarPoints] = L"Punkty: " + to_string( _gameLogic->getCV()->getPoints());
	strTopBar[TopBarScoutPoints] = L"Punkty zwiadu: " + to_string( _gameLogic->getCV()->getScoutPoints());
	for (int i=0; i<TOP_BAR_ELEMENTS; i++)
		topBar[i]->setString(strTopBar[i]);
	for (int i=0; i<TOP_BAR_ELEMENTS; i++)
	{
		int x=10, j=i;
		while (j--)
			x+=topBar[j]->getGlobalBounds().width + GAP_BEETWEN_ELEMENTS;
		topBar[i]->setPosition(x, TOP_BAR_HEIGHT-TOP_BAR_HEIGHT/2-topBar[i]->getGlobalBounds().height/2);
	} 
}

void TopBar::drawTopBar()
{
		for (int i=0; i<TOP_BAR_ELEMENTS; i++)
		_window.draw(*topBar[i]);
}


////////////////////////////
//MissionsBar
////////////////////////////

MissionsBar::MissionsBar(RenderWindow& window, Campaign* campaign, GameLogic* gameLogic): _mainWindow(window)
{
	_font.loadFromFile(GraphicManager::FONTS_LOCATION+"arial.ttf");
	_gameLogic=gameLogic;
	_campaign=campaign;
	for (int i=0; i<Operation::MISSIONS_IN_OPERATION; i++) //tworzymy teksty
		_text[i] = new Text ("", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	actualisation(); //aktualizujemy je 

}

void MissionsBar::actualisation()
{
	int i=0;
	for (i; i<_campaign->getOperation()->getLastScoutedMission(); i++) //dla wszystkich misji, które s¹ wykryte
		_text[i]->setString(_gameLogic->getMissionName(_campaign->getOperation()->getMissionFromList(i)));
						//bierzemy nazwê misji (bierzemy ID misji, która ma i'te miejsce w operacji [czyli dla aktualnej iteracji])
	for (i; i<Operation::MISSIONS_IN_OPERATION; i++) //dla reszty
		_text[i]->setString(L"Misja nieodkryta");
	i = 0;
	for (i; i<Operation::MISSIONS_IN_OPERATION; i++) //oraz ustalamy pozycje dla wszystkich
	{
		int x=GAP_BEETWEN_ELEMENTS + BAR_TOP_END, j=i;
		while (j--)
			x+=_text[j]->getGlobalBounds().height + GAP_BEETWEN_ELEMENTS;
		_text[i]->setPosition(20, x);
	} 
}

void MissionsBar::draw()
{
	for (int i=0; i<Operation::MISSIONS_IN_OPERATION; i++)
		_mainWindow.draw(*_text[i]);
}

void MissionsBar::checkClick(Vector2f& mouse, Event& event)
{
	//podkreœlanie aktualnie wybranej misji
	for (int i=0; i<Operation::MISSIONS_IN_OPERATION; i++)
		if (_text[i]->getGlobalBounds().contains(mouse))
			_text[i]->setStyle(Text::Underlined);
		else
			_text[i]->setStyle(Text::Regular);
	for (int i=0; i<Operation::MISSIONS_IN_OPERATION; i++) //wyœwietlanie informacji o misji po klikniêciu na ni¹
		if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && _text[i]->getGlobalBounds().contains(mouse))
		{
			//TODO: wyœwietlanie informacji o misji w nowym oknie
			//nowa metoda/klasa, przekazanie znacznika do konkretnej misji
		}
}

////////////////////////////
//Graphic Game Manager
////////////////////////////

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
	
	//CHWILOWE!!!!!!!!!!!!!!!!
	_campaign->getOperation()->scout(); //check it
	//END OF CHWILOWE!!!!!!!!!!!!!!!
	Texture backgroundImage; 
	backgroundImage.loadFromFile(GRAPHIC_LOCATION+"game_background.jpg");
	Sprite backgrondSprite;
	backgrondSprite.setTexture(backgroundImage);
	TopBar* topBar = new TopBar(_mainWindow, _campaign, _gameLogic);
	MissionsBar* missionsBar = new MissionsBar(_mainWindow, _campaign, _gameLogic);

	while (GraphicManager::getGameState() == GAME_SP)
	{
		Vector2f mouse(Mouse::getPosition(_mainWindow));
		Event event;
		while(_mainWindow.pollEvent(event))
		{
			missionsBar->checkClick(mouse, event);
			if (event.type == Event::Closed)
				GraphicManager::setGameState(GAME_END);

		//JEŒLI NOWA TURA TO ZAKTUALIZOWAC LICZNIK Top bara
			//topBar->actualTopBar();
			//missionsBar->actualisation();
		}


	_mainWindow.clear();
	//RYSOWANIE
	_mainWindow.draw(backgrondSprite);
	topBar->drawTopBar();
	missionsBar->draw();
	_mainWindow.display();
	}
}