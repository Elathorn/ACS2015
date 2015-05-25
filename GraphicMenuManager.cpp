#include "GraphicMenuManager.h"


GraphicMenuManager::GraphicMenuManager()
{
}


GraphicMenuManager::~GraphicMenuManager(void)
	{
	}


void GraphicMenuManager::runMenu()
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
	String str_menu[AMOUNT_OF_MENUS] = { L"Nowa Gra", L"Zakoñcz"};
	const int MENU_NEW_GAME = 0, MENU_END_GAME = 1;



	for (int i=0; i<AMOUNT_OF_MENUS; i++)
	{
		menus[i].setFont(_font);
		menus[i].setCharacterSize(MENU_TEXT_SIZE);
		menus[i].setString(str_menu[i]);
		menus[i].setPosition(RES_X/2-menus[i].getGlobalBounds().width/2,250+i*120);
	}


	while (_gameState==GAME_MENU) 
	{
		Vector2f mouse(Mouse::getPosition(*_mainWindow));
		Event event;
		while (_mainWindow->pollEvent(event)) //EVENT HANDLER
		{
			if (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && 
				menus[MENU_NEW_GAME].getGlobalBounds().contains(mouse))
			{
				_gameState=GAME_SP;

			}
			//koniec gry
			if (event.type == Event::Closed || event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left && menus[MENU_END_GAME].getGlobalBounds().contains(mouse))
			{
				_gameState=GAME_END;
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
