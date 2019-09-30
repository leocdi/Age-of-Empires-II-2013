#include "UnitMovement.h"

#include "Sdk.h"
#include "Renderer.h"
#include "Engine.h"

void DrawDestination(Unit* unit)
{
	bool canHaveDestination = unit->mileage > 0 && unit->fHealth > 0;
	if (canHaveDestination)
	{
		bool pointersNotNull = unit->pTarget != nullptr && unit->pTarget->pTarget != nullptr && unit->pTarget->pTarget->pTargetData != nullptr;
		if (pointersNotNull)
		{
			Vector2 destGamePos = unit->pTarget->pTarget->pTargetData->Destination;
			if (destGamePos.x > 0 && destGamePos.y > 0)
			{
				Vector2 destPosition = Engine::Get()->worldToScreen(destGamePos);
				Vector2 unitPosition = Engine::Get()->worldToScreen(unit);
				Renderer::Get()->RenderLine(ImVec2(unitPosition.x, unitPosition.y), ImVec2(destPosition.x, destPosition.y), 0x1fffffff, 0.5f);
			}
		}
	}
}

void UnitMovement::OnUnitIteration(Unit* unit, Player* player, int playerIndex)
{
	if (enabled)
	{
		DrawDestination(unit);
	}
}

void UnitMovement::OnMenuMainWindow()
{
	ImGui::Checkbox("DEST", &enabled);
}
