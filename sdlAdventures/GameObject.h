#pragma once
#include <iostream>
#include "Loader.h"

class GameObject
{
public:

	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;

protected:
	GameObject(const Loader* pParams) {}
	virtual ~GameObject() {}
};

