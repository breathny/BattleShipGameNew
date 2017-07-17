#include "stdafx.h"
#include "Field.h"
#include "Ship.h"


CField::CField()
{
	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			SetTile(Position(i, j), FIELD_NONE_MAX, SHIPTYPE_NONE_MAX);
		}
	}
}

CField::~CField()
{
}

void CField::SetTile(Position pos, EFieldType fieldType, EShipType shipType)
{
	m_TileArray[pos.y][pos.x] = fieldType;
	m_ShipArray[pos.y][pos.x] = shipType;
}

EFieldType CField::GetFieldType(Position pos)
{
	return m_TileArray[pos.y][pos.x];
}

EShipType CField::GetShipType(Position pos)
{
	return m_ShipArray[pos.y][pos.x];
}

bool CField::IsEmpty(Position pos)
{
	return (m_TileArray[pos.y][pos.x] != FIELD_NONE_MAX) ? true : false;
}
