#include "stdafx.h"
#include "Filed.h"
#include "Ship.h"


CFiled::CFiled()
{
	m_pShip = nullptr;
	m_HitResult = HitResult::NONE;
}


CFiled::~CFiled()
{
}

ShipType CFiled::GetShipType()
{
	return m_pShip->GetType();
}
