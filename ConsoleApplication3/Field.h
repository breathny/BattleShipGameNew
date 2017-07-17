#pragma once
class CShip;
#include"header.h"

class CField
{
public:
	CField();
	~CField();
	
	void SetTile(Position pos, EFieldType fieldType, EShipType shipType);
	EFieldType GetFieldType(Position pos);
	EShipType GetShipType(Position pos);
	bool IsEmpty(Position pos);

protected:
	EFieldType m_TileArray[MAX_Y][MAX_X];
	EShipType m_ShipArray[MAX_Y][MAX_X];
};

