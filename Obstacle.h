#pragma once
#include"Case.h"
class Obstacle
{
	Case cobs;
	
public:
	Obstacle(Case c):cobs ( c)
	{}
	~Obstacle() {  }
	Case getcobs()
	{
		return cobs;
	}
	
};
