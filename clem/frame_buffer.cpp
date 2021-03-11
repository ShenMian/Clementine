// Copyright 2020 SMS
// License(Apache-2.0)
// 帧缓冲区

#include "frame_buffer.h"
#include "director.h"
#include "tile.h"

FrameBuffer frameBuffer;

FrameBuffer::FrameBuffer()
		: current(nullptr), next(nullptr)
{
	setSize(Director::getInstance()->getWinSize());
}

FrameBuffer::~FrameBuffer()
{
	delete[] current;
	delete[] next;
}

void FrameBuffer::swapBuffers()
{
	auto temp = current;
	current   = next;
	next      = temp;
}

void FrameBuffer::drawRect(Rect r, const Tile& t)
{
	for(int x = r.left(); x <= r.right(); x++)
	{
		drawPoint(Point(x, r.top()), t);
		drawPoint(Point(x, r.bottom()), t);
	}
	for(int y = r.top(); y <= r.bottom(); y++)
	{
		drawPoint(Point(r.left(), y), t);
		drawPoint(Point(r.right(), y), t);
	}
}

void FrameBuffer::drawRectFill(Rect r, const Tile& t)
{
	for(int y = 0; y < r.height; y++)
		for(int x = 0; x < r.width; x++)
			drawPoint({r.x + x, r.y + y}, t);
}

void FrameBuffer::clear()
{
	for(int y = 0; y < size.y; y++)
		for(int x = 0; x < size.x; x++)
			drawPoint(Point(x, y), Tile(' '));
}

void FrameBuffer::setSize(Size s)
{
	size = s;
	if(current != nullptr)
		delete[] current;
	if(current != nullptr)
		delete[] next;
	current = new buffer_t[size.area()]();
	next    = new buffer_t[size.area()]();
}

Size FrameBuffer::getSize() const
{
	return size;
}

#ifdef OS_UNIX

void FrameBuffer::drawPoint(Point p, const Tile& t)
{
}

void FrameBuffer::render()
{
}

#endif

#ifdef OS_WIN

#include "director.h"

void FrameBuffer::drawPoint(Point p, const Tile& t)
{
	if(p.x < 0 || p.x >= size.x || p.y < 0 || p.y >= size.y)
		return;
	next[(int)p.y * size.x + (int)p.x].Char.AsciiChar = t.getChar();
	next[(int)p.y * size.x + (int)p.x].Attributes     = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
}

void FrameBuffer::render()
{
	// CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	// GetConsoleScreenBufferInfo(hStdOut, &bufInfo);
	auto       hStdOut     = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT writeRegion = {0, 0, (SHORT)size.x, (SHORT)size.y};
	WriteConsoleOutput(hStdOut,
										 current,
										 {(short)size.x, (short)size.y},
										 {0, 0},
										 &writeRegion);
}

#endif // OS_WIN
