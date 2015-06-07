#include "BusyManager.h"


BusyManager::BusyManager(void)
	{
		_busyManagers.clear();
	}


BusyManager::~BusyManager(void)
{
	for (list<BusyManager*>::const_iterator iterator = _busyManagers.begin(); iterator != _busyManagers.end(); ++iterator)
		{
			(*iterator)->busyEnd(); //wywo³ujemy natychmiastowe zakoñczenie wszelkich dzia³añ
			delete *iterator; //i kasujemy wskaŸnik
		}
}

void BusyManager::busyEndTurnCheck()
{
	for (list<BusyManager*>::const_iterator iterator = _busyManagers.begin(); iterator != _busyManagers.end();)
	{
		BusyManager* actualBusy = *iterator;
		if (!--actualBusy->_turns) //jeœli skoñczy³ siê okres w którym maszyna jest zajêta
		{
			createPopUp(actualBusy->busyEnd()); //wywo³ujemy funkcje odpowiadaj¹c¹ za koniec busy
			delete *iterator;
			iterator = _busyManagers.erase(iterator);
		}
		else
			++iterator;
	}
}

BusyCombatManager::BusyCombatManager(Machine* machine, AirCarrier* cv, int turns, int carrierHPChange, int machineHPChange, int pointsChange, 
									 int scoutPointsChange, bool victory, string debrief)
{
	_machine=machine;
	_cv=cv;
	_turns=turns;
	_carrierHPChange=carrierHPChange;
	_machineHPChange=machineHPChange;
	_pointsChange=pointsChange;
	_scoutPointsChange=scoutPointsChange;
	_victory=victory;
	_debrief = debrief;
	_machine->setStatus(BUSY); //ustawiamy status maszyny na busy
}

String BusyCombatManager::busyEnd()
{
	_cv->changeHP(_carrierHPChange);
	_cv->changePoints(_pointsChange);
	_cv->changeScoutPoints(_scoutPointsChange);
	_machine->changeHP(_machineHPChange);
	_machine->setStatus(AVAILABLE);
	string text;
	if (_victory)
		text = "MISJA UDANA!\n" + _machine->getName() + L" wraca z tarcz¹!\n";
	else
		text = "MISJA PRZEGRANA!\n" + _machine->getName() + " wraca na tarczy!\n";
	return text+_debrief;
	//TO DO
	//przekazanie informacji do operations o wygranej/przegranej
}

void BusyManager::createPopUp(String popUpString)
{
	Font font;
	font.loadFromFile("graphic/fonts/arial.ttf");
	RenderWindow popUpWindow(VideoMode(500,281), L"BREAKING NEWS  MIA¯D¯¥CE WIEŒCI  BREAKING NEWS", Style::Titlebar | Style::Close);
	Texture backgroundImage; 
	backgroundImage.loadFromFile("graphic/popup_background.jpg");
	Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundImage);
	Text popUpText(popUpString, font, 16);
	popUpText.setPosition((500-popUpText.getGlobalBounds().width)/2, 100);

	while (popUpWindow.isOpen())
	{
		Vector2f mouse(Mouse::getPosition(popUpWindow));
		Event event;
		while(popUpWindow.pollEvent(event))
		{
			if (event.type == Event::Closed || event.type == Event::MouseButtonPressed)
				popUpWindow.close();
		}
		popUpWindow.clear();
		popUpWindow.draw(backgroundSprite);
		popUpWindow.draw(popUpText);
		popUpWindow.display();
	}

}

BusyRearmManager::BusyRearmManager(Machine* machine, int turns)
{
	_machine = machine;
	machine->setStatus(BUSY);
	_turns=turns;
}

String BusyRearmManager::busyEnd()
{
	_machine->setStatus(AVAILABLE); //i nasza maszyna jest gotowa do boju
	return "Maszyna " + _machine->getName() + L" zakoñczy³a przezbrajanie.";
}
