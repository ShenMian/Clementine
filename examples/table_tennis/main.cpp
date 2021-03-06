// Copyright 2021 SMS
// License(Apache-2.0)
// Table tennis

#include "clem/clem.hpp"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <chrono>
#include <thread>

using std::chrono::seconds;
using std::this_thread::sleep_for;

using namespace std;

#include <clem/input/keyboard.h>
#include <clem/frame_buffer.h>

// width / height = 80 / 25 => width * 25 = height * 80
const short width  = 80;
const short height = width * 25 / 80;
const Size  winSize(width, height);

class Ball : public Factor
{
public:
	explicit Ball(Scene& s)
			: Factor(s)
	{
		sprite.setSize({1, 1});
		sprite.drawPoint({0, 0}, Tile('O'));

		collider.setSize({1, 1});

		body.addCollider(collider);

		addComponent(sprite);
		addComponent(body);
	}

	void onCollision(Collider&, Collider&) override
	{
		body.velocity = -body.velocity;
	}

	void setVelocity(const Vec2& v)
	{
		body.velocity = v;
	}

private:
	Sprite      sprite;
	Rigidbody   body;
	BoxCollider collider;
};

class Bar : public Factor
{
public:
	Bar(Scene& s)
			: Factor(s)
	{
		sprite.setSize({1, 5});
		sprite.drawLine({0, 0}, {0, 4}, Tile('#'));

		collider.setSize({1, 5});

		body.addCollider(collider);

		addComponent(sprite);
		addComponent(body);
	}

private:
	Sprite      sprite;
	Rigidbody   body;
	BoxCollider collider;
};

int main()
{
	Log::init();
	Cursor::setVisible(false);
	auto director = Director::getInstance();
	Scene scene;

	frameBuffer.setSize(winSize);

	Random random;
	Sprite sprite;
	sprite.setSize(winSize);
	Factor debug(scene);
	debug.addComponent(sprite);

	Bar bar(scene);
	bar.setPosition({1, winSize.y / 2.0f - 2});

	Ball ball(scene);
	ball.setPosition({winSize.x / 2.0f, winSize.y / 2.0f});
	ball.setVelocity({-30, 0});

	/*
	Ball testA(scene);
	testA.setPosition({117, 14});
	Ball testB(scene);
	testB.setPosition({2, 14});
	*/

	director->setMsPerRender(1000 / 60);
	director->pushScene(scene);
	director->run();

	for(int i = 0; i < 1000; i++)
	{
		for(int y = 0; y < sprite.getSize().y; y++)
			for(int x = 0; x < sprite.getSize().x; x++)
				sprite.drawPoint(x, y, Tile('0' + random.int32(0, 9)));
	}

	director->stop();
}
