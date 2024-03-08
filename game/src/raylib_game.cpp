/*******************************************************************************************
*
*   Ping-Pong
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
#include "variables.h" // Includes variables.
#include "ball.h" // Ball movement and scoring.
#include "paddle.h" // Creating AI and player movement.

using namespace std;

Ball ball;
Paddle player;
CPU_paddle cpu;


int main(void)
{	
	//SetTraceLogLevel(7);

	InitWindow(screen_width, screen_height, "Ping-Pong"); // Defines a windows.
	SetTargetFPS(targetFPS); // Sets the fps to 60.

	ball.radius = 20; // Size of ball
	ball.x = center_X; // Start position of ball(center of the windows)
	ball.y = center_Y;
	ball.speed_x = 7; // Velocity of the ball in 2D
	ball.speed_y = 7;

	player.width = paddle_width; // Size of player paddle
	player.height = paddle_height;
	player.x = 10;
	player.y = center_paddle_Y;
	player.speed = 6;

	cpu.width = paddle_width; // Size of AI paddle
	cpu.height = paddle_height;
	cpu.x = GetScreenWidth() - player.width - 10;
	cpu.y = center_paddle_Y;
	cpu.speed = 6;



	while (WindowShouldClose() == false) // Keeps the window open.
	{
		BeginDrawing(); // To start drawing objects on the screen.
		

		ball.updateBall(); //Calls the update function from ball.h
		player.updatePlayer(); //Calls the update function from paddle.h
		cpu.UpdateCPU(ball.y);

		ClearBackground(BLACK); // To remove the trace of the ball

		player.Draw();
		ball.Draw();
		cpu.Draw();
		ball.drawScore();

		// Checks for if ball interacted with collisions of player paddle. 
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ player.x,player.y,player.width,player.height }))
		{
			ball.speed_x *= -1;
		}

		// Checks for if ball interacted with collisions of AI paddle. 
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpu.x,cpu.y,cpu.width,cpu.height }))
		{
			ball.speed_x *= -1;
		}

		// Draws a line on the center of the window.
		DrawLine(center_X, 0, center_X, screen_height, WHITE);
		
		//std::cout << ball.y;
		//std::cout << player_score;
		//std::cout << AI_score;

		EndDrawing();
	}
	
	CloseWindow();
	cout << "Succesfull"; // Test print.
}
