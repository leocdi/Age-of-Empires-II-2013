#include "Automation.h"

#include "Sdk.h"
#include "Input.h"
#include "Engine.h"

#include <math.h>

void Automation::OnInitialise()
{

}

void Automation::OnDraw()
{
	if (Input::Get()->WasKeyPressed(VK_F1))
	{
		Engine::Get()->SendChatMessage("The");
		Engine::Get()->SendChatMessage("hack");
		Engine::Get()->SendChatMessage("can");
		Engine::Get()->SendChatMessage("now");
		Engine::Get()->SendChatMessage("send");
		Engine::Get()->SendChatMessage("text");
		Engine::Get()->SendChatMessage("messages");
		Engine::Get()->SendChatMessage("HYPE");
	}
}

void Automation::OnMenuMainWindow()
{
}

void Automation::OnMenuPlayerTreenode(Player * player, int playerIndex)
{
}

void Automation::OnPlayerIteration(Player * player, int playerIndex)
{
	
}

void Automation::OnUnitIteration(Unit* unit, Player* player, int playerIndex)
{

}