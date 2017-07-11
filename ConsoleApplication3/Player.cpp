#include "Player.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarines.h"
#include "Destroyer.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{	
	for (auto vec : pShipList)
	{
		delete vec;

	}
	pShipList.clear();
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
		pShipList.push_back(aircraft);
		//shipList.push_back(aircraft);

	}
		break;
	case BATTLESHIP:
	{
		CBattleship* battleShip = new CBattleship();
		pShipList.push_back(battleShip);

	}
		break;
	case CRUISER:
	{
		CCruiser* cruiser = new CCruiser();
		pShipList.push_back(cruiser);

	}
		break;
	case DESTROYER:
	{
		CDestroyer *destroyer= new CDestroyer();
		pShipList.push_back(destroyer);
	}
		
		break;
	case SUBMARINE:
	{
		CSubmarines* submarines = new CSubmarines();
		pShipList.push_back(submarines);
	}
		
		break;
	
	}
	
}

void CPlayer::PrintShip()
{
	for (int i = 0; i < (int)pShipList.size(); i++)
	{
		(*pShipList[i]).PrintTest();


	}

}
