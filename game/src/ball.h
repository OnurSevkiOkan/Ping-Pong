#pragma once
#include "raylib.h"
#include <iostream>
using namespace std;

class Ball
{

private:
	int screen_height = GetScreenHeight(); // Don't necessary at all.
	int screen_width = GetScreenWidth();

public:
	float x, y; // Movement variables.
	int speed_x, speed_y;
	float radius;

	void Draw()
	{
		DrawCircle(x, y, radius, WHITE); // Draws a ball on the center of the screen
	}

	void updateBall()
	{
		x += speed_x;
		y += speed_y;

		if (y + radius >= GetScreenHeight() || y + radius <= 0)
		{
			speed_y *= -1;
		}

		if (x + radius >= GetScreenWidth())//player score++
		{
			player_score ++;
			resetBall();
		}  
		if (x - radius <= 0)
		{
			AI_score ++;
			resetBall();
		}
	}

	void drawScore() // Draws the score on the window.
	{
		DrawText(TextFormat("%i", player_score), GetScreenWidth() / 4, 20, 80, WHITE);
		DrawText(TextFormat("%i", AI_score), 3 * GetScreenWidth()/4, 20, 80, WHITE);
	}

	void resetBall() // Reset the ball into center of the window.
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;

		// Randomize the movement of the ball;
		int speed_choices[2] = { -1, 1 };
		speed_x *= speed_choices[GetRandomValue(0, 1)];
		speed_y *= speed_choices[GetRandomValue(0, 1)];
	}
};