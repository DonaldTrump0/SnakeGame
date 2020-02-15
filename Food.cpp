#include "Food.h"

Food::Food(Screen& screen):screen(screen)
{
}

void Food::generateFood()
{
	int n = screen.getSize();
	do
	{
		food = pair<int, int>((rand() % n + 1) * 2, rand() % n + 1);
	} while (screen.get(food));
	screen.set(food, true);
	screen.gotoxy(food.first, food.second);
	cout << "бя";
}

pair<int, int>& Food::getFood()
{
	return this->food;
}
