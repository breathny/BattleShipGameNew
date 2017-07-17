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
	AddShip(SUBMARINE);
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

	int dir = rand() % DIR_NONE_MAX;
	
	for (int i = 0; i < DIR_NONE_MAX; i++)
	{
		bool isCanPlaceShip = true;
		Position rangeCheck(randX, randY);
		rangeCheck += DIR_VEC[dir] * (pShip->GetHP()-1);
		
		if( rangeCheck.x > MAX_X + 'A' 
			||rangeCheck.x < 'A'
			||rangeCheck.y > MAX_Y + '1'
			||rangeCheck.y < '1')//맵 크기를 넘어 가면 
		{
			dir = ++dir % DIR_NONE_MAX;
			isCanPlaceShip = false;
		}

		for (int j = 0; j < pShip->GetHP(); j++)
		{
			if (isCanPlaceShip == false) 
				break;

			Position tempPos((char)randX, (char)randY);
			tempPos += DIR_VEC[dir] * j;

			if (m_MyField.IsEmpty(Position(tempPos.y - '1',tempPos.x - 'A')) == false)
			{
				dir = ++dir % DIR_NONE_MAX;
				isCanPlaceShip = false;
				break;
			}
		}

		if (isCanPlaceShip) 
			break;

		if (i == (DIR_NONE_MAX - 1))
		{
			PlaceRandomPostion(pShip);
			break;
		}
		
		
	}

	//배치 
	for (int i = 0; i < pShip->GetHP(); i++)
	{
		Position tempPos(randX, randY);
		tempPos = tempPos + DIR_VEC[dir] * i;
		m_MyField.SetTile(Position(tempPos.y - '1', tempPos.x - 'A'), EXIST, pShip->GetType());
		pShip->AddPosition(tempPos);
	}
	ShowMyField();
}

void CPlayer::ShowMyField()
{
	std::cout << "[m_MyField]" << std::endl;
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			EFieldType fieldType = m_MyField.GetFieldType(Position(y,x));

			if (m_MyField.GetFieldType(Position(y, x)) != SHIPTYPE_NONE_MAX)
			{
				std::string printShipNames[5] = { "A","B","C","D","S" };
				std::cout << "0(";
				std::cout << printShipNames[m_MyField.GetShipType(Position(y, x))] << ") ";
			}
			else if (fieldType ==EHitResult::NONE)
			{
				std::cout << "0( ) ";
			}
			else if(fieldType == EHitResult::HIT)
			{
				std::string printShipNames[5] = { "A","B","C","D","S" };
				std::cout << "H(";
				std::cout << printShipNames[m_MyField.GetShipType(Position(y, x))] <<") ";
			}
			else if (fieldType == EHitResult::DESTROYED)
			{
				std::string printShipNames[5] = { "A","B","C","D","S" };
				std::cout << "D(";
				std::cout << printShipNames[m_MyField.GetShipType(Position(y, x))] << ") ";
			}
		}
		std::cout << std::endl;
	}
}

void CPlayer::PrintShip()
{
	for (int i = 0; i < (int)m_pShipList.size(); i++)
	{
		(*m_pShipList[i]).PrintTest();
	}
}

void CPlayer::ShipDeployTest()
{
	for (auto pShip : m_pShipList)
	{
		PlaceRandomPostion(pShip);
		pShip->PrintPosition();	// 현재 가진 각 배의 좌표 출력
	}
}



