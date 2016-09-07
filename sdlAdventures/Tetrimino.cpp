#include "Tetrimino.h"

Tetrimino::Tetrimino(const Loader* pParams): SDLGameObject(pParams)
{

}


Tetrimino::~Tetrimino()
{
}


void Tetrimino::draw()
{
	SDLGameObject::draw();
}


void Tetrimino::update()
{
	m_position -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Tetrimino::clean()
{
	SDLGameObject::clean();
	// tetrimino specific clean code
}
