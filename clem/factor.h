// Copyright 2020 SMS
// License(Apache-2.0)
// 游戏对象

#ifndef CLEM_GAME_OBJECT_H_
#define CLEM_GAME_OBJECT_H_

#include "texture.h"
#include <vector>

class Scene;
class Physics;

class Factor
{
public:
	Factor();
	Factor(const Texture& texture);

	virtual void update();

	void           setPosition(const Point& pos);
	const Point&   getPosition() const;
	void           setTexture(const Texture& texture);
	const Texture& getTexture() const;

protected:
	Point position;

private:
	Texture texture;
};

#endif // CLEM_GAME_OBJECT_H_
