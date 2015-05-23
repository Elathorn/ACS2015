#include "Weapon.h"
#include "Machine.h"
#include "GameLogic.h"
#include "IOManager.h"
#include "Operation.h"
#include <clocale>

//temp
#include <iostream>
using namespace std;
//end of temp

int main()
{
	setlocale(LC_ALL, "");
	//Tworzenie podstawowych klas
	GameLogic* gameLogic = new GameLogic();
	Campaign* campaign = new Campaign(gameLogic);
	IOManager* ioManager = new IOManager(gameLogic, campaign);
	
	cout << campaign->getOperation()->getMissionWonCount() << " "<< campaign->getOperation()->getMissionLostCount() <<  endl;
	cout << gameLogic->getCV()->getHP() << " " << gameLogic->getCV()->getPoints() << " " << gameLogic->getCV()->getScoutPoints() << endl;
	cout << gameLogic->getCV()->getMachine(0)->getHP() << endl;
	campaign->getOperation()->startMission(0);
	gameLogic->getCV()->getMachine(0)->setWeapon(gameLogic->getWeapon(1));
	cout << campaign->getOperation()->getMissionWonCount() << " "<< campaign->getOperation()->getMissionLostCount() <<  endl;
	cout << gameLogic->getCV()->getHP() << " " << gameLogic->getCV()->getPoints() << " " << gameLogic->getCV()->getScoutPoints() << endl;
	cout << gameLogic->getCV()->getMachine(0)->getHP() << endl;
	campaign->getOperation()->startMission(0);
	cout << campaign->getOperation()->getMissionWonCount() << " "<< campaign->getOperation()->getMissionLostCount() <<  endl;
	cout << gameLogic->getCV()->getHP() << " " << gameLogic->getCV()->getPoints() << " " << gameLogic->getCV()->getScoutPoints() << endl;
	cout << gameLogic->getCV()->getMachine(0)->getHP() << endl;
	getchar();
}