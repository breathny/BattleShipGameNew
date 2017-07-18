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
EHitResult CBattleship::HitCheck(Position hitPos)
{
	EHitResult hitResult = CShip::HitCheck(hitPos);

	if (hitResult == DESTROYED)
		return DESTROY_BATTLESHIP;

	return hitResult;
}