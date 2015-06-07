#pragma once
#include "Machine.h"
#include "AirCarrier.h"
#include "Weapon.h"
#include <SFML\Graphics.hpp>
#include <list>
using namespace std;
using namespace sf;

class BusyManager
{
public:
	BusyManager(void);
	~BusyManager(void);

	void busyEndTurnCheck();
	void addBusy(BusyManager* busy) {_busyManagers.push_back(busy);}
	virtual String busyEnd() {return "";}
	void createPopUp(String text);

protected:
	Machine* _machine;
	list<BusyManager*> _busyManagers;
	int _turns;

	
protected: //magic here, as always
	static const char AVAILABLE='A';
	static const char BUSY='B';
};

class BusyCombatManager: public BusyManager
{
public:
	BusyCombatManager(Machine*, AirCarrier*, int, int, int, int, int, bool, string);

	String busyEnd();
protected:
	AirCarrier* _cv;
	bool _victory;
	int _carrierHPChange;
	int _machineHPChange;
	int _pointsChange;
	int _scoutPointsChange;
	string _debrief; //debriefing
protected:
};

class BusyRearmManager: public BusyManager
{
public:
	BusyRearmManager(Machine*, int);
	String busyEnd();
protected:
};