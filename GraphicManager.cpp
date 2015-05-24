#include "GraphicManager.h"
const string GraphicManager::GRAPHIC_LOCATION = "graphic/";
const string GraphicManager::FONTS_LOCATION = "graphic/fonts/";

GraphicManager::GraphicManager(GameLogic* gameLogic, Campaign* campaign, IOManager* ioManager)
{
	_gameLogic=gameLogic;
	_campaign=campaign;
	_ioManager=ioManager;
	_mainWindow = new RenderWindow(VideoMode(RES_X,RES_Y),"Aircraft Carrier Simulator 2015!",Style::Titlebar | Style::Close);
	_gameState=MENU;
	_font.loadFromFile(FONTS_LOCATION+"arial.ttf"); //wczytanie czcionki

	runGraphic();
}


GraphicManager::~GraphicManager(void)
	{
	}

void GraphicManager::runGraphic()
{
	while (_gameState!=END)
	{
		switch(_gameState)
		{
			case GameState::MENU: 
				runMenu(); break;
			case GameState::GAME:
				runGame(); break;
			case END:
				_mainWindow->close();break;
		}
	}
}

void GraphicManager::runMenu()
{
	//stworzenie i wczytanie t³a menu
	Texture backgroundImage; 
	backgroundImage.loadFromFile(GRAPHIC_LOCATION+"menu_background.jpg");
	Sprite backgrondSprite;
	backgrondSprite.setTexture(backgroundImage);

	//stworzenie wyœwietlanych tekstów
	Text title ("Aircraft Carrier Simulator 2015!", _font, TITLE_TEXT_SIZE);
	title.setStyle(Text::Bold);
	title.setPosition(RES_X/2 - title.getGlobalBounds().width/2, 20);

	//deklaracja menu
	const int AMOUNT_OF_MENUS = 2;
	Text menus[AMOUNT_OF_MENUS]; 
	string str_menu[AMOUNT_OF_MENUS] = { "Nowa Gra", "Zakoñcz"};
	const int MENU_NEW_GAME = 0, MENU_END_GAME = 1;



	for (int i=0; i<AMOUNT_OF_MENUS; i++)
	{
		menus[i].setFont(_font);
		menus[i].setCharacterSize(MENU_TEXT_SIZE);
		menus[i].setString(str_menu[i]);
		menus[i].setPosition(RES_X/2-menus[i].getGlobalBounds().width/2,250+i*120);
	}


	while (_gameState==MENU) 
	{
		Vector2f mouse(Mouse::getPosition(*_mainWindow));
		Event event;
		while (_mainWindow->pollEvent(event)) //EVENT HANDLER
		{
			if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && 
				menus[MENU_NEW_GAME].getGlobalBounds().contains(mouse))
			{
				_gameState=GAME;

			}
			//koniec gry
			if (event.type == Event::Closed || event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && menus[MENU_END_GAME].getGlobalBounds().contains(mouse))
			{
				_gameState=END;
				return;
			}
			if (event.type == Event::MouseButtonPressed && title.getGlobalBounds().contains(mouse))
				{
				//miejsce na easteregga
				}

		}
		//sprawdzenie, czy mysz nie najecha³a na któryœ z menusów
		for (int i=0; i<AMOUNT_OF_MENUS; i++)
			if (menus[i].getGlobalBounds().contains(mouse))
				{
					menus[i].setColor(Color::Red);
					menus[i].setStyle(Text::Underlined);
				}
			else
				{
					menus[i].setColor(Color::White);
					menus[i].setStyle(Text::Regular);
				}

		_mainWindow->clear();
		//RYSOWANIE
		_mainWindow->draw(backgrondSprite); //t³o
		_mainWindow->draw(title); //tytu³
		for (int i=0; i<AMOUNT_OF_MENUS; i++) //menusy
		{
			_mainWindow->draw(menus[i]);
		}
		_mainWindow->display();
	}
}

/////////////////////////
//GAME GRAPHIC MANAGER//
///////////////////////

void::GraphicManager::runGame()
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


	while (_gameState == GAME)
	{
		Vector2f mouse(Mouse::getPosition(*_mainWindow));
		Event event;
		while(_mainWindow->pollEvent(event))
		{
			if (event.type == Event::Closed)
				_gameState = END;

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