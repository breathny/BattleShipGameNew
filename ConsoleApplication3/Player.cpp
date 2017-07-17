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
	//AddShip(DESTROYER);
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

//bool CPlayer::IsEmptyField(Position position, Position direction, int size)
//{
//	//Position tempPos = position;
//	/*for (auto pShip : m_pShipList)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (m_MyField[tempPos.y][tempPos.x].)
//				return false;
//			tempPos += direction;
//		}
//	}*/
//	return true;
//}

void CPlayer::PlaceRandomPostion(CShip* pShip)
{
	char randX = 'A' + rand() % MAX_X;
	char randY = '1' + rand() % MAX_Y;

	int randDirection = rand() % DIR_NONE_MAX;

	for (int i = 0; i < DIR_NONE_MAX; i++)
	{
		bool isCanPlaceShip = true;
		Position rangeOutCheck(randX, randY);
		rangeOutCheck += DIR_VEC[randDirection] * pShip->GetHP();
		
		if (  rangeOutCheck.x > 'H'
			||rangeOutCheck.x < 'A'
			||rangeOutCheck.y > '8'
			||rangeOutCheck.y < '1')	//맵 크기를 넘어 가면 
		{
			randDirection = (++randDirection) % DIR_NONE_MAX;
			continue;
		}
	
		for (int j = 1; j <= pShip->GetHP(); j++)
		{
			Position tempPos(randX, randY);
			tempPos += DIR_VEC[randDirection] * j;
	
			//std::cout << "> tempPos(" << tempPos.x << ", " << tempPos.y << ")" << std::endl;
	
			if (m_MyField.IsEmpty(Position(tempPos.y - '1', tempPos.x - 'A')) == false)
			{
				randDirection = (++randDirection) % DIR_NONE_MAX;
				isCanPlaceShip = false;
				break;
			}
		}
	
		if (isCanPlaceShip) 
			break;
	
		if (i == (DIR_NONE_MAX - 1) && isCanPlaceShip == false)
		{
			PlaceRandomPostion(pShip);
			return;
		}
	}

	//배치
	for (int i = 1; i <= pShip->GetHP(); i++)
	{
		Position tempPos(randX, randY);
		tempPos += DIR_VEC[randDirection] * i;

		m_MyField.SetTile(Position(tempPos.y - '1', tempPos.x - 'A'), FIELD_EXIST, pShip->GetType());
		pShip->AddPosition(tempPos);
	}
}

void CPlayer::ShowMyField()
{
	std::cout << "[m_MyField]" << std::endl;
	std::string printShipNames[6] = { "A","B","C","D","S"," " };

	for (int x = 0; x < MAX_X; x++)
	{
		std::cout << (char)('H'-x) << " | ";
		for (int y = 0; y < MAX_Y; y++)
		{
			EFieldType fieldType = m_MyField.GetFieldType(Position(y, x));

			if (m_MyField.GetFieldType(Position(y, MAX_Y - x - 1)) != SHIPTYPE_NONE_MAX)
			{
				std::cout << "0(" << printShipNames[m_MyField.GetShipType(Position(y, MAX_Y - x - 1))] << ") ";
			}
			else if (fieldType == FIELD_NONE_MAX)
			{
				std::cout << "0( ) ";
			}
			else if (fieldType == FIELD_HIT)
			{
				std::cout << "H(" << printShipNames[m_MyField.GetShipType(Position(y, MAX_Y - x - 1))] << ") ";
			}
			else if (fieldType == FIELD_DESTROY)
			{
				std::cout << "D(" << printShipNames[m_MyField.GetShipType(Position(y, MAX_Y - x - 1))] << ") ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "    [ 1] [ 2] [ 3] [ 4] [ 5] [ 6] [ 7] [ 8]" << std::endl;
}

void CPlayer::PrintShip()
{
	for (auto pShip : m_pShipList)
	{
		pShip->PrintTest();
	}
}

void CPlayer::ShipDeployTest()
{
	for (auto pShip : m_pShipList)
	{
		PlaceRandomPostion(pShip);
		pShip->PrintPosition();		// 현재 가진 각 배의 좌표 출력
	}
}



