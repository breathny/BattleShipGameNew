#pragma once
class CShip;
#include"header.h"

class CField
{
public:
	CField();
	~CField();
	
	void SetTile(Position pos, EHitResult hitResult, EShipType shipType);
	void SetAttackLog(Position pos, EHitResult hitResult);
	EHitResult GetFieldType(Position pos);
	EShipType GetShipType(Position pos);
	bool IsEmpty(Position pos);				//��ġ�� üũ�� �Լ�
	bool IsHit(Position pos);

protected:
	EHitResult m_TileArray[MAX_Y][MAX_X];
	EShipType m_ShipArray[MAX_Y][MAX_X];
};

