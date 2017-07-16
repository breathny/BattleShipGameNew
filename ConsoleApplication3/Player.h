#pragma once
#include "header.h"

#include "Field.h"
class CShip;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void AddShip(ShipType type);
	bool IsEmptyField(Position position, DIRECTION direction, int size);
	void PlaceRandomPostion(CShip* ship);
	void ShowMyField();

	void PrintShip();
	void ShipDeployTest();
	
protected:
	std::vector<CShip*> m_pShipList;
	CField m_MyField[MAX_Y][MAX_X];
	CField m_YourField[MAX_Y][MAX_X];
	
};

