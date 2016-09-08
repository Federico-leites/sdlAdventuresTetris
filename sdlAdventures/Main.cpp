#include<SDL.h>
#include "Game.h"
#include <string>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

const char GAME_NAME[] = "Tetris";
const int POS_X = 100;
const int POS_Y = 100;
const int GAME_WINDOW_WIDTH = 100;
const int GAME_WINDOW_HEIGHT = 100;
const bool GAME_OPTION_FULLSCREEN = false;

int main(int argc, char* args[]) {
	Uint32 frameStart, frameTime;

	if (Tetris::Instance()->init(
		GAME_NAME,
		POS_X,
		POS_Y,
		GAME_WINDOW_WIDTH,
		GAME_WINDOW_HEIGHT,
		GAME_OPTION_FULLSCREEN))
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