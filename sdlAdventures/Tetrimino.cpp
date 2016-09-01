#include "Tetrimino.h"



Tetrimino::Tetrimino()
{
}


Tetrimino::~Tetrimino()
{
}

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}


void Tetrimino::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
	// tetrimino specific draw code
}


void Tetrimino::update()
{
	GameObject::update();
	// tetrimino specific update code
	m_x += 1;
}

void Tetrimino::clean()
{
	GameObject::clean();
	// tetrimino specific clean code
}
