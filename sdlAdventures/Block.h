#pragma once
#include "SDLGameObject.h"
class Block :
	public SDLGameObject
{
public:
	Block(const Loader* pParams, Renderer& gameRenderer, bool isOccupied);
	virtual ~Block();
	void draw();

private:
	bool m_bIsOccupied;
};

