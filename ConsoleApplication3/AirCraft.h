#pragma once
#include "Ship.h"
class CAirCraft :
	public CShip
{
public:
	CAirCraft();
	~CAirCraft();
	virtual void PrintTest();
	virtual EHitResult HitCheck(Position hitPos);

};

