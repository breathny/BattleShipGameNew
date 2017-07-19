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
	void ShowAllField();
	Position GetAttackPosition();
	EHitResult HitCheck(Position pos);
	bool IsShipAlive();
	void DeployShip();
	void AddAttackHistory(Position position, EHitResult hitResult);
	EHitResult GetFieldAttackLog(Position pos);

	void PrintShip();
	void ShipDeployTest();


protected:
	std::vector<CShip*> m_pShipList;
	CField m_MyField;
	CField m_AttackHistoryField;
};

