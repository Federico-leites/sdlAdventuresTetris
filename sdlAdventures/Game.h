#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Renderer.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Tetrimino.h"
#include "GameBoard.h"
#include <vector>


class Game
{
private:
	Game();
	virtual ~Game();
	bool m_bRunning;

	SDL_Window* m_pWindow = nullptr;
	//todo remove m_pRenderer
	SDL_Renderer* m_pRenderer = nullptr;

	std::vector<GameObject*> m_gameObjects;
	Renderer* m_gameRenderer;

	static Game* s_pInstance;
	
	bool initGameBoard();

public:
	static Game* Instance()
	{
		if (s_pInstance == nullptr)
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
