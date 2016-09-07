#include "Game.h"

#include <Windows.h>
#include<iostream>
#include <sstream>

Game::Game(){}

Game* Game::s_pInstance = 0;

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

				if (!TheTextureManager::Instance()->load("assets/animate.png",
					"animate", m_pRenderer))
				{

					OutputDebugString("Texture manager init fail");
					std::cout << "Texture manager init fail" << std::endl;
					return false;
				}				
				m_gameObjects.push_back(new Tetrimino(new Loader(100, 100, 128, 82, "animate")));
			}
			else
			{
				std::cout << "renderer init fail" << std::endl;
				OutputDebugString("renderer init fail");
				m_bRunning = true;
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail" << std::endl;
			OutputDebugString("window init fail");
			m_bRunning = true;
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail" << std::endl;
		OutputDebugString("SDL init fail");
		return false; // could not initialize sdl
		m_bRunning = true;
	}

	OutputDebugString("init success\n");
	std::cout << "init success\n";
	m_bRunning = true;

	return true;
}

void Game::render() {
	// clear the window to black
	SDL_RenderClear(m_pRenderer);

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::draw() 
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
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
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

bool Game::getIsRunning() {
	return m_bRunning;
}

Game::~Game()
{
}
