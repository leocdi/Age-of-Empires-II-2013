#include "Player.h"

#include "Unit.h"
#include "ObjectManager.h"





std::vector<Unit*> Player::getUnitsByBaseId(int baseId)
{
	std::vector<Unit*> units;

	for (int i = 0; i < this->objectManager->iObjectCount; i++)
	{
		Unit* unit = this->objectManager->units[i];

		if (!unit && unit->pOwner != this && unit->pUnitData->Base_ID != baseId)
			continue;

		units.push_back(unit);
	}

	return units;
}