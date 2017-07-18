#include"stdafx.h"
#include "Destroyer.h"


CDestroyer::CDestroyer()
{
	m_Name = "Destroyer";
	m_Type = DESTROYER;
	m_HP = 2;
}


CDestroyer::~CDestroyer()
{
}
EHitResult CDestroyer::HitCheck(Position hitPos)
{
	EHitResult hitResult = CShip::HitCheck(hitPos);

	if (hitResult == DESTROYED)
		return DESTROY_DESTROYER;

	return hitResult;
}