#pragma once
#include "Feature.h"

class Automation : public Feature
{
	bool playerAuto[8] = { true,false,false,false,false,false,false,false };

	void OnInitialise();

	void OnDraw();
	void OnMenuMainWindow();
	void OnMenuPlayerTreenode(Player* player, int playerIndex);

	void OnPlayerIteration(Player* player, int playerIndex);
	void OnUnitIteration(Unit* unit, Player* player, int playerIndex);
};