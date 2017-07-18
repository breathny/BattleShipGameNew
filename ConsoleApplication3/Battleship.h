#pragma once
#include "Ship.h"
class CBattleship :
	public CShip
{
public:
	CBattleship();
	~CBattleship();
	virtual void PrintTest();
	virtual EHitResult HitCheck(Position hitPos);
};

