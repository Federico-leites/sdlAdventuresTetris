#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const Loader* pParams, Renderer& gameRenderer) : GameObject(pParams),
m_rGameRenderer(gameRenderer), m_position(pParams->getX(), pParams->getY())
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_currentRow = 1;
	m_currentFrame =1;
	
	m_textureID = pParams->getTextureID();
}


SDLGameObject::~SDLGameObject()
{
}

void SDLGameObject::draw()
{
	m_rGameRenderer.drawAsset(m_textureID, (int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height, m_currentRow, m_currentFrame);
}

void SDLGameObject::update()
{
}

void SDLGameObject::clean()
{
}