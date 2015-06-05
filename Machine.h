#pragma once
#include <string>
#include "Weapon.h"
#include <SFML\Graphics.hpp>
using namespace std;

class Machine
{
public:
	//Konstruktor i destruktor
	Machine(string name, short int hp, char type, Weapon* weapon, int _mobility, int _view, char _status); //konstruktor do wczytywania
	//z plików, zarówno layoutów maszyn jak i (przysz³oœciowo) z save
	Machine(Machine& layout, char status); //konstruktor w³asciwy dla dodawania nowych maszyn dla gracza
	~Machine(void);
	//GETery
	string getName() {return _name;}
	int getHP() {return _hp;}
	sf::String getHPStatus(); //zwraca opisowy status maszyny
	char getType() {return _type;}
	Weapon* getWeapon() {return _weapon;}
	int getMobility() {return _mobility;}
	int getView() {return _view;}
	char getStatus() {return _status;}
	//SETery 
	void setWeapon(Weapon* weapon) {_weapon=weapon;}
	void setStatus(char status) {_status=status;}
	//inne
	void changeHP (int amount);
	//overload ==
	friend bool operator==(const Machine& lhs, const Machine& rhs)
	{
		if (lhs._hp == rhs._hp)
			if (true)
				return true;
		else
			return false;
	}
	friend bool operator!=(const Machine& lhs, const Machine& rhs) {return !(lhs==rhs);}
protected:
	string _name;  //nazwa pojazdu
	int _hp; //liczba HP (0-100)
	char _type; // (H)eli, (A)ircraft
	Weapon* _weapon; //wskaŸnik do aktualnie wybranej broni 
	int _mobility; //"mobilnoœæ" pojazdu, czyli zdolnoœæ do unikniêcia ataku
	int _view; //"wzrok" pojazdu, czyli ogólna zdolnoœæ do wykrywania wszystkiego
	char _status; //status pojazdu, (A)vailable, (B)usy, (D)estroyed, (L)ayout


public:	//"MAGIC NUMBERS"
	static const char HELI='H';
	static const char AIRCRAFT='A';
	static const char AVAILABLE='A';
	static const char BUSY='B';
	static const char DESTROYED='D';
	static const char LAYOUT='L';

	
protected:	//"MAGIC NUMBERS"
	static const int MAX_HP = 100;
	static const int MIN_HP = 0;
	static const int EFFICENT_THRESHOLD = 80;
	static const int DAMAGED_THRESHOLD = 60;
	static const int HEAVY_DAMAGED_THRESHOLD = 40;


};

