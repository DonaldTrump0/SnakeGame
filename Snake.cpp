#include "Snake.h"

Snake::Snake(Screen& screen, Food& food):screen(screen), food(food)
{
}

void Snake::init()
{
	screen.set(pair<int, int>(2, 1), true);
	screen.set(pair<int, int>(4, 1), true);
	screen.set(pair<int, int>(6, 1), true);

	snake.push_front(pair<int, int>(2, 1));
	snake.push_front(pair<int, int>(4, 1));
	snake.push_front(pair<int, int>(6, 1));

	screen.gotoxy(2, 1);
	cout << "¡ñ¡ñ¡Ñ";
}

bool Snake::move(char c)
{
	pair<int, int> head = snake.front();
	pair<int, int> tail = snake.back();
	pair<int, int> newHead;
	switch (c)
	{
	case UP:
		newHead = pair<int, int>(head.first, head.second - 1);
		break;
	case DOWN:
		newHead = pair<int, int>(head.first, head.second + 1);
		break;
	case LEFT:
		newHead = pair<int, int>(head.first - 2, head.second);
		break;
	case RIGHT:
		newHead = pair<int, int>(head.first + 2, head.second);
		break;
	default:
		return false;
	}

	int n = screen.getSize();
	if (newHead.first < 2 || newHead.first >= (n * 2 + 1) || newHead.second < 1 || newHead.second > n
		|| (screen.get(newHead) && newHead != tail && newHead != food.getFood())) {
		// ÓÎÏ·½áÊø
		return false;
	}

	if (newHead == food.getFood())
	{
		food.generateFood();
	}
	else
	{
		screen.set(tail, false);
		snake.pop_back();
		screen.gotoxy(tail.first, tail.second);
		cout << "  ";
	}
	screen.set(newHead, true);
	snake.push_front(newHead);
	screen.gotoxy(newHead.first, newHead.second);
	cout << "¡Ñ";
	screen.gotoxy(head.first, head.second);
	cout << "¡ñ";

	return true;
}
