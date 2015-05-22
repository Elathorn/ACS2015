#include "AirCarrier.h"


AirCarrier::AirCarrier(void)
	{
	}


AirCarrier::~AirCarrier(void)
	{
	}

void AirCarrier::changeHP (int amount)
{
	_hp+=amount;
	if (_hp<0) //HP jest w granicach 0-100, zabezpieczenie przed wyjœciem poza zakres
		_hp=0;
	if (_hp>100)
		_hp=100;
}