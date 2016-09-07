#include<SDL.h>
#include "Game.h"

Game* g_game = 0;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]) {
	Uint32 frameStart, frameTime;

	if (Tetris::Instance()->init("Level 1", 100, 100, 640, 480, false))
	{
		while (Tetris::Instance()->getIsRunning())
		{
			frameStart = SDL_GetTicks();

			Tetris::Instance()->handleEvents();
			Tetris::Instance()->update();
			Tetris::Instance()->render();
			
			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}			
		}
		Tetris::Instance()->clean();
	}
	else
	{
		return -1;
	}

	return 0;
};