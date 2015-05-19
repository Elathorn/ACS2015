#include "Machine.h"


Machine::Machine(string name, short int hp, char type, Weapon* weapon,  int mobility, int view)
{
	_name=name;
	_hp=hp;
	_type=type;
	_weapon=weapon;
	_mobility=mobility;
	_view=view;
}


Machine::~Machine(void)
{
}

void Machine::changeHP (int amount)
{
	_hp+=amount;
	if (_hp<0) //HP jest w granicach 0-100, zabezpieczenie przed wyjœciem poza zakres
		_hp=0;
	if (_hp>100)
		_hp=100;
}

string Machine::getHPStatus() //zwraca opisowy status maszyny
{
	if (_hp==100)
		return "Nienaruszony";
	if (_hp > 100 && _hp >= 80)
		return "Sprawny";
	if (_hp >80 && _hp >= 60)
		return "Uszkodzony";
	if (_hp > 60 && _hp >= 40)
		return "Ciê¿ko uszkodzony";
	if (_hp > 40 && _hp)
		return "Niesprawny";
	if (!_hp)
		return "Zniszczony";
}