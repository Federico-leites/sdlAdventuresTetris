#include "GameBoard.h"



GameBoard::GameBoard(const Loader* pParams, Renderer& gameRenderer, int rows, int cols) :SDLGameObject(pParams, gameRenderer),
m_iRows(rows), m_iColumns(cols)
{
	for (size_t c = 0; c < cols; c++)
	{
		for (size_t r = 0; r < rows; r++)
		{
			// block properties will live outside in a gameConfig Namespace
			//ToDo move hardcoded values to gameConfig
			m_pBlocksList[c][r] = new Block(new Loader((r * 36 + 2), (r * 36 + 2), 36, 36, "red"), gameRenderer, true);
		}
	}
}

void GameBoard::drawBlocks()
{
	for (size_t c = 0; c < m_iColumns; c++)
	{
		for (size_t r = 0; r < m_iRows; r++)
		{
			
			m_pBlocksList[c][r]->draw();
		}
	}
}

void GameBoard::draw()
{
	SDLGameObject::draw();
	drawBlocks();
}


GameBoard::~GameBoard()
{
	for (size_t c = 0; c < m_iColumns; c++)
	{
		for (size_t r = 0; r < m_iRows; r++)
		{

			delete m_pBlocksList[c][r];
		}
	}
}
