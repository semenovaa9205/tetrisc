// car.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <SFML\Graphics.hpp>
#include "packages\sfml_system.2.5.1\build\native\include\SFML\System\Time.hpp"

//#pragma comment(lib, "packages\sfml_graphics.2.5.1\build\native\lib\x64\v141\Debug\dynamic\sfml-graphics-d.lib")
//using namespace sf;
// tetrisc.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <SFML\Graphics.hpp>
#include<time.h>
using namespace sf;
const int M = 20;
const int N = 10;
int field[M][N] = { 0 };
int w = 34;
int figures[7][4] = {
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,4,7,
	2,3,5,7,
	3,5,7,6,
	2,3,4,5,
};
struct Point
{
	int x, y;
}a[4], b[4];
int main() {
	RenderWindow window(VideoMode(N * w, M * w), "Tettris");
	Texture t;
	 t.loadFromFile("C:/Users/andrey/src/tetrisc/Paint/tetris.png");
	//t.loadFromFile("F:\\WorkF\\tmp\\redsquare400x400.png");	
	Sprite tet(t);
	tet.setTextureRect(IntRect(0, 0, w, w));
	int dx = 0;
	bool rotate = false;

	int n = 3;
	if(a[0].x==0)
	for (int i = 0; i < 4; i++)
	{
		a[i].x = figures[n][i] % 2;
		a[i].y = figures[n][i] / 2;
	}
	dx = 0;
	rotate = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)
				{
					rotate = true;
				}
				else if (event.key.code == Keyboard::Right)
				{
					dx = 1;
				}
				else if (event.key.code == Keyboard::Left)
				{
					dx = -1;
				}
			}

			window.clear(Color::White);
			for (int i = 0; i < 4; i++)
			{
				tet.setPosition(a[i].x * w, a[i].y * w);
				window.draw(tet);
			}
			window.display();

		} 
		if (rotate) {
			Point p = a[1];
			for (int i = 0; i < 3; i++)
			{
				int x = a[i].y - p.y;
				int y = a[i].x - p.y;

				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
		for (int i = 0; i < 4; i++)
		{
			if (a[i].x <= 0 && dx < 0) dx = 0;
			if (a[i].x >= 7 && dx > 0) dx = 0;
		}

		for (int i = 0; i < 4; i++)
		{
			a[i].x += dx;
		}

		dx = 0;

		
		}



	}
	return 0;
}

