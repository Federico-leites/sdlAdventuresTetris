#include "Game.h"
#include<iostream>

Game::Game(){}

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullScreen)
{
	int flags = 0;
	if(fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Initilize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);


		if (m_pWindow != 0)
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) {
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
				
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // could not initialize sdl
	}

	std::cout << "init success\n";
	m_bRunning = true;

	return true;
}

void Game::render() {
	// clear the window to black
	SDL_RenderClear(m_pRenderer);

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean(){
	std::cout << "cleaning game subsystems\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	
	if (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	
}

bool Game::getIsRunning() {
	return m_bRunning;
}

Game::~Game()
{
}
