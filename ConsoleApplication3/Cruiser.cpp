#include"stdafx.h"
#include "Cruiser.h"


CCruiser::CCruiser()
{
	m_Name = "Crusier";
	m_Type = CRUISER;
	m_HP = 3;
}


CCruiser::~CCruiser()
{
}
EHitResult CCruiser::HitCheck(Position hitPos)
{
	EHitResult hitResult = CShip::HitCheck(hitPos);

	if (hitResult == DESTROYED)
		return DESTROY_CRUISER;

	return hitResult;
}