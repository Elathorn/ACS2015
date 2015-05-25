#pragma once
#include "GraphicManager.h"
class GraphicMenuManager: public GraphicManager
{
public:
	GraphicMenuManager();
	~GraphicMenuManager(void);
	void runMenu();

protected:
	RenderWindow& _mainWindow; 
};

