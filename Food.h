#pragma once
#include <iostream>
#include "Screen.h"
using namespace std;

class Food
{
private:
	Screen& screen;
	pair<int, int> food;

public:
	Food(Screen& screen);
	void generateFood();
	pair<int, int>& getFood();
};

