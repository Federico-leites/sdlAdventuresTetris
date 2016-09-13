#pragma once
#include "SDLGameObject.h"
#include "Renderer.h"

class Tetrimino : public SDLGameObject
{
public:
	Tetrimino(const Loader* pParams, Renderer& gameRenderer);
	virtual void update();

	virtual ~Tetrimino() {};
};

