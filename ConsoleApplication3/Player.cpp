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

	//��ġ
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
	
	std::cout << "-------------------------------------------" << std::endl;
	std::string printShipNames[] = { " ", "O", "-", "*", "A", "B", "C", "D", "S" };

	for (int x = 0; x < MAX_X; x++)
	{
		std::cout << (char)('A' + x) << " | ";
		for (int y = 0; y <MAX_Y; y++)
		{
			EHitResult hitResult = m_AttackHistoryField.GetFieldType(Position(x, y));

			if (m_AttackHistoryField.GetShipType(Position(x, y)) != SHIPTYPE_NONE_MAX)
			{
				std::cout << "0 (" << printShipNames[m_AttackHistoryField.GetFieldType(Position(x, y))] << ") ";
			}
			else if (hitResult == NONE)
			{
				std::cout << "0 ( ) ";
			}
			else if (hitResult == MISS)
			{
				std::cout << "M (" << printShipNames[m_AttackHistoryField.GetFieldType(Position(x, y))] << ") ";
			}
			else if (hitResult == HIT)
			{
				std::cout << "H (" << printShipNames[m_AttackHistoryField.GetFieldType(Position(x, y))] << ") ";
			}
			else if (hitResult > DESTROYED)
			{
				std::cout << "D (" << printShipNames[m_AttackHistoryField.GetFieldType(Position(x, y))] << ") ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "    [1 ] [2 ] [3 ] [4 ] [5 ] [ 6] [ 7] [ 8]" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	std::string printShipNames2[] = {"A", "B", "C", "D", "S", " "};
	std::cout << "-------------------------------------------" << std::endl;

	for (int x = 0; x < MAX_X; x++)
	{
		std::cout << (char)('A' + x) << " | ";
		for (int y = 0; y <MAX_Y; y++)
		{
			EHitResult hitResult = m_MyField.GetFieldType(Position(x, y));

			if (m_MyField.GetShipType(Position(x, y)) != SHIPTYPE_NONE_MAX)
			{
				std::cout << "0 (" << printShipNames2[m_MyField.GetShipType(Position(x, y))] << ") ";
			}
			else if (hitResult == NONE)
			{
				std::cout << "0 ( ) ";
			}
			else if (hitResult == MISS)
			{
				std::cout << "M (" << printShipNames2[m_MyField.GetShipType(Position(x, y))] << ") ";
			}
			else if (hitResult == HIT)
			{
				std::cout << "H (" << printShipNames2[m_MyField.GetShipType(Position(x, y))] << ") ";
			}
			else if (hitResult > DESTROYED)
			{
				std::cout << "D (" << printShipNames2[m_MyField.GetShipType(Position(x, y))] << ") ";
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
		pShip->PrintPosition();		// ���� ���� �� ���� ��ǥ ���
	}
}

Position CPlayer::GetAttackPosition()
{
	char returnX = 0;
	char returnY = 0;

	

	//�� ���°� SEEK ���¸� �������� returnPosition ��ȯ , ���� ���� �����Ѵٸ� ���¸�FIRST_HIT ������ firstPostion ���� 
	
	//FIRSTHIT ���¸� firstPosition ����  chaseSeekDirection �� ������  returnPosition ��ȯ ��chaseSeekDirection�������� ��� ������ CHSE�� ���� �ȸ����� CHASESEEK���� ���椷 
	
	  

	//ChaseSEEK ++chaseSeekDirection�� ���ذ��� firstPosition�� ����t . //chaseDirectionFrontState �� true .���� ���ü����Ѵٸ� CHASE_SEEK���·� ���� 
	   
	//CHASE ���¶�� chaseSeekDirectio ���� ��ӽ��ش� .���� ����ǥ�� NONE�̶�� firstPosition�� chaseSeekDirection �ݴ�������� �ٲٰ� chaseDirectionFrontState �� false �� ���� chaseSeek���·� ���ư���. 
	// 


	//seek ���� ->  Hitüũ�� �������� ���� 4������ ���̻� üũ �� �κ��� ���� ��
	//chase ���� -> ã���������� �Ѿư��� ����
	//chase_seek ���� ->���� ���� ���� ã�� ���� 



	//-------------------------------------------------------------------

	////do
	////{
	////	returnX = rand() % MAX_X;
	////	returnY = rand() % MAX_Y;
	////} while (GetFieldAttackLog(Position(returnX,returnY)) != NONE);
	////
	////

	//Position returnPosition;
	//int maxCount =0;
	//for (int y = 0; y < MAX_Y; y++)
	//{
	//	for (int x = 0; x < MAX_X; x++)
	//	{
	//		int randDir = rand() % 2; //0�̳� 1�̳��� 
	//		randDir *= 2; // 0 �̳� 2������ �ᱸ ���γ� ���ΰ� ���´�. 

	//		Position tempPosition(x, y); //�˻��� �ӽ� ��ǥ
	//		bool isMovePlus = true;
	//		bool isMoveMinus = true;
	//		int checkCount = 0;
	//		//�翷���� �����̶� �̵������ϸ� ����(j)�� Ȯ����Ѱ���.
	//		for (int j = 0; isMoveMinus != false || isMovePlus != false ; j++)
	//		{	
	//			
	//			//�翷 ������ üũ�ϸ鼭 
	//			if (isMovePlus == true GetFieldAttackLog(tempPosition + DIR_VEC[randDir] * j)== NONE)
	//			{
	//				isMovePlus = false;
	//			}
	//			else if(isMoveMinus == true && GetFieldAttackLog(tempPosition + DIR_VEC[randDir] * (j+1)) == NONE)
	//			{
	//				isMoveMinus == false;\
	//			}
	//			

	//		}

	//	}


	//}

		
	//-------------------------------------------------------------------
	
	return Position(returnX,returnY);
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

// ���� �Ŵ��� �� ���� Ȯ�� ���ο�
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



