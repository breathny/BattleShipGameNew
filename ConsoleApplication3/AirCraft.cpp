#include"stdafx.h"
#include "AirCraft.h"

CAirCraft::CAirCraft()
{
	m_Name = "Aircraft";
	m_Type = AIRCRAFT;
	m_HP = 5;
}


CAirCraft::~CAirCraft()
{
}

void CAirCraft::PrintTest()
{
	printf("AirCraft\n");
}
