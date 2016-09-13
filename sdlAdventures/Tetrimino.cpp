#include "Tetrimino.h"
#define DEBUG(x) OutputDebugString(x)

Tetrimino::Tetrimino(const Loader* pParams, Renderer& gameRenderer): SDLGameObject(pParams, gameRenderer)
{

}



void Tetrimino::update()
{
	m_position -= 1;
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
