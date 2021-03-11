// Copyright 2020 SMS
// License(Apache-2.0)
// ͼ��

#include "sprite.h"
#include "frame_buffer.h"

void Sprite::setSize(Size s)
{
	size = s;
	buffer.resize(s.area());
}

Size Sprite::getSize() const
{
	return size;
}

void Sprite::onAdd()
{
	owner->getScene()->addSprite(*this);
}

void Sprite::onRemove()
{
	owner->getScene()->removeSprite(*this);
}
