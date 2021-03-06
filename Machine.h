#pragma once
#include <string>
#include "Weapon.h"
#include <SFML\System\String.hpp>
using namespace std;

class Machine
{
public:
	//Konstruktor i destruktor
	Machine(string name, short int hp, char type, Weapon* weapon, int _mobility, int _view, char _status); //konstruktor do wczytywania
	//z plik�w, zar�wno layout�w maszyn jak i (przysz�o�ciowo) z save
	Machine(Machine& layout, char status); //konstruktor w�asciwy dla dodawania nowych maszyn dla gracza
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
protected:
	string _name;  //nazwa pojazdu
	int _hp; //liczba HP (0-100)
	char _type; // (H)eli, (A)ircraft
	Weapon* _weapon; //wska�nik do aktualnie wybranej broni 
	int _mobility; //"mobilno��" pojazdu, czyli zdolno�� do unikni�cia ataku
	int _view; //"wzrok" pojazdu, czyli og�lna zdolno�� do wykrywania wszystkiego
	char _status; //status pojazdu, (A)vailable, (B)usy, (D)estroyed, (L)ayout


protected:	//"MAGIC NUMBERS"
	static const char HELI='H';
	static const char AIRCRAFT='A';
	static const char AVAILABLE='A';
	static const char BUSY='B';
	static const char DESTROYED='D';
	static const char LAYOUT='L';

	static const int MAX_HP = 100;
	static const int MIN_HP = 0;
	static const int EFFICENT_THRESHOLD = 80;
	static const int DAMAGED_THRESHOLD = 60;
	static const int HEAVY_DAMAGED_THRESHOLD = 40;


};

