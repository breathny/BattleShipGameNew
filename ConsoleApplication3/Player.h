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
	void PrintShip();
	void PlaceRandomPostion(CShip* ship);
	bool IsEmptyField(Position position, DIRECTION direction, int size);
	void ShowMyField();
	
protected:
	std::vector<CShip*> m_pShipList;
	CField m_MyField[MAX_Y][MAX_X];
	CField m_YourField[MAX_Y][MAX_X];
	
};

