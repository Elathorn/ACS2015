#include "GraphicMachinesManager.h"

string GraphicMachinesManager::WeaponStatsToString(Weapon* weap)
{
	string text = to_string(weap->getSoftAttack()) + "/" + to_string(weap->getHardAttack()) + "/" + to_string(weap->getAirAttack()) + "/";
	text+= to_string(weap->getNavalAttack()) + "/" + to_string(weap->getASWAttack()) + "/" + to_string(weap->getSEADAttack());
	return text;
}

GraphicMachinesManager::GraphicMachinesManager(RenderWindow& window, GameLogic* gameLogic): _mainWindow(window), AMOUNT_OF_MACHINES(gameLogic->getCV()->getAmountOfMachines())
{
	_font.loadFromFile(GraphicManager::FONTS_LOCATION+"arial.ttf");
	_gameLogic=gameLogic;
	_cv=_gameLogic->getCV();
	for (int i = 0; i<AMOUNT_OF_MACHINES; i++)
	{
		Text* text;
		Machine* mach = _cv->getMachine(i); //dla u³atwienia zapisów i poprawienia czytelnoœci
		text = new Text (mach->getName() + " (" + mach->getHPStatus() + ")", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE); //pobieramy nazwy maszyn
		_machines.push_back(text);
		Weapon* weap = mach->getWeapon(); //dla u³atwienia zapisów i poprawienia czytelnoœci
		text = new Text (weap->getName(), _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);//i broni
		_weapons.push_back(text);
		string statistics_list = WeaponStatsToString(weap); //wczytujemy statystyki bronii do jednego tekstu
		text = new Text (statistics_list, _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
		_weaponsStats.push_back(text);
		statistics_list = to_string(mach->getMobility()+weap->getMobility()) + "/" + to_string(mach->getView());
		text = new Text (statistics_list, _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
		_machinesStats.push_back(text);
	}
	//teksty do informacji o samolotach
	_infoTexts[INFO_TEXT_MACHINE_AVAIBLE] = new Text(L"Maszyny gotowe", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	_infoTexts[INFO_TEXT_MACHINE_BUSY] = new Text(L"Maszyny zajête", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	_infoTexts[INFO_TEXT_MACHINE_DESTROYED] = new Text(L"Maszyny zniszczone", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	_infoTexts[INFO_TEXT_WEAPON] = new Text(L"Broñ zamontowana", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	_infoTexts[INFO_TEXT_WEAPON_STATS] = new Text(L"SA/HA/AA/NA/ASW/SEAD", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	_infoTexts[INFO_TEXT_MACHINE_STATS] = new Text(L"MOB/SCOUT", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	_infoTexts[INFO_TEXT_ACTIVE_MACHINE] = new Text(L"->", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	//ustawienie pozycji wszystkich elementów
	setPosition();
}


GraphicMachinesManager::~GraphicMachinesManager(void)
{
	for (int i=0; i<INFO_TEXTS_AMOUNT; i++)
		delete _infoTexts[i];
	for (int i=0; i<_machines.size(); i++)
	{
		delete _machines[i];
		delete _weapons[i];
		delete _weaponsStats[i];
		delete _machinesStats[i];
	}
}

void GraphicMachinesManager::actualTexts()
{	
	for (int i=0; i<AMOUNT_OF_MACHINES; i++)
	{ //czyszczenie pamiêci, która nie bêdzie ju¿ u¿ywana
		delete _weapons[i];
		delete _weaponsStats[i];
		delete _machinesStats[i];
	}
	//zwalnianie miejsca w vectorach
	_weapons.clear();
	_weaponsStats.clear();
	_machinesStats.clear();
	for (int i = 0; i<AMOUNT_OF_MACHINES; i++)
	{
		Text* text;
		Machine* mach = _cv->getMachine(i); //dla u³atwienia zapisów i poprawienia czytelnoœci
		Weapon* weap = mach->getWeapon(); //dla u³atwienia zapisów i poprawienia czytelnoœci
		text = new Text (weap->getName(), _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);//i broni
		_weapons.push_back(text);
		string statistics_list = WeaponStatsToString(weap); //wczytujemy statystyki bronii do jednego tekstu
		text = new Text (statistics_list, _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
		_weaponsStats.push_back(text);
		statistics_list = to_string(mach->getMobility()+weap->getMobility()) + "/" + to_string(mach->getView());
		text = new Text (statistics_list, _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
		_machinesStats.push_back(text);
	}
}

void GraphicMachinesManager::runWindow()
{
	while (_mainWindow.isOpen())
	{
		Event event;
		Vector2f mouse(Mouse::getPosition(_mainWindow));
		Texture backgroundImage; 
		backgroundImage.loadFromFile(GraphicManager::GRAPHIC_LOCATION+"machines_background.jpg");
		Sprite backgroundSprite;
		backgroundSprite.setTexture(backgroundImage);

		while(_mainWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				return;
			//podœwietlenia tekstów aktywnych
			for (int i=0; i<AMOUNT_OF_MACHINES; i++)
			{
				if (_machines[i]->getGlobalBounds().contains(mouse))
					_machines[i]->setColor(Color::Red);
				else 
					_machines[i]->setColor(Color::White);
				if (_weapons[i]->getGlobalBounds().contains(mouse))
					_weapons[i]->setColor(Color::Red);
				else 
					_weapons[i]->setColor(Color::White);
			}
			//zmiana maszyny wys³anej na misje
			for (int i=0; i<AMOUNT_OF_MACHINES; i++)
			{
				Machine* mach = _cv->getMachine(i);
				if (_machines[i]->getGlobalBounds().contains(mouse) && mach->getStatus()==Machine::AVAILABLE && event.type == Event::MouseButtonPressed)
					_gameLogic->setMachine(_cv->getMachine(i));
			}
			//zmiana wyposa¿enia
			for (int i=0; i<AMOUNT_OF_MACHINES; i++)
			{
				Machine* mach = _cv->getMachine(i);
				Weapon* weap = mach->getWeapon();
				if (_weapons[i]->getGlobalBounds().contains(mouse) && mach->getStatus()==Machine::AVAILABLE && event.type == Event::MouseButtonPressed)
				{
					mach->setWeapon(changeWeapon(mach->getType())); //zmieniamy broñ na maszynie
					if (mach->getWeapon() == NULL) //jeœli zmiana broni nie dojdzie do skutku
						mach->setWeapon(weap); //przywracamy star¹ broñ
					else
					{
						BusyManager* tempBusy = new BusyRearmManager(mach, GameLogic::NUMBER_OF_REARMENT_TURNS); //tworzymy status "busy" z powodu przezbrojenia
						_gameLogic->getBusyManager()->addBusy(tempBusy); //przekazujemy go do BusyManager
						actualTexts(); //aktualizujemy teksty
					}
				}
			}

		}
		setPosition();
		_mainWindow.clear();
		//rysowanie
		_mainWindow.draw(backgroundSprite);
		draw();
		//
		_mainWindow.display();
	}
}

void GraphicMachinesManager::draw()
{
	for (int i=0; i<INFO_TEXTS_AMOUNT; i++)
		_mainWindow.draw(*_infoTexts[i]);
	for (int i=0; i<_machines.size(); i++)
	{
		_mainWindow.draw(*_machines[i]);
		_mainWindow.draw(*_weapons[i]);
		_mainWindow.draw(*_weaponsStats[i]);
		_mainWindow.draw(*_machinesStats[i]);
	}
}

void GraphicMachinesManager::setPosition()
{
	//ustalenie bazowych koordynatów dla wszystkich tekstów wychodz¹cych poza ekran
	//"chowa to" nieu¿ywane statystyki
	_infoTexts[INFO_TEXT_ACTIVE_MACHINE]->setPosition(20000,2000);
	for (int i=0; i<_machines.size(); i++)
	{
		_weaponsStats[i]->setPosition(200000, 20000);
		_machinesStats[i]->setPosition(200000, 20000);
		_weapons[i]->setPosition(200000, 20000);
	}
	int y_coord = Y_COORD_TEXT_START;
	//ustalanie pozycji dla napisów informacyjnych o dostêpnych maszynach
	_infoTexts[INFO_TEXT_MACHINE_AVAIBLE]->setPosition(X_COORD_MACHINE_START, y_coord);
	_infoTexts[INFO_TEXT_WEAPON]->setPosition(X_COORD_WEAPON_START, y_coord);
	_infoTexts[INFO_TEXT_WEAPON_STATS]->setPosition(X_COORD_WEAPON_STATS_START, y_coord);
	_infoTexts[INFO_TEXT_MACHINE_STATS]->setPosition(X_COORD_MACHINE_STATS_START, y_coord);
	y_coord+=_infoTexts[INFO_TEXT_MACHINE_AVAIBLE]->getGlobalBounds().height + GAP_BEETWEN_ELEMENTS_Y;
	//ustalanie dla maszyn dostêpnych
	for (int i=0; i<AMOUNT_OF_MACHINES; i++)
	{
		if (_cv->getMachine(i)->getStatus() == Machine::AVAILABLE) //ustalamy koordynaty tylko dostêpnych maszyn
		{
			_machines[i]->setPosition(X_COORD_MACHINE_START, y_coord);
			_weapons[i]->setPosition(X_COORD_WEAPON_START, y_coord);
			_weaponsStats[i]->setPosition(X_COORD_WEAPON_STATS_START, y_coord);
			_machinesStats[i]->setPosition(X_COORD_MACHINE_STATS_START, y_coord);
			if (_gameLogic->getActualMachine() == _cv->getMachine(i))//jeœli jest to maszyna aktywna
				_infoTexts[INFO_TEXT_ACTIVE_MACHINE]->setPosition(X_COORD_MACHINE_START-_infoTexts[INFO_TEXT_ACTIVE_MACHINE]->getGlobalBounds().width-1, y_coord);
			y_coord+=GAP_BEETWEN_ELEMENTS_Y; //_machines[i]->getGlobalBounds().width/2 + 
		}
	}
	//ustalanie pozycji dla napisów informacyjnych o zajêtych maszynach
	y_coord+=_infoTexts[INFO_TEXT_MACHINE_DESTROYED]->getGlobalBounds().height + GAP_BEETWEN_ELEMENTS_Y;
	_infoTexts[INFO_TEXT_MACHINE_BUSY]->setPosition(X_COORD_MACHINE_START, y_coord);
	y_coord+=_infoTexts[INFO_TEXT_MACHINE_BUSY]->getGlobalBounds().height + GAP_BEETWEN_ELEMENTS_Y;
	//dla zajêtych
	for (int i=0; i<AMOUNT_OF_MACHINES; i++)
	{
		if (_cv->getMachine(i)->getStatus() == Machine::BUSY) //ustalamy koordynaty tylko dla zajêtych maszyn
		{
			_machines[i]->setPosition(X_COORD_MACHINE_START, y_coord);
			_weapons[i]->setPosition(X_COORD_WEAPON_START, y_coord);
			_weaponsStats[i]->setPosition(X_COORD_WEAPON_STATS_START, y_coord);
			_machinesStats[i]->setPosition(X_COORD_MACHINE_STATS_START, y_coord);
			y_coord+=GAP_BEETWEN_ELEMENTS_Y;//_machines[i]->getGlobalBounds().width/2 + 
		}
	}
	//ustalanie pozycji dla napisów informacyjnych o zniszczonych maszynach
	y_coord+=_infoTexts[INFO_TEXT_MACHINE_DESTROYED]->getGlobalBounds().height + GAP_BEETWEN_ELEMENTS_Y;
	_infoTexts[INFO_TEXT_MACHINE_DESTROYED]->setPosition(X_COORD_MACHINE_START, y_coord);
	y_coord+=_infoTexts[INFO_TEXT_MACHINE_DESTROYED]->getGlobalBounds().height + GAP_BEETWEN_ELEMENTS_Y;
	for (int i=0; i<AMOUNT_OF_MACHINES; i++)
	{
		if (_cv->getMachine(i)->getStatus() == Machine::DESTROYED) //ustalamy koordynaty tylko dla zniszczonych maszyn
		{
			_machines[i]->setPosition(X_COORD_MACHINE_START, y_coord);
			y_coord+=GAP_BEETWEN_ELEMENTS_Y; //_machines[i]->getGlobalBounds().width/2 + 
		}
	}
}


Weapon* GraphicMachinesManager::changeWeapon (char machineType)
{
	int weaponsAmount = _gameLogic->getWeaponsAmount();
	vector<Text*> weaponsStats; 
	vector<Text*> weaponsName;
	vector<Weapon*> weaponPointers; //przechowywanie wskaŸników do broni
	Text nameInfoText(L"Nazwa broni", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	Text statsInfoText(L"SA/HA/AA/NA/ASW/SEAD", _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
	for (int i=0; i<weaponsAmount; i++)
	{
		Weapon* weap = _gameLogic->getWeapon(i); 
		if (weap->getAvailability() == Weapon::CAN_MOUNT_ON_BOTH || weap->getAvailability() == machineType) //wczytanie broni dostêpnych na maszynie do vectora
		{
			string strWeaponStats = WeaponStatsToString(weap);
			Text* text = new Text(strWeaponStats, _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
			weaponsStats.push_back(text);
			text = new Text(weap->getName(), _font, GraphicManager::GAME_STANDARD_TEXT_SIZE);
			weaponsName.push_back(text);
			weaponPointers.push_back(weap); //zachowujemy wskaŸnik na wypadek jakby ta broñ zosta³a wybrana
		}
	}
	RenderWindow window(VideoMode(750,492), L"Wybór wyposa¿enia", Style::Titlebar | Style::Close); //stworzenie okna
	//wczytanie t³a
	Texture backgroundImage;
	backgroundImage.loadFromFile(GraphicManager::GRAPHIC_LOCATION+"weapon_select_background.jpg");
	Sprite background;
	background.setTexture(backgroundImage);
	//ustalanie pozycji tekstów
	nameInfoText.setPosition(20, 20);
	statsInfoText.setPosition(150, 20);
	for (int i=0; i<weaponsStats.size(); i++)
	{
		weaponsName[i]->setPosition(20, 40+i*GAP_BEETWEN_ELEMENTS_Y);
		weaponsStats[i]->setPosition(150, 40+i*GAP_BEETWEN_ELEMENTS_Y);
	}

	while (window.isOpen())
	{
		Vector2f mouse(Mouse::getPosition(window));;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				for (int i=0; i<weaponsStats.size(); i++)
				{ //czyszczenie pamiêci
					delete weaponsStats[i];
					delete weaponsName[i];
				}
				return NULL;
			}
			for (int i=0; i<weaponsName.size(); i++)
				if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Left && weaponsName[i]->getGlobalBounds().contains(mouse))
				{
					delete weaponsStats[i];
					delete weaponsName[i];
					return weaponPointers[i];
				}
			for (int i=0; i<weaponsName.size(); i++)
				if (weaponsName[i]->getGlobalBounds().contains(mouse))
					weaponsName[i]->setColor(Color::Red);
				else
					weaponsName[i]->setColor(Color::White);
		}
		//rysowanie
		window.clear();
		window.draw(background);
		for (int i=0; i<weaponsStats.size(); i++)
		{
			window.draw(*weaponsStats[i]);
			window.draw(*weaponsName[i]);
		}
		window.draw(nameInfoText);
		window.draw(statsInfoText);
		window.display();
	}
	return NULL;
}