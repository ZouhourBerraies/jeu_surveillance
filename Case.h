#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Case
{
	int x, y;
public:
	Case() { x = 0; y = 0; }
	Case(int a, int b) :x(a), y(b)
	{}
	~Case() {}
	void operator=(Case& c)
	{
		x = c.x;
		y = c.y;
	}
	bool operator==(const Case& c)
	{
		return (x == c.x && y == c.y);
	}

	friend bool adjacente(Case a, Case b)
	{
		return (a.x == b.x + 1 || a.x == b.x - 1 || a.y == b.y + 1 || a.y == b.y - 1);
	}
	int getx() const
	{
		return x;
	}
	int gety() const
	{
		return y;
	}
	void setx(int a)
	{
		x = a;
	}
	void sety(int a)
	{
		y = a;
	}
};

