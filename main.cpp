#include "Weapon.h"
#include "Machine.h"
#include "GameLogic.h"
#include "IOManager.h"
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
	IOManager* ioManager = new IOManager(gameLogic);
	
	for (int i=0; i<2; i++)
		{
	cout << gameLogic->getMission(i)->getName() << endl;
	cout << gameLogic->getMission(i)->getMissionInfo() << endl;
	cout << gameLogic->getMission(i)->getMissionWin() << endl;
	cout << gameLogic->getMission(i)->getMissionLose() << endl;
		}



	
	getchar();
}