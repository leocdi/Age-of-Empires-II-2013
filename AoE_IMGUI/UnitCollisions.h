#pragma once
#include "Feature.h"

class UnitCollisions : public Feature
{
	bool playerEsp[8] = { false,true,true,true,true,true,true,true };
	float colors[8][3];
	uint32_t colors_hex[8] = { 0xffffffff, 0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xffffffff };

	void OnUnitIteration(Unit* unit, Player* player, int playerIndex);
	void OnMenuPlayerTreenode(Player* player, int playerIndex);
};