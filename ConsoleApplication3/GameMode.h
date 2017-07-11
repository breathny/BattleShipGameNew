#pragma once
#include <vector>

#define MAXSHIP 5

class GameMode
{
public:
	GameMode();
	~GameMode();
};

struct Position
{
	Position()
	{
		x = 0;
		y = 0;
	}

	Position(char x, char y)
	{
		this->x = x;
		this->y = y;
	}
	char x;
	char y;
};

enum HitResult
{
	HIT,
	MISS,
	DESTROYED
};

enum ShipType
{
	AIRCRAFT,
	BATTLESHIP,
	CRUISER,
	DESTROYER,
	SUBMARINE
};

