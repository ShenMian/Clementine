// Copyright 2020 SMS
// License(Apache-2.0)

#include "director.h"
#include <cassert>
#include <chrono>
#include "scene.h"
#include "platform.h"

Director Director::instance;

Director* Director::getInstance()
{
	return &instance;
}

void Director::run()
{
	if(scenes.empty())
		assert(false);

	loop();
}

void Director::pause()
{
	if(paused)
		assert(false);

	paused = true;	
}

void Director::resume()
{
	if(!paused)
		assert(false);

	paused = false;
}

void Director::pushScene(Scene& s)
{
	scenes.push_back(&s);
}

void Director::popScene()
{
	if(scenes.empty())
		assert(false);

	scenes.pop_back();
}

void Director::replaceScene(Scene& s)
{
	if(scenes.empty())
		assert(false);

	scenes.front() = &s;
}

Scene* Director::getCurrentScene() const
{
	if(!scenes.empty())
		return scenes.back();
	else
		return nullptr;
}

void Director::setMsPerUpdate(long ms)
{
	assert(ms > 0);

	msPerUpdate = ms;
}

void Director::loop()
{
	long current, previous, lag = 0;
	previous = getCurrentMillSecond();

	while(true)
	{
		current = getCurrentMillSecond();
		lag += current - previous;
		previous = current;

		auto scene = getCurrentScene();
		if(paused || scene == nullptr)
			continue;

		while(lag >= msPerUpdate)
		{
			scene->update();
			lag -= msPerUpdate;
		}

		scene->render();
	}
}

#ifdef OS_UNIX

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

Director::Director()
		: paused(false), msPerUpdate(16)
{
  // ���� raw ģʽ
  termios mode;
  if(tcgetattr(STDOUT_FILENO, &mode) == -1)
    assert(false);
  mode.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &mode) == -1)
    assert(false);
}

Size Director::getWinSize() const
{
	winsize winSize;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &winSize);
	return Size(winSize.ws_col, winSize.ws_row + 1);
}

#include <sys/time.h>

long Director::getCurrentMillSecond() const
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec * 1000 + t.tv_usec * 0.001;
}

#endif // OS_UNIX

#ifdef OS_WIN

Director::Director()
		: paused(false), msPerUpdate(16)
{
  // ���� VT100ģʽ
	const auto hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD      mode;
	if(!GetConsoleMode(hStdOut, &mode))
		assert(false);
	if(!SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING))
		assert(false);
}

Size Director::getWinSize() const
{
	static const auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	auto ret = GetConsoleScreenBufferInfo(hOut, &screenInfo);
	if(!ret)
		assert(false);

	return Size(screenInfo.srWindow.Right + 1, screenInfo.srWindow.Bottom + 1);
}

long Director::getCurrentMillSecond() const
{
	LARGE_INTEGER freq;
	BOOL          ret = QueryPerformanceFrequency(&freq);
	assert(ret != 0);

	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return time.QuadPart * 1000000 / freq.QuadPart;
}

/*
void Director::loop()
{
	LARGE_INTEGER current, previous, freq;
	long          lag = 0;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&previous);

	const long interval = secPerUpdate * freq.QuadPart;

	while(true)
	{
		QueryPerformanceCounter(&current);
		lag += (long)(current.QuadPart - previous.QuadPart);
		previous.QuadPart = current.QuadPart;

		auto scene = getCurrentScene();
		if(paused || scene == nullptr)
			continue;

		while(lag >= interval)
		{
			scene->update();
			lag -= interval;
		}

		scene->render();
	}
}
*/

#endif // OS_WIN
