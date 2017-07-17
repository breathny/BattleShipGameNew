#pragma once
#include "header.h"
#include "Field.h"
class CShip;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void AddShip(EShipType type);
	//bool IsEmptyField(Position position, Position direction, int size);
	void PlaceRandomPostion(CShip* ship);
	void ShowMyField();

	void PrintShip();
	void ShipDeployTest();
	
protected:
	std::vector<CShip*> m_pShipList;
	CField m_MyField;
	CField m_YourField;
	
};

