#pragma once
#include <iostream>
#include <list>
#include "Screen.h"
#include "Food.h"
using namespace std;

enum Direct
{
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd'
};

class Snake
{
private:
	Screen& screen;
	Food& food;
	list<pair<int, int>> snake;

public:
	Snake(Screen& screen, Food& food);
	void init();
	bool move(char c);
};