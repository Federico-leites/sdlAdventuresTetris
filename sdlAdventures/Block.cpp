#include "Block.h"



Block::Block(const Loader* pParams, Renderer& gameRenderer, bool isOccupied):
	SDLGameObject(pParams, gameRenderer),
	m_bIsOccupied(isOccupied)
{
}

void Block::draw()
{
	if (m_bIsOccupied) {
		SDLGameObject::draw();
	} 
}


Block::~Block()
{
}
