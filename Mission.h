#pragma once
#include <SFML\Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;
class Mission
{
public:
	Mission(String, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, string, string, string);
	~Mission(void);

	//GETery
	String getMissionName() {return _name;}

	int getMissionDifficulty() {return _missionDifficulty;}

	int getSoftAttackMod() {return _softAttackMod;}
	int getHardAttackMod() {return _hardAttackMod;}
	int getAirAttackMod() {return _airAttackMod;}
	int getNavalAttackMod() {return _navalAttackMod;}
	int getASWAttackMod() {return _ASWAttackMod;}
	int getSEADAttackMod() {return _SEADAttackMod;}

	int getViewMod() {return _viewMod;}
	int getMobilityMod() {return _mobilityMod;}
	int getAircraftMod() {return _aircraftMod;}
	int getHelicopterMod() {return _helicopterMod;}

	int getPointsReward() {return _pointsReward;}
	int getScoutReward() {return _scoutReward;}
	int getMachineHPLossOnWin() {return _machineHPLossOnWin;}

	int getPointsLoss() {return _pointsLoss;}
	int getScoutLoss() {return _scoutLoss;}
	int getMachineHPLossOnLose() {return _machineHPLossOnLose;}
	int getCarrierHPLoss() {return _carrierHPLoss;} 

	string getMissionInfo() {return _missionInfo;}
	string getMissionWin() {return _missionWin;}
	string getMissionLose() {return _missionLose;}
protected:
	String _name; //nazwa misji
	int _missionDifficulty; //poziom trudnoœci misji
	//Modyfikatory do trudnoœci wykonania misji
	int _softAttackMod; //modyfikator za soft attack
	int _airAttackMod;
	int _hardAttackMod;
	int _navalAttackMod;
	int _ASWAttackMod;
	int _SEADAttackMod;
	int _viewMod;
	int _mobilityMod;
	int _aircraftMod;
	int _helicopterMod;
	//Nagrody za wykonanie
	int _pointsReward; //punkty za wykonanie misji
	int _scoutReward; //bonus do wywiadu/zwiadu
	int _machineHPLossOnWin; //odjêcie HP w wypadku wygranej
	//Kary za niewykonanie
	int _pointsLoss; //strata punktów za przegran¹
	int _scoutLoss; 
	int _machineHPLossOnLose; 
	int _carrierHPLoss; //strata HP na lotniskowcu
	//Teksty
	string _missionInfo; //informacja o misji
	string _missionWin; //informacja po wygranej
	string _missionLose; //informacja po przegranej

protected: //MAGIC WORDS
};

