#pragma once
#include "SDLGameObject.h"
#include "Block.h"

class GameBoard :
	public SDLGameObject
{
public:
	GameBoard(const Loader* pParams, Renderer& gameRenderer, int m_iRows, int m_iColumns);
	virtual ~GameBoard();

	Block* **m_pBlocksList;
	
	void draw();

private:
	int m_iColumns;
	int m_iRows;
	void drawBlocks();
};

