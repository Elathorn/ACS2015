#pragma once
#include "Machine.h"
#include <vector>

class AirCarrier
{
public:
	AirCarrier(void);
	~AirCarrier(void);
	//carrier
	int getHP() {return _hp;}
	void changeHP(int);

	//machines
	void addMachine(Machine* machine) {_MachinesList.push_back(machine);}
	Machine* getMachine(int id) {return _MachinesList[id];}


protected:
	vector<Machine*> _MachinesList;
	int _hp; // od 0 do 100
protected: //magic numbers
};

