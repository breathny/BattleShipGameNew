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

	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			m_MyField[i][j].SetFiledType(HitResult::NONE);
		}
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

bool CPlayer::IsEmptyField(Position position, DIRECTION direction,int size)
{
	if ( (direction == HORIZON && ((position.x + size-1) >= ('A' +MAX_X)) ) 
		||( direction == VERTICAL && ((position.y + size-1) >= ('1'+ MAX_Y)) ))
		return false;
	

	for (auto pShip : m_ShipList)
	{
		if (pShip->HitCheck(position) != MISS)// 놓으려는 위치에 배가 있는지 체크
			return false;

		if (pShip->GetDirection() != direction) //방향이 같을때만 아랫줄로.
			continue;

		if (direction == HORIZON)
		{
			char tempX = position.x;
			for (int i = 0; i < pShip->GetHP(); i++)
			{
				if (pShip->HitCheck(Position(tempX, position.y)) != MISS)
					return false;
				tempX += 1;
			}
		}
		else
		{
			char tempY = position.y;
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

void CPlayer::ShowMyField()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			HitResult hitResult = m_MyField[y][x].GetFiledType();
			if (m_MyField[y][x].m_pShip != nullptr)
			{
				std::string printShipNames[5] = { "A","B","C","D","S" };
				std::cout << " 0(";
				std::cout << printShipNames[m_MyField[y][x].GetShipType()] << ") ";
			}
			else if (hitResult ==HitResult::NONE)
			{
				std::cout << " 0( ) ";
			}
			else if(hitResult == HitResult::HIT)
			{
				std::string printShipNames[5] = { "A","B","C","D","S" };
				std::cout << " H(";
				std::cout << printShipNames[m_MyField[y][x].GetShipType()] <<") ";
			}
			else if (hitResult == HitResult::DESTROYED)
			{
				std::string printShipNames[5] = { "A","B","C","D","S" };
				std::cout << " D(";
				std::cout << printShipNames[m_MyField[y][x].GetShipType()] << ") ";
			}
		}
		std::cout << std::endl;
	}
}

void CPlayer::PlaceRandomPostion(CShip* pShip)
{
	Position randomPosition;
	DIRECTION  randomDirection;

	randomPosition.x = 'A' + (rand() %((int)MAX_X));
	randomPosition.y = '1' + (rand() % ((int)MAX_Y));
	randomDirection = (DIRECTION)(rand() % (int)DIRECTION::MAX);

	std::cout << "[" << randomPosition.x << ", " << randomPosition.y << "] - ";
	std::cout << ((randomDirection == 0) ? "Vertical" : "Horizon" ) << std::endl;
	std::cout << ", HP:" << pShip->GetHP() << std::endl;
	std::cout << " ========================== [First]" << std::endl;

	////엠티인지 체크 
	while (IsEmptyField(randomPosition, randomDirection,pShip->GetHP()) == false)
	{
		randomPosition.x = 'A' + (rand() % ((int)MAX_X));
		randomPosition.y = '1' + (rand() % ((int)MAX_Y));
		randomDirection = (DIRECTION)(rand() % (int)DIRECTION::MAX);

		std::cout << "[" << randomPosition.x << ", " << randomPosition.y << "] - ";
		std::cout << ((randomDirection == 0) ? "Vertical" : "Horizon") << std::endl;
		std::cout << ", HP:" << pShip->GetHP() << std::endl;
		std::cout << " ========================== [Retry]" << std::endl;
			
	}

	std::cout << "end IS Empty Func (0 " << std::endl;
	pShip->SetDirection(randomDirection);

	for (int i = 0; i < pShip->GetHP(); i++)
	{
		pShip->AddPosition(randomPosition);
		//맵에도 표시해주기
		int x = randomPosition.x - 'A';
		int y = randomPosition.y - '1';


		m_MyField[y][x].m_pShip = pShip;
		
		if (pShip->GetDirection() == HORIZON)
			randomPosition.x += 1;
		else
			randomPosition.y += 1;
	}
}



