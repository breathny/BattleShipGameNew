#pragma once
#include "Ship.h"
class CCruiser :
	public CShip
{
public:
	CCruiser();
	~CCruiser();
	virtual EHitResult HitCheck(Position hitPos);

};

