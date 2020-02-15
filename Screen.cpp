#include "Screen.h"

Screen::Screen()
{
	this->hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	this->n = 20;
	int x = this->n * 2 + 4;
	int y = this->n + 2;

	screenArray.resize(x);
	for (int i = 0; i < x; i++)
	{
		screenArray[i].resize(y);
	}
}

Screen::Screen(int n)
{
	this->hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	this->n = n;
	int x = n * 2 + 4;
	int y = n + 2;

	screenArray.resize(x);
	for (int i = 0; i < x; i++)
	{
		screenArray[i].resize(y);
	}
}

void Screen::hiddenCursor()
{
	CONSOLE_CURSOR_INFO hidden;
	GetConsoleCursorInfo(hOut, &hidden);
	hidden.bVisible = 0;
	SetConsoleCursorInfo(hOut, &hidden);
}

void Screen::gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void Screen::initScreen()
{
	// 上横线
	gotoxy(2, 0);
	for (int i = 0; i < n; i++) {
		cout << "▁";
	}
	// 左竖线
	gotoxy(0, 1);
	for (int i = 0; i < n; i++) {
		cout << "▕" << endl;
	}
	// 下横线
	gotoxy(2, n + 1);
	for (int i = 0; i < n; i++) {
		cout << "▔";
	}
	// 右竖线
	for (int i = 1; i <= n; i++) {
		gotoxy(n * 2 + 2, i);
		cout << "▏";
	}
}

int Screen::getSize()
{
	return this->n;
}

void Screen::set(pair<int, int> coord, bool flag)
{
	screenArray[coord.first][coord.second] = flag;
}

bool Screen::get(pair<int, int> coord)
{
	return screenArray[coord.first][coord.second];
}