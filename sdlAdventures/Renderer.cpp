#include "Renderer.h"
#include <Windows.h>
#define DEBUG(x) OutputDebugString(x)


Renderer::Renderer(SDL_Window* window)
{
	m_pWindow = window;
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);


	m_textureManager = new TextureManager();
}


Renderer::~Renderer()
{
	//delete &m_textureManager;
}

void Renderer::drawAsset(std::string id, int x, int y, int width,
	int height, int currentRow, int currentFrame, 
	SDL_RendererFlip flip)
{
	//DEBUG("Renderer::drawAsset\n");
	m_textureManager->drawframe(id, x, y, width, height, currentRow, currentFrame, m_pRenderer, flip);
}

void Renderer::setBackgroundColor(int R, int G, int B, int A)
{
	SDL_SetRenderDrawColor(m_pRenderer, R, G, B, A);
}

bool Renderer::loadAsset(std::string filePath, std::string textureID)
{
	return m_textureManager->load(filePath, textureID, m_pRenderer);
}

void Renderer::clearScreen() 
{
	//DEBUG("Renderer::clearScreen\n");
	SDL_RenderClear(m_pRenderer);
}

void Renderer::showWindowScreen()
{
	//DEBUG("Renderer::showWindowScreen\n");
	SDL_RenderPresent(m_pRenderer);
}
