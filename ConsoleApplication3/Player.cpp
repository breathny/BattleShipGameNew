#include "stdafx.h"
#include "Player.h"

#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarines.h"
#include "Destroyer.h"

CPlayer::CPlayer()
{
	AddShip(AIRCRAFT);
	AddShip(BATTLESHIP);
	AddShip(CRUISER);
	AddShip(DESTROYER);
	AddShip(DESTROYER);
	//AddShip(SUBMARINE);
	//AddShip(SUBMARINE);
}

CPlayer::~CPlayer()
{	
	for (auto pShip : m_pShipList)
	{
		if(pShip != NULL) delete pShip;
	}
	m_pShipList.clear();
}

void CPlayer::AddShip(EShipType type)
{
	switch(type)
	{
	case AIRCRAFT:
		{
			CAirCraft* aircraft = new CAirCraft();
			m_pShipList.push_back(aircraft);
		}
		break;
	case BATTLESHIP:
		{
			CBattleship* battleShip = new CBattleship();
			m_pShipList.push_back(battleShip);
		}
		break;
	case CRUISER:
		{
			CCruiser* cruiser = new CCruiser();
			m_pShipList.push_back(cruiser);
		}
		break;
	case DESTROYER:
		{
			CDestroyer *destroyer= new CDestroyer();
			m_pShipList.push_back(destroyer);
		}
		break;
	case SUBMARINE:
		{
			CSubmarines* submarines = new CSubmarines();
			m_pShipList.push_back(submarines);
		}
		break;
	}
}

void CPlayer::PlaceRandomPostion(CShip* pShip)
{
	char randX = rand() % MAX_X;
	char randY = rand() % MAX_Y;

	int randDirection = rand() % DIR_NONE_MAX;
	bool isCanPlace = true;

	for (int i = 0; i < DIR_NONE_MAX; i++)
	{
		//std::cout << "[" << randX << ", " << randY << "]" << std::endl;
		for (int j = 0; j < pShip->GetHP(); j++)
		{
			Position tempPos(randX, randY);
			tempPos += DIR_VEC[randDirection] * j;

			if (m_MyField.IsEmpty(Position( tempPos.x,tempPos.y)) == false)
			{
				randDirection = ++randDirection % DIR_NONE_MAX;
				isCanPlace = false;
				break;
			}
		}
		if (i == DIR_NONE_MAX - 1 && !isCanPlace)
		{
			PlaceRandomPostion(pShip);
			return;
		}

	}

	//배치
	for (int i = 0; i < pShip->GetHP(); i++)
	{
		Position tempPos(randX, randY);
		tempPos += DIR_VEC[randDirection] * i;

		m_MyField.SetTile(Position( tempPos.x,tempPos.y), NONE, pShip->GetType());
		pShip->AddPosition(tempPos);
	}
}

void CPlayer::ShowAllField()
{
	CField& showField = m_AttackHistoryField;

	std::cout << "-------------------------------------------" << std::endl;
	std::string printShipNames[] = { " ", "O", "-", "*", "A", "B", "C", "D", "S" };

	for (int x = 0; x < MAX_X; x++)
	{
		std::cout << (char)('A' + x) << " | ";
		for (int y = 0; y <MAX_Y; y++)
		{
			EHitResult hitResult = showField.GetFieldType(Position(x, y));

			if (showField.GetShipType(Position(x, y)) != SHIPTYPE_NONE_MAX)
			{
				std::cout << "0 (" << printShipNames[showField.GetFieldType(Position(x, y))] << ") ";
			}
			else if (hitResult == NONE)
			{
				std::cout << "0 ( ) ";
			}
			else if (hitResult == MISS)
			{
				std::cout << "M (" << printShipNames[showField.GetFieldType(Position(x, y))] << ") ";
			}
			else if (hitResult == HIT)
			{
				std::cout << "H (" << printShipNames[showField.GetFieldType(Position(x, y))] << ") ";
			}
			else if (hitResult > DESTROYED)
			{
				std::cout << "D (" << printShipNames[showField.GetFieldType(Position(x, y))] << ") ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "    [1 ] [2 ] [3 ] [4 ] [5 ] [ 6] [ 7] [ 8]" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	showField = m_MyField;
	std::string printShipNames2[] = {"A", "B", "C", "D", "S", " "};
	std::cout << "-------------------------------------------" << std::endl;

	for (int x = 0; x < MAX_X; x++)
	{
		std::cout << (char)('A' + x) << " | ";
		for (int y = 0; y <MAX_Y; y++)
		{
			EHitResult hitResult = showField.GetFieldType(Position(x, y));

			if (showField.GetShipType(Position(x, y)) != SHIPTYPE_NONE_MAX)
			{
				std::cout << "0 (" << printShipNames2[showField.GetShipType(Position(x, y))] << ") ";
			}
			else if (hitResult == NONE)
			{
				std::cout << "0 ( ) ";
			}
			else if (hitResult == MISS)
			{
				std::cout << "M (" << printShipNames2[showField.GetShipType(Position(x, y))] << ") ";
			}
			else if (hitResult == HIT)
			{
				std::cout << "H (" << printShipNames2[showField.GetShipType(Position(x, y))] << ") ";
			}
			else if (hitResult > DESTROYED)
			{
				std::cout << "D (" << printShipNames2[showField.GetShipType(Position(x, y))] << ") ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "    [1 ] [2 ] [3 ] [4 ] [5 ] [ 6] [ 7] [ 8]" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void CPlayer::PrintShip()
{
	//for (auto pShip : m_pShipList)
	{
		//pShip->PrintTest();
		//pShip->HitCheck();
	}
}

void CPlayer::ShipDeployTest()
{
	for (auto pShip : m_pShipList)
	{
		PlaceRandomPostion(pShip);
		std::cout << "[" << pShip->GetName() << "] - " << pShip->GetHP() << std::endl;
		pShip->PrintPosition();		// 현재 가진 각 배의 좌표 출력
	}
}

Position CPlayer::GetAttackPosition()
{
	char x = 0;
	char y = 0;

	do
	{
		x = rand() % MAX_X;
		y = rand() % MAX_Y;
	} while (GetFieldAttackLog(Position(x,y)) != NONE);
	
	
	return Position(x, y);
}

EHitResult CPlayer::HitCheck(Position pos)
{
	EHitResult tempResult = MISS;
	for (auto pShip : m_pShipList)
	{
		tempResult = pShip->HitCheck(pos);
		if (tempResult != MISS)
			break;

	}
	return tempResult;
}

// 게임 매니저 턴 진행 확인 여부용
bool CPlayer::IsShipAlive()
{
	for (auto pShip : m_pShipList)
	{
		if (pShip->GetHP() != 0)
			return true;
	}
	return false;
}

void CPlayer::DeployShip()
{
	for (auto pShip : m_pShipList)
	{
		PlaceRandomPostion(pShip);
	}
}

void CPlayer::AddAttackHistory(Position position, EHitResult hitResult)
{
	m_AttackHistoryField.SetAttackLog(position, hitResult);
}

EHitResult CPlayer::GetFieldAttackLog(Position pos)
{
	return m_AttackHistoryField.GetFieldType(pos);
}



