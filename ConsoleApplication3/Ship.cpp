#include"stdafx.h"
#include "Ship.h"

CShip::CShip(void)
{
	m_HP = 0;
	m_Direction = Position(0,0);
}

CShip::~CShip()
{
}

void CShip::AddPosition(Position pos)
{
	Position tmp = pos;
	if (tmp.x > 'a')
	{
		tmp.x -= 32;
	}

	if ((pos.x < 'A') || (pos.x > 'H') || (pos.y < '1') || (pos.y > '8'))
	{
		return;
	}
	
	m_Pos.push_back(pos);
}


EHitResult CShip::HitCheck(Position hitPos, bool isCheckOnly = false)
{
	if ((hitPos.x == '0') || (hitPos.y == '0')|| (m_Pos.size() == 0))
	{
		return EHitResult::MISS;
	}

	for (int i = 0; i < m_HP; i++)
	{
		if (m_Pos.size() <= i)
			break;

		if ((hitPos.x == m_Pos[i].x)
			&& (hitPos.y == m_Pos[i].y))
		{
			if (isCheckOnly == false)
			{
				m_Pos.erase(m_Pos.begin() + i);
				m_HP--;
			}

			return (m_HP == 0)? EHitResult::DESTROYED : EHitResult::HIT;
			//if (m_HP <= 0) //���׿����ڷ� ���ϼ� �ִ�.
			//	return HitResult::DESTROYED;
			//else 
			//	return HitResult::HIT;
		}
	}
	return EHitResult::MISS;
}

void CShip::PrintPosition()
{
	for (int i = 0; i < m_Pos.size(); i++)
	{
		printf("%s Position[%d] - %c%c\n", m_Name.c_str(), i, m_Pos[i].x, m_Pos[i].y);
	}
}

void CShip::PrintTest()
{
	printf("Ship\n");
}