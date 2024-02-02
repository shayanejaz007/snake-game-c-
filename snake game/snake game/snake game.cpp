#include<iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include<conio.h>
#include <string>
using namespace std;
void goto_xy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
int tail = 1;
char dir;
int fruitx, fruity, score =0 ;
bool gameover = false;

struct point
{
	int x;
	int y;
};
void kill_snake(point arr[])
{
	for (int a = 0; a < tail; a++)
	{
		goto_xy(arr[a].x, arr[a].y);
		cout << " ";
	}
}
void boundries()
{
	int h = 30, w = 30;
	char boundry = 124;
	for (int a = 1; a < h; a++) {
		for (int b = 1; b < w; b++) {
			if (a == 1 || a == w - 1 || b == 1 || b == h - 1)

			{
				cout << boundry;
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	fruitx = 15;
	fruity = 15;
	goto_xy(fruitx, fruity);
	cout << "O";

}
void assign_values(point arr[])
{

	arr[0].x = 11;
	arr[0].y = 11;
	arr[1].x = 11;
	arr[1].y = 12;
	arr[2].x = 11;
	arr[2].y = 13;

}
void moveup(point p[])
{
	int i;
	for (i = 5; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].y = p[i].y - 1;
}
void movedown(point p[])
{
	int i;
	for (i = 5; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].y = p[i].y + 1;
}
void moveleft(point p[])
{

	int i;
	for (i = 5; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].x = p[i].x - 1;
}
void moveright(point p[])
{

	int i;
	for (i = 5; i > 0; i--)
	{
		p[i].x = p[i - 1].x;
		p[i].y = p[i - 1].y;
	}
	p[i].x = p[i].x + 1;

}
void display_S(point arr[])
{

	for (int a = 0; a < tail; a++)
	{
		goto_xy(arr[a].x, arr[a].y);
		cout << "*";
	}
}
int Over(point arr[])
{
	if (arr[0].x > 28 || arr[0].x < 1 || arr[0].y > 27 || arr[0].y < 1)
	{
		gameover = true;
	}
	return 0;
}

void fruit_touch(point p[])

{

	if (fruitx == p[0].x && fruity == p[0].y)
	{
		fruitx = rand() % 12;
		fruity = rand() % 17;
		goto_xy(fruitx, fruity);
		cout << "O";
		tail++;
		score = score + 5;

	}

}

void Input(point p[])
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 75:
			dir = 'l';
			//moveleft(p);
			break;
		case 77:
			dir = 'r';
			// moveright(p);
			break;
		case 72:
			dir = 'u';
			// moveup(p);
			break;
		case 80:
			dir = 'd';
			//movedown(p);
			break;


		}
	}
	switch (dir)
	{
	case 'l':
		moveleft(p);
		break;
	case 'r':
		moveright(p);
		break;
	case 'u':
		moveup(p);
		break;
	case 'd':
		movedown(p);
		break;
	default:
		break;
	}
	Over(p);
	fruit_touch(p);

}


int main()
{
	
	point arr[20];
	char a;
	
	int i = 0;
	point* f;
	boundries();
	assign_values(arr);
	while (!gameover)
	{
		display_S(arr);
		Sleep(200);
		kill_snake(arr);
		Input(arr);
		goto_xy(0, 28);

	}
	
}