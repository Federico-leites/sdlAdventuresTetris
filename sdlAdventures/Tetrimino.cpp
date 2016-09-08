#include "Tetrimino.h"

Tetrimino::Tetrimino(const Loader* pParams, Renderer& gameRenderer): SDLGameObject(pParams, gameRenderer)
{

}


Tetrimino::~Tetrimino()
{
}


void Tetrimino::update()
{
	m_position -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
