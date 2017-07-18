#include"stdafx.h"
#include "Submarines.h"


CSubmarines::CSubmarines(void)
{
	m_Name = "Submarine";
	m_Type = SUBMARINE;
	m_HP = 1;

}


CSubmarines::~CSubmarines()
{
}
EHitResult CSubmarines::HitCheck(Position hitPos)
{
	EHitResult hitResult = CShip::HitCheck(hitPos);

	if (hitResult == DESTROYED)
		return DESTROY_SUBMARINE;

	return hitResult;
}