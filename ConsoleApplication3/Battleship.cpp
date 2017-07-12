#include"stdafx.h"
#include "Battleship.h"


CBattleship::CBattleship()
{
	m_Name = "battleship";
	m_Type = BATTLESHIP;
	m_HP = 4;
}


CBattleship::~CBattleship()
{
}

void CBattleship::PrintTest()
{
	printf("BattleShip\n");
}
