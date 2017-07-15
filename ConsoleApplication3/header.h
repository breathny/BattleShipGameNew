#pragma once

#define MAX_X 5
#define MAX_Y 5

enum DIRECTION
{
	VERTICAL,
	HORIZON,
	MAX
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
	NONE,
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
	SUBMARINE,

};

