// Copyright 2020 SMS
// License(Apache-2.0)
// ���

#ifndef CLEM_COMPONENT_H_
#define CLEM_COMPONENT_H_

class Factor;

class Component
{
public:
	virtual void update() = 0;

	virtual void onEnter();
	virtual void onExit();
	virtual void onAdd();
	virtual void onRemove();

	void    setOwner(Factor* owner);
	Factor* getOwner() const;

protected:
	Factor* owner;
};

#endif // !CLEM_COMPONENT_H_

