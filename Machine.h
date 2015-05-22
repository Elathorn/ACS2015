#pragma once
#include <string>
#include "Weapon.h"
using namespace std;

class Machine
{
public:
	//Konstruktor i destruktor
	Machine(string name, short int hp, char type, Weapon* weapon, int _mobility, int _view, char _status); //konstruktor do wczytywania
	//z plików, zarówno layoutów maszyn jak i (przysz³oœciowo) z save
	Machine(Machine& layout); //konstruktor w³asciwy dla dodawania nowych maszyn dla gracza
	~Machine(void);
	//GETery
	string getName() {return _name;}
	int getHP() {return _hp;}
	string getHPStatus(); //zwraca opisowy status maszyny
	char getType() {return _type;}
	Weapon* getWeapon() {return _weapon;}
	int getMobility() {return _mobility;}
	int getView() {return _view;}
	char getStatus() {return _status;}
	//SETery 
	void setWeapon(Weapon* weapon) {_weapon=weapon;}
	//inne
	void changeHP (int amount);
protected:
	string _name;  //nazwa pojazdu
	short int _hp; //liczba HP (0-100)
	char _type; // (H)eli, (A)ircraft
	Weapon* _weapon; //wskaŸnik do aktualnie wybranej broni 
	int _mobility; //"mobilnoœæ" pojazdu, czyli zdolnoœæ do unikniêcia ataku
	int _view; //"wzrok" pojazdu, czyli ogólna zdolnoœæ do wykrywania wszystkiego
	char _status; //status pojazdu, (A)vailable, (B)usy, (D)estroyed, (L)ayout


protected:	//"MAGIC NUMBERS"
	static const char HELI='H';
	static const char AIRCRAFT='A';
	static const char AVAILABLE='A';
	static const char BUSY='B';
	static const char DESTROYED='D';
	static const char LAYOUT='L';

};

