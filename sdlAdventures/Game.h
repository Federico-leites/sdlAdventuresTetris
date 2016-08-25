#pragma once

#include "SDL.h"

class Game
{
private:
	bool m_bRunning;

	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
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

