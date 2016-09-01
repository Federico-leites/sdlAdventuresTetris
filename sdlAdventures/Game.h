#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Tetrimino.h"


class Game
{
private:
	bool m_bRunning;

	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	int m_currentFrame;
	TextureManager m_textureManager;
	GameObject m_gameObject;
	Tetrimino m_tetrimino;

public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullScreen);
	void update();
	void handleEvents();
	void render();
	void clean();

	bool getIsRunning();
};

