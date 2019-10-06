#include "Player.h"
#include "Engine.h"
#include "Unit.h"
#include "ObjectManager.h"
#include <sstream>
#include <string>





std::vector<Unit*> Player::getUnitsByBaseId(int baseId)
{
	std::vector<Unit*> units;

	for (int i = 0; i < this->objectManager->iObjectCount; i++)
	{
		Unit* unit = this->objectManager->units[i];

		if (!unit || unit->pOwner != this || unit->pUnitData->Base_ID != baseId)
			continue;

		std::stringstream ss;
		ss << "selecting  " << unit->pUnitData->name <<"  base id :  " << unit->pUnitData->Base_ID << " ofs " << unit;
		std::string s = ss.str();
		std::string::iterator p = s.begin();
		char* chr = &(*p);

		Engine::Get()->SendChatMessage(chr);

		units.push_back(unit);
	}

	return units;
}