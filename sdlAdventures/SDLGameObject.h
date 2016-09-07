#pragma once
#include "GameObject.h"
#include "Loader.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const Loader* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	~SDLGameObject();

protected:
	Vector2D m_position;

	int m_width;
	int m_height;

	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

