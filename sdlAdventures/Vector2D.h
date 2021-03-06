#pragma once
#include <math.h>

//ToDo copy definition code to source file.
class Vector2D
{
public:
	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	// Vector addition
	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}


	friend Vector2D& operator+= (Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		
		return v1;
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	// Vector substraction
	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-= (Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	friend Vector2D& operator-= (Vector2D& v1, int number)
	{
		v1.m_x -= number;
		v1.m_y -= number;

		return v1;
	}

	// Vector division
	Vector2D operator/(float scalar)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}

	// Vector normalization
	void normalize()
	{
		float l = length();
		if (l > 0) // to evade dividing by zero
		{
			(*this) *= 1 / l;
		}
	}

private:
	float m_x;
	float m_y;
};

