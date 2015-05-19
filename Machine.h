#pragma once
#include <string>
#include "Weapon.h"
using namespace std;

class Machine
{
public:
	//Konstruktor i destruktor
	Machine(string name, short int hp, char type, Weapon* weapon, int _mobility, int _view);
	~Machine(void);
	//GETery
	string getName() {return _name;}
	int getHP() {return _hp;}
	string getHPStatus(); //zwraca opisowy status maszyny
	char getType() {return _type;}
	Weapon* getWeapon() {return _weapon;}
	//SETery 

	//inne
	void changeHP (int amount);
private:
	string _name;  //nazwa pojazdu
	short int _hp; //liczba HP (0-100)
	char _type; // (H)eli, (A)ircraft
	Weapon* _weapon; //wskaŸnik do aktualnie wybranej broni 
	int _mobility; //"mobilnoœæ" pojazdu, czyli zdolnoœæ do unikniêcia ataku
	int _view; //"wzrok" pojazdu, czyli ogólna zdolnoœæ do wykrywania wszystkiego

};

