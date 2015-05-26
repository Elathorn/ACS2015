#include "Machine.h"


Machine::Machine(String name, short int hp, char type, Weapon* weapon,  int mobility, int view, char status)
{
	_name=name;
	_hp=hp;
	_type=type;
	_weapon=weapon;
	_mobility=mobility;
	_view=view;
	_status=status;
}

Machine::Machine (Machine& layout, char status)
{
	_name=layout._name;
	_hp=layout._hp;
	_type=layout._type;
	_weapon=layout._weapon;
	_mobility=layout._mobility;
	_view=layout._view;
	_status=status;
}

Machine::~Machine(void)
{
}

void Machine::changeHP (int amount)
{
	_hp+=amount;
	if (_hp<MIN_HP) //HP jest w granicach 0-100, zabezpieczenie przed wyj�ciem poza zakres
	{
		_hp=MIN_HP;
		this->setStatus(DESTROYED); //maszyna ma 0 hp, ustawiamy status jako zniszczona
	}

	if (_hp>MAX_HP)
		_hp=MAX_HP;
}

sf::String Machine::getHPStatus() //zwraca opisowy status maszyny
{
	if (_hp==MAX_HP)
		return L"Nienaruszony";
	if (_hp >= EFFICENT_THRESHOLD)
		return L"Sprawny";
	if (_hp >= DAMAGED_THRESHOLD)
		return L"Uszkodzony";
	if (_hp >= HEAVY_DAMAGED_THRESHOLD)
		return L"Ci�ko uszkodzony";
	if (_hp > MIN_HP)
		return L"Niesprawny";
	if (!_hp)
		return L"Zniszczony";
}