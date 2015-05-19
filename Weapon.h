#pragma once
#include <string>
using namespace std;
class Weapon
{
public:
	Weapon(string, int, int, int, int, int, int, char);
	~Weapon(void);
	//GETtery
	string getName() {return _name;}
	int getSoftAttack() {return _softAttack;}
	int getHardAttack() {return _hardAttack;}
	int getNavalAttack() {return _navalAttack;}
	int getASWAttack() {return _ASWAttack;}
	int getSEADAttack() {return _SEADAttack;}
	int getMobility() {return _mobility;}
	char getAvailability() {return _availability;}

protected:
	string _name;
	int _softAttack; //atak przeciwpiechocie 
	int _hardAttack; //atak przeciwpancerny
	int _navalAttack; //atak morski
	int _ASWAttack; //atak ASW (anti submarine warfare)
	int _SEADAttack; //atak SEAD (Suppression of Enemy Air Defenses)
	int _mobility; //zmiana w mobilnoœci pojazdu
	char _availability; //mo¿na zamontowaæ na H (heli), A (aircraft), B (both), N (neither, "brak na stanie")
};

