#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class Screen
{
private:
	// ��Ļ���ο򳤶�
	int n;
	// ��ʾ��Ļռ������Ķ�ά����
	vector<vector<bool>> screenArray;
	// ��ʾ�����
	HANDLE hOut;

public:
	Screen();
	Screen(int n);

	// �������
	void hiddenCursor();
	// ���ù������
	void gotoxy(int x, int y);

	void initScreen();
	int getSize();
	void set(pair<int, int> coord, bool flag);
	bool get(pair<int, int> coord);
};

