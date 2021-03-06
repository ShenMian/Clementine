#include "component.h"
// Copyright 2020 SMS
// License(Apache-2.0)
// ���

#include "component.h"

void Component::onEnter()
{
}

void Component::onExit()
{
}

void Component::onAdd()
{
}

void Component::onRemove()
{
}

void Component::setOwner(Factor* o)
{
	this->owner = o;
}

Factor* Component::getOwner() const
{
	return owner;
}