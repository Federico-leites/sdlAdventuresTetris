#include "GameBoard.h"



GameBoard::GameBoard(const Loader* pParams, Renderer& gameRenderer, int rows, int cols) :SDLGameObject(pParams, gameRenderer),
m_iRows(rows), m_iColumns(cols)
{
}


GameBoard::~GameBoard()
{
}
