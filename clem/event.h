// Copyright 2020 SMS
// License(Apache-2.0)
// �¼�

#ifndef CLEM_EVENT_H_
#define CLEM_EVENT_H_

class Event
{
public:
	enum class Type
	{
		keyboard,
		gamepad
	};

	Event(Type type);

	Type getType() const;

private:
	Type type;
};

#endif // !CLEM_EVENT_H_

