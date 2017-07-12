#pragma once

//#ifndef SHIP_H //���� ������ #pragma once�� �������ڵ�
//#define SHIP_H
//#endif // !SHIP_H
#include"header.h"

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
	DIRECTION GetDirection() { return m_Direction; }
	
	void SetDirection(DIRECTION direction) { m_Direction = direction; }

	void PrintPosition();
	virtual void PrintTest();

protected:
	ShipType m_Type;	
	std::string m_Name;
	std::vector<Position> m_Pos;
	int		 m_HP;
	DIRECTION	m_Direction;
};


