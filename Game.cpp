#include <iostream>
#include <ctime>
#include <conio.h>
#include "Screen.h"
#include "Snake.h"
#include "Food.h"
using namespace std;

// ���ο򳤶�
const int n = 20;
// ���ƶ��ٶ�
const int sleepTime = 200;

void playGame()
{
	srand(time(NULL));

	Screen screen(n);
	Food food(screen);
	Snake snake(screen, food);
	screen.hiddenCursor();
	screen.initScreen();
	snake.init();
	food.generateFood();

	bool isAlive = true;
	char curC = 0;
	char lastC = RIGHT;
	while (true)
	{
		// ��ʼʱ��ֹ����
		curC = _getch();
		// ��ֹ�����ӳ�
		while (_kbhit())
		{
			curC = _getch();
		}

		// ���˱�ļ�
		if (curC != UP && curC != DOWN && curC != LEFT && curC != RIGHT)
		{
			curC = lastC;
		}
		do
		{
			if ((lastC == UP && curC == DOWN)
				|| (lastC == DOWN && curC == UP)
				|| (lastC == LEFT && curC == RIGHT)
				|| (lastC == RIGHT && curC == LEFT))
			{
				curC = lastC;
			}
			isAlive = snake.move(curC);
			lastC = curC;
			Sleep(sleepTime);
		} while (!_kbhit() && isAlive);

		if (!isAlive)
		{
			screen.gotoxy(0, n + 2);
			cout << "  Game Over!" << endl;
			cout << "  Press \"Enter\" To Play Again" << endl;
			char c;
			do
			{
				c = _getch();
			} while (c != '\r');
			system("cls");
			return;
		}
	}
}

void autoPlay()
{

}

int main()
{
	while (true)
	{
		playGame();
	}
	return 0;
}