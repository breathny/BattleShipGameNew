#include<iostream>
#include "Ship.h"
#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarines.h"
#include "Destroyer.h"
#include "Player.h"
void main()
{

	CAirCraft aircraft;
	CBattleship battleship;
	CCruiser crusier;
	CDestroyer destroyer;
	CSubmarines submarines;

	//std::cout << aircraft.GetName().c_str() << "HP is" << aircraft.GetHP() << std::endl;
	//std::cout << battleship.GetName().c_str() << "HP is" << battleship.GetHP() << std::endl;
	//std::cout << crusier.GetName().c_str() << "HP is" << crusier.GetHP() << std::endl;
	//std::cout << destroyer.GetName().c_str() << "HP is" << destroyer.GetHP() << std::endl;
	//std::cout << submarines.GetName().c_str() << "HP is" << submarines.GetHP() << std::endl;

	printf("%s is HP : %d Type : %d\n", aircraft.GetName().c_str(), aircraft.GetHP(), aircraft.GetType());
	printf("%s is HP : %d Type : %d\n", battleship.GetName().c_str(), battleship.GetHP(), battleship.GetType());
	printf("%s is HP : %d Type : %d\n", crusier.GetName().c_str(), crusier.GetHP(), crusier.GetType());
	printf("%s is HP : %d Type : %d\n", destroyer.GetName().c_str(), destroyer.GetHP(), destroyer.GetType());
	printf("%s is HP : %d Type : %d\n", submarines.GetName().c_str(), submarines.GetHP(), submarines.GetType());

	aircraft.AddPosition(Position('A', '5'));
	aircraft.AddPosition(Position('B', '5'));
	aircraft.AddPosition(Position('C', '5'));
	aircraft.AddPosition(Position('D', '5'));
	aircraft.AddPosition(Position('E', '5'));
	aircraft.PrintPosition();
	battleship.PrintPosition();

	Position pos[3];
	pos[0].x = 'A';
	pos[0].y = '5';
	pos[1].x = 'B';
	pos[1].y = '5';
	pos[2].x = 'D';
	pos[2].y = '3';

	HitResult hitResult;
	std::string hitString[3] = { "HIT","MISS","DESTROY" };
	for (int i = 0; i < 3; i++)
	{
		hitResult = aircraft.HitCheck(pos[i]);
		printf("%c%c  - %s\n", pos[i].x, pos[i].y, hitString[(int)hitResult].c_str());
	}


	CPlayer player;
	player.AddShip(AIRCRAFT);
	player.AddShip(BATTLESHIP);
	player.AddShip(BATTLESHIP);
	player.AddShip(BATTLESHIP);
	player.AddShip(DESTROYER);

	player.PrintShip();


	getchar(); 
}