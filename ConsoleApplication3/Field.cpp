#include "stdafx.h"
#include "Field.h"
#include "Ship.h"


CField::CField()
{
	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			SetTile(Position(j, i), NONE, SHIPTYPE_NONE_MAX);
		}
	}
}

CField::~CField()
{
}

void CField::SetTile(Position pos, EHitResult hitResult, EShipType shipType)
{
	m_TileArray[pos.y][pos.x] = hitResult;
	m_ShipArray[pos.y][pos.x] = shipType;
}

void CField::SetAttackLog(Position pos, EHitResult hitResult)
{
	m_TileArray[pos.y][pos.x] = hitResult;
}

EHitResult CField::GetFieldType(Position pos)
{
	return m_TileArray[pos.y][pos.x];
}

EShipType CField::GetShipType(Position pos)
{
	return m_ShipArray[pos.y][pos.x];
}

bool CField::IsEmpty(Position pos)
{
	bool output = false;
	
	if (pos.x < 0
		|| pos.x > MAX_X - 1
		|| pos.y < 0
		|| pos.y > MAX_Y - 1)
	{
		return false;
	}

	if (m_ShipArray[pos.y][pos.x] == SHIPTYPE_NONE_MAX)
	{
		output = true;
	}

	//std::cout << "> IsEmpty(" << (char)(pos.y+'1') << ", " << (char)(pos.x+'A') << "); m_TileArry: " << m_TileArray[pos.y][pos.x] << std::endl;
	return output;
}
