#pragma once
#include "Machine.h"
#include "AirCarrier.h"
#include "Weapon.h"
#include <list>
using namespace std;



class BusyManager
{
public:
	BusyManager(void);
	~BusyManager(void);

	void busyEndTurnCheck();

	void addBusy(BusyManager* busy) {_busyManagers.push_back(busy);}
	virtual void busyEnd() {return;}

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
	BusyCombatManager(AirCarrier*, int, int, int, int, int, bool);

	void busyEnd();
protected:
	AirCarrier* _cv;
	bool _victory;
	int _carrierHPChange;
	int _machineHPChange;
	int _pointsChange;
	int _scoutPointsChange;
protected:
};

class BusyRearmManager: public BusyManager
{
public:
	BusyRearmManager(Weapon*, int);
	void busyEnd();
protected:
	Weapon* _weapon;
};