// Copyright 2020 SMS
// License(Apache-2.0)
// �¼�

#include "event.h"

Event::Event(Type type)
	: type(type)
{
}

Event::Type Event::getType() const
{
	return type;
}

