#pragma once
#include "SDLGameObject.h"
class GameBoard :
	public SDLGameObject
{
public:
	GameBoard(const Loader* pParams, Renderer& gameRenderer, int m_iRows, int m_iColumns);
	virtual ~GameBoard();
	int m_iColumns;
	int m_iRows;

};

