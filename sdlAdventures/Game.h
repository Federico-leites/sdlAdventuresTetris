#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Tetrimino.h"
#include <vector>


class Game
{
private:
	Game();
	~Game();
	bool m_bRunning;

	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	std::vector<GameObject*> m_gameObjects;

	static Game* s_pInstance;
	
	void draw();

public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullScreen);
	void update();
	void handleEvents();
	void render();
	void clean();
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	bool getIsRunning();
};
typedef Game Tetris;
