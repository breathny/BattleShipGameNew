#pragma once

//#ifndef SHIP_H //여기 두줄이 #pragma once라 동일한코드
//#define SHIP_H
//#endif // !SHIP_H
#include"header.h"

class CShip
{
public:
	CShip(void);
	~CShip(void);

	CShip(ShipType);

	void AddPosition(Position pos);			// (처음 세팅시에) 배의 영역을 추가한다.
	HitResult HitCheck(Position hitPos);	// 피격을 체크한다.
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


