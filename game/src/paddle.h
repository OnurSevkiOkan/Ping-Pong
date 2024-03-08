#include "raylib.h"
#include <iostream>
#include "variables.h"


class Paddle
{
protected:
	void limitMovement() // Limits the movement if paddle try get out of window.
	{
		if (y <= 0)
		{
			y = 0;
		}
		if (y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}
	}
public:
	float x, y;
	float width, height;
	int speed;
	
	void Draw() // Creates paddles.
	{
		DrawRectangle(x,y, paddle_width, paddle_height, WHITE);
	}

	void updatePlayer() // Checks key to control the paddle.
	{
		if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
		{
			y = y - speed;
		}
		if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
		{
			y = y + speed;
		}

		limitMovement();
	}

};

class CPU_paddle : public Paddle // AI to play with someone
{
public:
	void UpdateCPU(int ball_y)
	{
		if (y + height / 2 > ball_y)
		{
			y = y - speed;
		}
		if (y + height / 2 <= ball_y)
		{
			y = y + speed;
		}
	
		limitMovement();
	}

};