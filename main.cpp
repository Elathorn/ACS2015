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
	cout << gameLogic->getMachine(i)->getName() << endl;
	
	cout << gameLogic->getMachine(i)->getHP() << endl;
	cout << gameLogic->getMachine(i)->getHPStatus() << endl;
	cout << gameLogic->getMachine(i)->getType() << endl;
	cout << gameLogic->getMachine(i)->getWeapon()->getName() << endl;
	cout << gameLogic->getMachine(i)->getMobility() << endl;
	cout << gameLogic->getMachine(i)->getView() << endl;
	cout << gameLogic->getMachine(i)->getStatus() << endl;


	}
	getchar();
}