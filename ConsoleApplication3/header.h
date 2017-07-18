#pragma once

#define MAX_X 8
#define MAX_Y 8

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

	Position(int x, int y)
	{
		this->x = (char)x;
		this->y = (char)y;
	}

	Position operator+(Position pos)
	{
		Position temp = pos;
		temp.x += x;
		temp.y += y;
		return temp;
	}

	Position operator+=(Position pos)
	{
		x += pos.x;
		y += pos.y;
		return *this;
	}

	Position operator*(int num)
	{
		Position pos = *this;
		pos.x *= (char)num;
		pos.y *= (char)num;
		return pos;
	}
	
	char x;
	char y;
};

enum EHitResult
{
	NONE,
	HIT,
	MISS,
	DESTROYED,
	DESTROY_AIRCRAFT,
	DESTROY_BATTLESHIP,
	DESTROY_CRUISER,
	DESTROY_DESTROYER,
	DESTROY_SUBMARINE,
};

enum EShipType
{
	AIRCRAFT,
	BATTLESHIP,
	CRUISER,
	DESTROYER,
	SUBMARINE,
	SHIPTYPE_NONE_MAX,
};

enum EDirection
{
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN,
	DIR_NONE_MAX
};

static Position DIR_VEC[] = { Position(-1,0),Position(1,0),Position(0,-1),Position(0,1) };
