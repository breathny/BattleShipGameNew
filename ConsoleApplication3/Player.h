#pragma once
#include <vector>
#include<list>
#include"Ship.h"
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void AddShip(ShipType type);
	void PrintShip();
	
protected:
	std::vector<CShip*> pShipList;
	//CShip* shipList[5];
	

};

