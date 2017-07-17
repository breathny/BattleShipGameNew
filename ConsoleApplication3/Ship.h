#pragma once
#include"header.h"

class CShip
{
public:
	CShip(void);
	~CShip(void);

	void AddPosition(Position pos);					// (ó�� ���ýÿ�) ���� ������ �߰��Ѵ�.
	EHitResult HitCheck(Position hitPos, bool );	// �ǰ��� üũ�Ѵ�.
	std::string GetName(){ return m_Name;}
	EShipType GetType(){ return m_Type;}
	int GetHP() { return m_HP; }
	Position GetDirection() { return m_Direction; }
	void SetDirection(Position direction) { m_Direction = direction; }

	void PrintPosition();
	virtual void PrintTest();

protected:
	EShipType m_Type;	
	std::string m_Name;
	std::vector<Position> m_Pos;
	int		 m_HP;
	Position	m_Direction;
};


