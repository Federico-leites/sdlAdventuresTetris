#include "Game.h"
 

#include <Windows.h>
#include<iostream>
#include <sstream>
#define DEBUG(x) OutputDebugString(x)

Game::Game(){}

Game* Game::s_pInstance = nullptr;

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
			m_gameRenderer = new Renderer(m_pWindow);


			if (m_gameRenderer->isLibraryRendererReady()) {
				std::cout << "renderer creation success" << std::endl;

				//set background color
				m_gameRenderer->setBackgroundColor(255, 255, 255, 255);
				initGameBoard();
			}
			else
			{
				std::cout << "renderer init fail" << std::endl;
				DEBUG("renderer init fail");
				m_bRunning = true;
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail" << std::endl;
			DEBUG("window init fail");
			m_bRunning = true;
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail" << std::endl;
		DEBUG("SDL init fail");
		return false; // could not initialize sdl
		m_bRunning = true;
	}

	DEBUG("init success\n");
	std::cout << "init success\n";
	m_bRunning = true;

	return true;
}

void Game::render() {
	// clear the window
	m_gameRenderer->clearScreen();
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

	// show the window
	m_gameRenderer->showWindowScreen();
}

void Game::clean(){
	std::cout << "cleaning game subsystems" << std::endl;
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		delete &m_gameObjects[i];
	}
	delete m_gameRenderer;
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

bool Game::initGameBoard()
{
	if (!m_gameRenderer->loadAsset("assets/board.png", "gameBoardBackground"))
	{

		DEBUG("Error loading Game Background asset");
		std::cout << "Texture manager init fail" << std::endl;
		return false;
	}
	
	m_gameObjects.push_back(new GameBoard(new Loader(0, 0, 320, 640, "gameBoardBackground"), *m_gameRenderer, 20, 10));
}

bool Game::getIsRunning() {
	return m_bRunning;
}

Game::~Game()
{
	
}
