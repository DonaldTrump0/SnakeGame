#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class Screen
{
private:
	// 屏幕矩形框长度
	int n;
	// 表示屏幕占用情况的二维数组
	vector<vector<bool>> screenArray;
	// 显示器句柄
	HANDLE hOut;

public:
	Screen();
	Screen(int n);

	// 光标隐藏
	void hiddenCursor();
	// 设置光标坐标
	void gotoxy(int x, int y);

	void initScreen();
	int getSize();
	void set(pair<int, int> coord, bool flag);
	bool get(pair<int, int> coord);
};

