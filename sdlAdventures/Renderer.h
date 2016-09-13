#pragma once
#include "TextureManager.h"

class Renderer
{
public:
	Renderer(SDL_Window* window);
	virtual ~Renderer();

	void drawAsset(std::string id, int x, int y, int width,
		int height, int currentRow, int currentFrame,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	bool isLibraryRendererReady() { return m_pRenderer != 0 ? true : false; };

	// sets background color in RGBA value
	void setBackgroundColor(int R, int G, int B, int A);

	//loads assets to texture map
	bool loadAsset(std::string filePath, std::string textureID);

	// clears the screen
	void clearScreen();

	// show window screen 
	// review
	void showWindowScreen();

private:
	TextureManager* m_textureManager;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

};

