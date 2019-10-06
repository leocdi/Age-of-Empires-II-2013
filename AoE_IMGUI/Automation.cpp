#include "Automation.h"

#include "Sdk.h"
#include "Input.h"
#include "time.h"
#include "Engine.h"
#include "Renderer.h"

#include <math.h>

void Automation::OnInitialise()
{

}

void Automation::OnDraw()
{

}

void Automation::OnMenuMainWindow()
{

}

void Automation::OnMenuPlayerTreenode(Player * player, int playerIndex)
{
	if (ImGui::TreeNode("Automation"))
	{
		ImGui::PushItemWidth(100);
		if (ImGui::TreeNode("Villager Production"))
		{
			static int defaultThreshold = 2;
			ImGui::PushItemWidth(100);
			ImGui::Checkbox("Enabled", &enabled);
			ImGui::SameLine();
			ImGui::SliderInt("Threshold", &defaultThreshold, 1, 5);
			ImGui::TreePop();
		}

		ImGui::TreePop();

	}
}

void Automation::OnPlayerIteration(Player * player, int playerIndex)
{
	if (enabled && &playerAuto[playerIndex] && Input::Get()->WasKeyPressed(VK_SPACE))
	{
		int tcId = (int)EnumUnitDataId::TownCenter;
		int threshold = 2;

		std::vector<Unit*> tcList = player->getUnitsByBaseId(tcId);

		int VK_KEY_C = 0x43; //my villager key

		float currentFood = player->Ressources->food;

		//would consider tc order by iQueuesize Desc but idk in c++
		for each(auto& tc in tcList)
		{
			if (currentFood >= 50 && tc->iQueuesize <= threshold)
			{

				tc->Select(player);

				clock_t startTime = clock(); //Start timer

				double secondsPassed;
				double secondsToDelay = 1;

				bool flagWait = true;
				while (flagWait)
				{
					secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;

					if (secondsPassed >= secondsToDelay)
					{
						//Engine::Get()->SendChatMessage("I am waiting tc to be truly selected, should be ok Now");
						flagWait = false;
					}
				}



				if (tc->bIsSelected == 1)
				{
					Input::Get()->SendKey(VK_KEY_C);
					Input::Get()->SendKey(VK_ESCAPE);
					currentFood = currentFood - 50;
				}
			}

		}
	}
}

void Automation::OnUnitIteration(Unit* unit, Player* player, int playerIndex)
{
	/*static Vector2 pos = Vector2(1, 1);
	unit->MoveTo(pos);
	pos = Vector2(unit->vPos.x, unit->vPos.z);*/
}