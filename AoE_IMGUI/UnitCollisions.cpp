#include "UnitCollisions.h"

#include "Sdk.h"
#include "Renderer.h"
#include "Engine.h"
#include "Input.h"


void DrawBox(Unit* unit, int32_t color)
{
	Vector3 one3 = unit->vPos;
	one3.x -= unit->pUnitData->collisionX;
	one3.z -= unit->pUnitData->collisionY;
	Vector2 one = Engine::Get()->worldToScreen(one3);

	Vector3 two3 = unit->vPos;
	two3.x += unit->pUnitData->collisionX;
	two3.z += unit->pUnitData->collisionY;
	Vector2 two = Engine::Get()->worldToScreen(two3);

	Vector3 three3 = unit->vPos;
	three3.x -= unit->pUnitData->collisionX;
	three3.z += unit->pUnitData->collisionY;
	Vector2 three = Engine::Get()->worldToScreen(three3);

	Vector3 four3 = unit->vPos;
	four3.x += unit->pUnitData->collisionX;
	four3.z -= unit->pUnitData->collisionY;
	Vector2 four = Engine::Get()->worldToScreen(four3);

	ImVec2 ivOne = ImVec2(one.x, one.y);
	ImVec2 ivTwo = ImVec2(two.x, two.y);
	ImVec2 ivThree = ImVec2(three.x, three.y);
	ImVec2 ivFour = ImVec2(four.x, four.y);

	Renderer::Get()->RenderRect(ivOne, ivFour, ivTwo, ivThree, color);
}

void UnitCollisions::OnUnitIteration(Unit* unit, Player* player, int playerIndex)
{
	if (playerEsp[playerIndex])
	{
		DrawBox(unit, colors_hex[playerIndex]);
	}
}

void UnitCollisions::OnMenuPlayerTreenode(Player * player, int playerIndex)
{
	if (ImGui::TreeNode("ESP"))
	{
		ImGui::PushItemWidth(100);
		ImGui::Checkbox("Enabled", &playerEsp[playerIndex]);
		if (ImGui::ColorPicker3("Color", colors[playerIndex],ImGuiColorEditFlags_NoPicker || ImGuiColorEditFlags_NoOptions || ImGuiColorEditFlags_NoSmallPreview ||  ImGuiColorEditFlags_NoInputs ||  ImGuiColorEditFlags_NoTooltip ||  ImGuiColorEditFlags_NoLabel || ImGuiColorEditFlags_NoSidePreview || ImGuiColorEditFlags_NoDragDrop))
		{
			int r = colors[playerIndex][0] * 255;
			int g = colors[playerIndex][1] * 255;
			int b = colors[playerIndex][2] * 255;
			colors_hex[playerIndex] = ((0xff) << 24) + ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		}
		ImGui::TreePop();
	}
	if (Input::Get()->WasKeyPressed(VK_F1))
	{
		enabled = !enabled;
	}
	if (Input::Get()->IsKeyDown(VK_F2))
	{
		enabled = !enabled;
	}
}