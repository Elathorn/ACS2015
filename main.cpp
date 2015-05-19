#include "Weapon.h"
#include "Machine.h"

//temp
#include <iostream>
using namespace std;
//end of temp

int main()
{
	Weapon* weapon = new Weapon ("Maverick", 0, 50, 20, 0, 0, 0, 'B');
	Machine* aircraft = new Machine ("F16", 100, 'A', weapon);
	cout << weapon->getName() << endl << aircraft->getWeapon()->getHardAttack();
	cout << aircraft->getHP() << endl;
	aircraft->changeHP(5);
	cout << aircraft->getHP() << endl;
	aircraft->changeHP(-150);
	cout << aircraft->getHP() << endl;
	aircraft->changeHP(50);
	cout << aircraft->getHP() << endl;
	getchar();
}