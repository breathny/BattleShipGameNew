#include "stdafx.h"
#include "Player.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarines.h"
#include "Destroyer.h"
#include "Ship.h"
#include "header.h"


CPlayer::CPlayer()
{
	AddShip(AIRCRAFT);
	AddShip(BATTLESHIP);
	AddShip(CRUISER);
	AddShip(DESTROYER);
	AddShip(SUBMARINE);

	for (auto pShip : m_ShipList)
	{
		PlaceRandomPostion(pShip);
		pShip->PrintPosition();
	}

}


CPlayer::~CPlayer()
{	
	
	for (auto pShip : m_ShipList)
	{
		if(pShip != NULL) delete pShip;
	}
	m_ShipList.clear();
	
}

void CPlayer::AddShip(ShipType type)
{
	/*shipList[0] = new CAirCraft();
	shipList[1] = new CBattleship();
	shipList[2] = new CCruiser();
	shipList[3] = new CDestroyer();
*/

	switch(type)
	{
	case AIRCRAFT:
	{
		CAirCraft* aircraft = new CAirCraft();
		m_ShipList.push_back(aircraft);
	}
		break;
	case BATTLESHIP:
	{
		CBattleship* battleShip = new CBattleship();
		m_ShipList.push_back(battleShip);
	}
		break;
	case CRUISER:
	{
		CCruiser* cruiser = new CCruiser();
		m_ShipList.push_back(cruiser);

	}
		break;
	case DESTROYER:
	{
		CDestroyer *destroyer= new CDestroyer();
		m_ShipList.push_back(destroyer);
	}
		
		break;
	case SUBMARINE:
	{
		CSubmarines* submarines = new CSubmarines();
		m_ShipList.push_back(submarines);
	}
		
		break;
	
	}
	
}

void CPlayer::PrintShip()
{
	for (int i = 0; i < (int)m_ShipList.size(); i++)
	{
		(*m_ShipList[i]).PrintTest();

	}

}

bool CPlayer::IsEmptyFiled(Position position, DIRECTION direction,int size)
{
	if ( (direction == HORIZON &&  position.x + size >= ('A' +MAX_X) ) 
		|| (direction == VERTICAL && position.y + size <= ('1'+ MAX_Y)) )
		return false;
	

	for (auto pShip : m_ShipList)
	{
		if (pShip->HitCheck(position) != MISS)// 놓으려는 위치에 배가 있는지 체크
			return false;

		if (pShip->GetDirection() != direction) //방향이 같을때만 아랫줄로.
			continue;

		if (direction == HORIZON)
		{
			int tempX =position.x;
			for (int i = 0; i < pShip->GetHP(); i++)
			{
				if (pShip->HitCheck(Position(tempX, position.y)) != MISS)
					return false;
				tempX += 1;
			}
		}
		else
		{
			int tempY = position.y;
			for (int i = 0; i < pShip->GetHP(); i++)
			{
				if (pShip->HitCheck(Position(position.x, tempY)) != MISS)
					return false;
				tempY += 1;
			}
		}
	}

	return true;

}
void CPlayer::PlaceRandomPostion(CShip* pShip)
{
	Position randomPosition;
	DIRECTION  randomDirection;

	randomPosition.x = 'A' + (rand() %((int)MAX_X));
	randomPosition.y = '1' + (rand() % ((int)MAX_Y));
	randomDirection = (DIRECTION)(rand() % (int)DIRECTION::MAX);

	std::cout << randomPosition.x<<std::endl;
	std::cout << randomPosition.y<<std::endl;
	std::cout << randomDirection << std::endl;
	std::cout << " ========================== " << std::endl;

	////엠티인지 체크 
	while (IsEmptyFiled(randomPosition, randomDirection,pShip->GetHP()) == false)
	{
		randomPosition.x = 'A' + (rand() % ((int)MAX_X));
		randomPosition.y = '1' + (rand() % ((int)MAX_Y));
		randomDirection = (DIRECTION)(rand() % (int)DIRECTION::MAX);
		std::cout << randomPosition.x << std::endl;
		std::cout << randomPosition.y << std::endl;
		std::cout << randomDirection << std::endl;
		std::cout << " ========================== " << std::endl;
			
	}

	std::cout << "end IS Empty Func (0 " << std::endl;
	pShip->SetDirection(randomDirection);

	for (int i = 0; i < pShip->GetHP(); i++)
	{
		pShip->AddPosition(randomPosition);
		if (pShip->GetDirection() == HORIZON)
		{
			randomPosition.x += 1;
		}
		else
		{
			randomPosition.y += 1;
		}
	}

}
