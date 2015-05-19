#include "Weapon.h"


Weapon::Weapon(string name, int soft, int hard, int naval, int asw, int sead, int mob, char av)
{
	_name = name;
	_softAttack = soft;
	_hardAttack = hard;
	_navalAttack = naval;
	_ASWAttack = asw;
	_SEADAttack = sead;
	_mobility = mob;
	_availability = av;
}


Weapon::~Weapon(void)
{
}
