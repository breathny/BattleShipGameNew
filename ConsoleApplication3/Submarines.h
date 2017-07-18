#pragma once
#include "Ship.h"

class CSubmarines :
	public CShip
{
public:
	CSubmarines();
	~CSubmarines();
	virtual EHitResult HitCheck(Position hitPos);

};

