#include "Weapon.h"
#include "Machine.h"
#include "GameLogic.h"
#include "IOManager.h"
#include "Operation.h"
#include "GraphicManager.h"
#include <time.h>  
#include <clocale>
#include "GraphicEngine.h"

//temp
#include <iostream>
using namespace std;
//end of temp

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	/////////////////////////////////
	//Tworzenie podstawowych klas///
	///////////////////////////////
	GameLogic* gameLogic = new GameLogic();
	Campaign* campaign = new Campaign(gameLogic);
	IOManager* ioManager = new IOManager(gameLogic, campaign);
	////////////////////////////////////////////

	////////////////////////////////////////////
	GraphicEngine* graphicEngine = new GraphicEngine(gameLogic, campaign, ioManager);

    return 0;
	getchar();
}