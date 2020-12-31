// Copyright 2020 SMS
// License(Apache-2.0)
// �ֱ��¼�

#include "gamepad_event.h"

GamepadEvent::GamepadEvent(SubType subType, Gamepad* gamepad)
		: subType(subType), gamepad(gamepad)
{
	Event(Event::Type::gamepad);
}

SubType GamepadEvent::getSubType() const
{
	return subType;
}

Gamepad* GamepadEvent::getGamepad() const
{
	return gamepad;
}
