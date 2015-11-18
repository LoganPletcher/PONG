#include <time.h>
#include <iostream>
#include "GameLoop.h"
#include "Vector.h"

void BULLET(int &bullet, int deltaTime, int movement)
{
	bullet -= movement * deltaTime;
}

float x = 50;
float y = 450;
int size = 50;
int sides = 50;
int R = 255;
int G = 255;
int B = 0;
int density = 255;
float currentTime = clock();
float previousTime = currentTime;
int deltaTime = 0;
int bullet = 1610;
int by = 500;
float a = 1550;
float b = 450;
bool p1W = false;
bool p1S = false;
//bool p1D = false;
//bool p1A = false;
bool p2UP = false;
bool p2DOWN = false;
//bool p2RIGHT = false;
//bool p2LEFT = false;
int movement = 10;
int p1Score = -1;
int p2Score = 0;
bool down = false;
bool up = false;

void GameLoop::Loop()
{
	while (m_bRunning)
	{
		SDL_Event sdlEvent; // Will hold the next event to be parsed

		while (m_bRunning)
		{
			// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
			// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
			// 'SDL_PollEvent' returns 0 when there are no more events to parse
			while (SDL_PollEvent(&sdlEvent))
			{
				// Calls the redefined event function for the EventHandler class
				// Refer to its header file and cpp for more information on what each inherited function is capable of
				// and its syntax
				OnEvent(sdlEvent);
			}
			currentTime = clock();
			deltaTime = (currentTime - previousTime) / 10;	//creates Delta time
			std::cout << deltaTime << std::endl;			//prints out the delta time

			previousTime = currentTime;

			if (down)			
			{
				by += 10;
			}
			//The if statement above and below are boolean checkers that checks to see if one of them is true.
			//down increases the y of the bullet causing it to move down, up decreases the y of the bullet causing it to move up
			if (up)
			{
				by -= 10;
			}

			if (by >= 890)
			{
				down = false;
				up = true;
			}
			//The if statements above and below check the bullet's y. If it "hits" 890, aka the bottom of the screen,
			if (by <= 10)
			{
				down = true;
				up = false;
			}

			if (((bullet == x - 20) && (by >= y - 10 && by <= y + 100)))
			{
				if (by > y + 40)
				{
					up = false;
					down = true;
				}
				else if (by < y + 40)
				{
					down = false;
					up = true;
				}
				else
				{
					down = false;
					up = false;
				}
				movement = -10;
			}

			if (((bullet - 20 == a) && (by >= b - 10 && by <= b + 100)))
			{
				if (by > b + 40)
				{
					up = false;
					down = true;
				}
				else if (by < b + 40)
				{
					down = false;
					up = true;
				}
				else
				{
					down = false;
					up = false;
				}
				movement = 10;
			}

			if ((bullet < 1610 && bullet > -10))
			{
				BULLET(bullet, deltaTime, movement);
			}
			
			else if (bullet >= 1610) { bullet = 800; by = 500; down = false; up = false; p1Score++; }

			else if (bullet <= -10) { bullet = 800; by = 500; down = false; up = false; p2Score++; }

			if (p1W) { if (y > 0) { y -= 10 * deltaTime; } }

			if (p1S) { if (y < 800) { y += 10 * deltaTime; } }

			//if (p1D) { if (x < 1150) { x += 50 * deltaTime; } }

			//if (p1A) { if (x > 450) { x -= 50 * deltaTime; } }

			if (p2UP) { if (b > 0) { b -= 10 * deltaTime; } }
			
			if (p2DOWN) { if (b < 800) { b += 10 * deltaTime; }}

			//if (p2RIGHT) { if (a < 1150) { a += 50 * deltaTime; } }

			//if (p2LEFT) { if (a > 450) { a -= 50 * deltaTime; } }
			
			//std::cout << p1Score << std::endl;

			if (p1Score == 25 || p2Score == 25)
			{
				m_bRunning = false; break;
			}

			Update();

			LateUpdate();

			Draw();

			Graphics::Flip(); // Required to update the window with all the newly drawn content
		}
	}
}

void GameLoop::Update()
{

}
void GameLoop::LateUpdate()
{

}

void GameLoop::Draw()
{
	//for (float i = 0; i < 9; i++)
	//{
	//	Graphics::DrawLine({ 400 , 50 + (100 * i) }, { 1200, 50 + (100 * i) }, { 255, 255, 255, 255 });
	//	Graphics::DrawLine({ 400 + (100 * i), 50 }, { 400 + (100 * i), 850 }, { 255, 255, 255, 255 });
	//}
	//Graphics::DrawCircle({ x, y }, size, sides, { R, G, B, density });
	Graphics::DrawRect({ 10, y }, { 10, 100 }, { 85, 107, 47, 255 });
	//Graphics::DrawCircle({ a, b }, size, sides, { R, G, B, density });
	Graphics::DrawRect({ 1580, b }, { 10, 100 }, { 112, 41, 99, 255 });
	Graphics::DrawCircle({ bullet, by }, 10, 500, { 255,255,255,255 });
	for (int i = 0; i < 10; i++)
	{
		if (p1Score / 10 == 0)
		{
			Graphics::DrawRect({ 450, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 1)
		{
			Graphics::DrawRect({ 510, 20 }, { 10,110 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 2)
		{
			Graphics::DrawRect({ 450, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 3)
		{
			Graphics::DrawRect({ 450, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,100 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 4)
		{
			Graphics::DrawRect({ 450, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,110 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 5)
		{
			Graphics::DrawRect({ 450, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 70 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 6)
		{
			Graphics::DrawRect({ 450, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 20 }, { 10,110 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 70 }, { 10,60 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 7)
		{
			Graphics::DrawRect({ 450, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,110 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 8)
		{
			Graphics::DrawRect({ 450, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 60,10 }, { 255,255,255,255 });
		}
		if (p1Score / 10 == 9)
		{
			Graphics::DrawRect({ 450, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 510, 20 }, { 10,110 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 450, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		for (int j = 0; j < 10; j++)
		{
			if (p1Score - i * 10 == 0)
			{
				Graphics::DrawRect({ 530, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 1)
			{
				Graphics::DrawRect({ 590, 20 }, { 10,110 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 2)
			{
				Graphics::DrawRect({ 530, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 3)
			{
				Graphics::DrawRect({ 530, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,100 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 4)
			{
				Graphics::DrawRect({ 530, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,110 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 5)
			{
				Graphics::DrawRect({ 530, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 70 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 6)
			{
				Graphics::DrawRect({ 530, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 20 }, { 10,110 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 70 }, { 10,60 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 7)
			{
				Graphics::DrawRect({ 530, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,110 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 8)
			{
				Graphics::DrawRect({ 530, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 60,10 }, { 255,255,255,255 });
			}
			if (p1Score - i * 10 == 9)
			{
				Graphics::DrawRect({ 530, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 590, 20 }, { 10,110 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 530, 120 }, { 70,10 }, { 255,255,255,255 });
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (p2Score / 10 == 0)
		{
			Graphics::DrawRect({ 1110, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 1)
		{
			Graphics::DrawRect({ 1170, 20 }, { 10,110 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 2)
		{
			Graphics::DrawRect({ 1110, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 3)
		{
			Graphics::DrawRect({ 1110, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,100 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 4)
		{
			Graphics::DrawRect({ 1110, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,110 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 5)
		{
			Graphics::DrawRect({ 1110, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 70 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 6)
		{
			Graphics::DrawRect({ 1110, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 20 }, { 10,110 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 70 }, { 10,60 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 7)
		{
			Graphics::DrawRect({ 1110, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,110 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 8)
		{
			Graphics::DrawRect({ 1110, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 20 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,100 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 60,10 }, { 255,255,255,255 });
		}
		if (p2Score / 10 == 9)
		{
			Graphics::DrawRect({ 1110, 20 }, { 70,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1170, 20 }, { 10,110 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 20 }, { 10,60 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 70 }, { 60,10 }, { 255,255,255,255 });
			Graphics::DrawRect({ 1110, 120 }, { 70,10 }, { 255,255,255,255 });
		}
		for (int j = 0; j < 10; j++)
		{
			if (p2Score - i * 10 == 0)
			{
				Graphics::DrawRect({ 1190, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 1)
			{
				Graphics::DrawRect({ 1250, 20 }, { 10,110 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 2)
			{
				Graphics::DrawRect({ 1190, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 3)
			{
				Graphics::DrawRect({ 1190, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,100 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 4)
			{
				Graphics::DrawRect({ 1190, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,110 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 5)
			{
				Graphics::DrawRect({ 1190, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 70 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 6)
			{
				Graphics::DrawRect({ 1190, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 20 }, { 10,110 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 70 }, { 10,60 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 7)
			{
				Graphics::DrawRect({ 1190, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,110 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 8)
			{
				Graphics::DrawRect({ 1190, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 20 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,100 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 60,10 }, { 255,255,255,255 });
			}
			if (p2Score - i * 10 == 9)
			{
				Graphics::DrawRect({ 1190, 20 }, { 70,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1250, 20 }, { 10,110 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 20 }, { 10,60 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 70 }, { 60,10 }, { 255,255,255,255 });
				Graphics::DrawRect({ 1190, 120 }, { 70,10 }, { 255,255,255,255 });
			}
		}
	}
	//Vector<float> Vec1 = { 300, 0, 0 };												//Creates a 2D vector
	//Vector<float> Vec2 = { 0, 400, 0 };												//Creates another 2D vector
	//Vector<float> Vec3 = Vec1 + Vec2;												//Creates a third 2D vector 
	//Graphics::DrawLine({ 10, 10 }, { 10, Vec2.y }, { 255, 255, 255, 255 });			//Draws a line using the second 2D vector
	//Graphics::DrawLine({ 10, 10 }, { Vec1.x, 10 }, { 255, 255, 255, 255 });			//Draws a line using the first 2D vector
	//Graphics::DrawLine({ Vec3.x, 10 }, { 10, Vec3.y }, { 255, 255, 255, 255 });		//Draws a third line using the third 2D vector creating a triangle using all three lines
	//Vector<float> Vec3D = { 200, 300, 543 };										//Creates a 3D vector
	//float dotprod = Vec1.DotProduct(Vec2);											//Gets the dotproduct of Vec1 & Vec2
	//Vec3D.Magnitude();																//Creates a variable for the 3D vector magnitude
	//Vec3D.Normalize();																//Normalizes the 3D vector
	//Vector<float> Vec3DNi = { 1234, 3213, 8595 };									//Creates another 3D vector
	//Vec3DNi = Vec3DNi - Vec3D;														//Sets the values of the second 3D vector to the vector minus the first 3D vector
	//Vec3DNi = Vec3DNi.CrossProduct(Vec3D);											//Sets the values of the second 3D vector to the crossproduct of the first and second 3D vectors
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	printf("%s\n", SDL_GetKeyName(ac_sdlSym));
	switch (ac_sdlSym)
	{
	case SDLK_b: if (!((bullet - 10 <= x + size && bullet >= x - size) && (by <= y + size && by >= y - size))) { BULLET(bullet, deltaTime, movement);  break; } else { break; }
	case SDLK_w: p1W = true; /*if (y > 100) { y -= 100; break; } else { break; }*/ break;
	case SDLK_s: p1S = true; /*if (y < 800) { y += 100; break; } else { break; }*/ break;
	//case SDLK_d: p1D = true; /*if (x < 1150) { x += 100; break; } else { break; }*/ break;
	//case SDLK_a: p1A = true; /*if (x > 450) { x -= 100; break; } else { break; }*/ break;
	case SDLK_y: if (R < 255) { R += 5; break; } else { break; }
	case SDLK_h: if (R > 0) { R -= 5;  break; } else { break; }
	case SDLK_u: if (G < 255) { G += 5; break; } else { break; }
	case SDLK_j: if (G > 0) { G -= 5;  break; } else { break; }
	case SDLK_i: if (B < 255) { B += 5; break; } else { break; }
	case SDLK_k: if (B > 0) { B -= 5; break; } else { break; }
	case SDLK_UP: p2UP = true; /*if (b > 100) { b -= 100; break; } else { break; }*/ break;
	case SDLK_DOWN: p2DOWN = true; /*if (b < 800) { b += 100; break; } else { break; }*/ break;
	//case SDLK_RIGHT: p2RIGHT = true; /*if (a < 1150) { a += 100; break; } else { break; }*/ break;
	//case SDLK_LEFT: p2LEFT = true; /*if (a > 450) { a -= 100; break; } else { break; }*/ break;
	case SDLK_ESCAPE: m_bRunning = false; break;

	default: printf("%s\n",SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_w: p1W = false; break;
	case SDLK_s: p1S = false; break;
	//case SDLK_d: p1D = false; break;
	//case SDLK_a: p1A = false; break;
	case SDLK_UP: p2UP = false; break;
	case SDLK_DOWN: p2DOWN = false; break;
	//case SDLK_RIGHT: p2RIGHT = false; break;
	//case SDLK_LEFT: p2LEFT = false; break;
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
