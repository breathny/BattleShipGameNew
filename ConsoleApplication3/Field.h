#pragma once
class CShip;
#include"header.h"

class CField
{
public:
	CField();
	~CField();
	CShip* m_pShip;
	HitResult m_HitResult;
	
	void SetFiledType(HitResult hitResult) { m_HitResult = hitResult; }
	HitResult GetFiledType() { return m_HitResult; }

	void SetShip(CShip* ship) { m_pShip = ship; }
	ShipType GetShipType();

};

