#pragma once
#include "GameMode.h"
#include <cstring>

class CShip
{
public:
	CShip(void);
	~CShip(void);

	CShip(ShipType);

	void AddPosition(Position pos);			// (ó�� ���ýÿ�) ���� ������ �߰��Ѵ�.
	HitResult HitCheck(Position hitPos);	// �ǰ��� üũ�Ѵ�.
	std::string GetName(){ return m_Name;}
	ShipType GetType(){ return m_Type;}
	int GetHP() { return m_HP; }

	void PrintPosition();
	 void PrintTest();

protected:
	ShipType m_Type;
	std::string m_Name;
	std::vector<Position> m_Pos;
	int		 m_HP;

};


