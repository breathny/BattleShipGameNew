#include"stdafx.h"
#include "Ship.h"

CShip::CShip(void)
{
	m_HP = 0;
	m_Direction = VERTICAL;
}

CShip::~CShip()
{
}

CShip::CShip(ShipType types)
{
	m_Type = types;
	
	switch (m_Type)
	{
	case AIRCRAFT:
		m_HP = 5;
		break;
	case BATTLESHIP:
		m_HP = 4;
		break;
	case CRUISER:
		m_HP = 3;
		break;
	case DESTROYER:
		m_HP = 2;
		break;
	case SUBMARINE:
		m_HP = 1;
		break;
	default:
		break;
	}
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
		std::cout << "position value is out of range position : " << pos.x << ", " << pos.y << std::endl;
		return;
	}
	
	m_Pos.push_back(pos);


}


HitResult CShip::HitCheck(Position hitPos)
{
	if ((hitPos.x == '0') || (hitPos.y == '0')|| (m_Pos.size() == 0))
	{
		return HitResult::MISS;
	}

	for (int i = 0; i < m_HP; i++)
	{
		if (m_Pos.size() < i)
			break;

		if ((hitPos.x == m_Pos[i].x)
			&& (hitPos.y == m_Pos[i].y))
		{
		/*	m_Pos.erase(m_Pos.begin() + i);
			m_HP--;
*/
			return (m_HP == 0)? HitResult::DESTROYED : HitResult::HIT;
			//if (m_HP <= 0) //삼항연산자로 줄일수 있다.
			//	return HitResult::DESTROYED;
			//else 
			//	return HitResult::HIT;
		}
	}
	return HitResult::MISS;
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

