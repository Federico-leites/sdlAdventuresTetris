#pragma once
#include "SDLGameObject.h"

class Tetrimino : public SDLGameObject
{
public:
	Tetrimino(const Loader* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual ~Tetrimino();
};

