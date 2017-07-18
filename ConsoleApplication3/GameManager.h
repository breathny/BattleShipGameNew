#pragma once

#include "Player.h"

class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	void Init();
	void Start();


protected:
	CPlayer m_Attacker;
	CPlayer m_Defender;
};

