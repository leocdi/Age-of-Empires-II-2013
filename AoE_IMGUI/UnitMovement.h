#pragma once
#include "Feature.h"

class UnitMovement : public Feature
{
	void OnUnitIteration(Unit* unit, Player* player, int playerIndex);
	void OnMenuMainWindow();
};


