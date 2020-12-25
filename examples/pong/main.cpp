﻿// Copyright 2020 SMS
// License(Apache-2.0)
// 乒乓球

#include <time.h>
#include <clem/clem.hpp>
#include <iostream>
#include <stdio.h>

#ifdef OS_WIN
#include <windows.h>
#define sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep(ms) usleep(ms * 1000)
#endif

using namespace std;

int main()
{
#ifdef OS_WIN
	// 开启 VT100模式
	DWORD mode;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | 4);
#endif

	auto director = Director::getInstance();
	auto size     = director->getWinSize();

	Texture texture(size);
	Color   green(Fore::green);
	texture.drawCycle(Point(size.x / 2, size.y / 2), 5, Tile('.', green));
	
	Factor factor(texture);
	
	Scene scene;
	scene.addFactor(&factor);

	director->pushScene(&scene);
	director->run();

	getchar();
	getchar();
}
