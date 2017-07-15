#pragma once
#include "header.h"
class CShip;
#include"Filed.h"
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
	std::vector<CShip*> m_ShipList;
	CFiled m_MyField[MAX_Y][MAX_X];
	CFiled m_YourField[MAX_Y][MAX_X];
	
};

