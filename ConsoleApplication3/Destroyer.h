#pragma once
#include "Ship.h"
class CDestroyer :
	public CShip
{
public:
	CDestroyer();
	~CDestroyer();
	virtual EHitResult HitCheck(Position hitPos);

};

