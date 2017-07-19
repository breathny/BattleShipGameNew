#include "stdafx.h"
#include "GameManager.h"
#include <Windows.h> //  출력 테스트용 시간 딜레이


CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	
}

void CGameManager::Start()
{
	

	m_Defender.DeployShip();
	int turnCnt = 1;
	while (m_Defender.IsShipAlive())
	{
		Position pos = m_Attacker.GetAttackPosition();
		EHitResult result = m_Defender.HitCheck(pos);
		m_Attacker.AddAttackHistory(pos, result);
		
		std::string resultStr[] = {
			"None",
			"HIT",
			"MISS",
			"DESTROYED",
			"DESTROY_AIRCRAFT",
			"DESTROY_BATTLESHIP",
			"DESTROY_CRUISER",
			"DESTROY_DESTROYER",
			"DESTROY_SUBMARINE"
		};

		printf_s( "[ %d ] \t  ATTACK Position :[ %c, %c ] Result : %s \n ", turnCnt, pos.x + 'A', pos.y+'1', resultStr[(int)result].c_str());
		
		turnCnt++;
	}

	m_Defender.ShowAllField();

	printf_s(" Game Over! Turn Count : %d", turnCnt);
}

