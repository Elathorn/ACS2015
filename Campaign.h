#pragma once
#include "Operation.h"

class Campaign
{
public:
	Campaign(GameLogic*);
	~Campaign(void);

	Operation* getOperation() {return _currentOperation;}

	void creatNewOperation(int, int);

protected:
	Operation* _currentOperation;
	GameLogic* _gameLogic;

};

