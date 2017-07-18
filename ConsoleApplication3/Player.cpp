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
		rangeOutCheck += DIR_VEC[randDirection] * (pShip->GetHP()-1);
		
		if (  rangeOutCheck.x > 'H'
			||rangeOutCheck.x < 'A'
			||rangeOutCheck.y > '8'
			||rangeOutCheck.y < '1')	//맵 크기를 넘어 가면 
		{
			randDirection = (++randDirection) % DIR_NONE_MAX;
			isCanPlaceShip = false;
			if (i == (DIR_NONE_MAX - 1))
			{
				PlaceRandomPostion(pShip);
				
				break;
			}

			
			std::cout << "맵크기 넘어감 "<< std::endl;

		}
		std::cout << "x " << randX << " y " << randY << " dir " << randDirection << " hp " << pShip->GetHP() << std::endl;
	
		for (int j = 0; j < pShip->GetHP(); j++)
		{
			if (isCanPlaceShip == false)
				break;

			Position tempPos(randX, randY);
			tempPos += DIR_VEC[randDirection] * j;
	
			//std::cout << "> tempPos(" << tempPos.x << ", " << tempPos.y << ")" << std::endl;
	
			if (m_MyField.IsEmpty(Position( tempPos.x - 'A',tempPos.y - '1')) == false)
			{
				randDirection = (++randDirection) % DIR_NONE_MAX;
				isCanPlaceShip = false;
				break;
			}
		}
	
		if (i == (DIR_NONE_MAX - 1) && isCanPlaceShip == false)
		{
			PlaceRandomPostion(pShip);
			break;
		}
	}

	//배치
	for (int i = 0; i < pShip->GetHP(); i++)
	{
		Position tempPos(randX, randY);
		tempPos += DIR_VEC[randDirection] * i;

		m_MyField.SetTile(Position( tempPos.x - 'A',tempPos.y - '1'), FIELD_EXIST, pShip->GetType());
		pShip->AddPosition(tempPos);
	}
	ShowMyField();
}

void CPlayer::ShowMyField()
{
	std::cout << "[m_MyField]" << std::endl;
	std::string printShipNames[6] = { "A","B","C","D","S"," " };

	for (int y = 0; y < MAX_Y; y++)
	{
		std::cout << (char)('1'+y) << " | ";
		for (int x = 0; x < MAX_X; x++)
		{
			EFieldType fieldType = m_MyField.GetFieldType(Position(x, y));

			if (m_MyField.GetFieldType(Position(x,y)) != SHIPTYPE_NONE_MAX)
			{
				std::cout << "0(" << printShipNames[m_MyField.GetShipType(Position(x, y))] << ") ";
			}
			else if (fieldType == FIELD_NONE_MAX)
			{
				std::cout << "0( ) ";
			}
			else if (fieldType == FIELD_HIT)
			{
				std::cout << "H(" << printShipNames[m_MyField.GetShipType(Position(x,y))] << ") ";
			}
			else if (fieldType == FIELD_DESTROY)
			{
				std::cout << "D(" << printShipNames[m_MyField.GetShipType(Position(x,y))] << ") ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "    [A ] [B ] [C ] [D ] [E ] [ F] [ G] [ H]" << std::endl;
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



