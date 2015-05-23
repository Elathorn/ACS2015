#include "Weapon.h"
#include "Machine.h"
#include "GameLogic.h"
#include "IOManager.h"
#include "Operation.h"
#include <time.h>  
#include <clocale>

//temp
#include <iostream>
using namespace std;
//end of temp

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	//Tworzenie podstawowych klas
	GameLogic* gameLogic = new GameLogic();
	Campaign* campaign = new Campaign(gameLogic);
	IOManager* ioManager = new IOManager(gameLogic, campaign);
	for (int i=0; i<15; i++)
		cout << campaign->getOperation()->getMissionFromList(i) << " ";
	cout << endl;
	for (int i=0; i<15; i++)
	{
	campaign->getOperation()->scout();
	campaign->getOperation()->startMission(campaign->getOperation()->getMissionFromList(campaign->getOperation()->getNextMission()));
	cout << i << "*" << campaign->getOperation()->getLastScoutedMission() << " " << campaign->getOperation()->getNextMission() << "*" << endl;
	for (int j=0; j<campaign->getOperation()->getLastScoutedMission(); j++)
		cout << j << " " << campaign->getOperation()->getMissionFromList(j) << " " << endl;
	cout << endl << " ****** " << endl;
	}



	getchar();
}