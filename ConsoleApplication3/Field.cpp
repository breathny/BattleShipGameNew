#include "stdafx.h"
#include "Field.h"
#include "Ship.h"


CField::CField()
{
	m_pShip = nullptr;
	m_HitResult = HitResult::NONE;
}


CField::~CField()
{
}

ShipType CField::GetShipType()
{
	return m_pShip->GetType();
}
