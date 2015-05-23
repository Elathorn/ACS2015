#include "AirCarrier.h"


AirCarrier::AirCarrier(int hp, int points, int scoutPoints, int repairPoints)
{
	_hp=hp;
	_points=points;
	_scoutPoints=scoutPoints;
	_repairPoints=repairPoints;
}


AirCarrier::~AirCarrier(void)
{
	for(std::vector<Machine*>::iterator it = _MachinesList.begin(); it != _MachinesList.end(); ++it) 
	{
		delete *it;
	}
}

void AirCarrier::changeHP (int amount)
{
	_hp+=amount;
	if (_hp<MIN_HP) //HP jest w granicach 0-100, zabezpieczenie przed wyjœciem poza zakres
		_hp=MIN_HP;
	if (_hp>MAX_HP)
		_hp=MAX_HP;
}

void AirCarrier::changePoints (int amount)
{
	_points+=amount;
	if (_points < 0)
		_points = 0;
}

void AirCarrier::changeScoutPoints (int amount)
{
	_scoutPoints+=amount;
	if (_scoutPoints < 0)
		_scoutPoints = 0;
}