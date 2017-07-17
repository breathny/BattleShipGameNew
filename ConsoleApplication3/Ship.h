#pragma once
#include"header.h"

class CShip
{
public:
	CShip(void);
	~CShip(void);

	void AddPosition(Position pos);					// (처음 세팅시에) 배의 영역을 추가한다.
	EHitResult HitCheck(Position hitPos, bool );	// 피격을 체크한다.
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


