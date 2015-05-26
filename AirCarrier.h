#pragma once
#include "Machine.h"
#include <vector>
using namespace std;
using namespace sf;

class AirCarrier
{
public:
	AirCarrier(int, int, int, int);
	~AirCarrier(void);
	//carrier
	int getHP() {return _hp;}
	void changeHP(int);
	sf::String getHPStatus(); //zwraca opisowy status maszyny

	int getPoints() {return _points;}
	void changePoints(int);

	int getScoutPoints() {return _scoutPoints;}
	void changeScoutPoints(int);

	//machines
	void addMachine(Machine* machine) {_MachinesList.push_back(machine);} //dodanie maszyny do listy maszyn gry
	Machine* getMachine(int id) {return _MachinesList[id];}


protected:
	vector<Machine*> _MachinesList;
	int _hp; // od 0 do 100
	int _points; //zdobyte punkty
	int _scoutPoints; //punkty zwiadu, pozwalaj¹ lepiej odkrywaæ misje
	int _repairPoints; //punkty naprawy, przydzielane ka¿dej tury

protected: //magic numbers
	static const int MAX_HP = 100;
	static const int MIN_HP = 0;
	static const int EFFICENT_THRESHOLD = 80;
	static const int DAMAGED_THRESHOLD = 60;
	static const int HEAVY_DAMAGED_THRESHOLD = 40;
};

