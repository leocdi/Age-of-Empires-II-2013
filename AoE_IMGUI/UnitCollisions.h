#pragma once
#include "Feature.h"

class UnitCollisions : public Feature
{
	bool playerEsp[8] = { true,true,true,true,true,true,true,true };

	void OnUnitIteration(Unit* unit, Player* player, int playerIndex);
	void OnMenuPlayerTreenode(Player* player, int playerIndex);
};