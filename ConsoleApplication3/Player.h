#pragma once
#include "header.h"
class CShip;
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void AddShip(ShipType type);
	void PrintShip();
	void PlaceRandomPostion(CShip* ship);
	bool IsEmptyFiled(Position position, DIRECTION direction, int size);
	
protected:
	std::vector<CShip*> m_ShipList;
	//CShip* shipList[5];
	

};

