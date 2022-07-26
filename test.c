#include <stdio.h>
#include <stdlib.h>
#include "handleline.h"


#define mapsizeX 11
#define mapsizeY 11
char map[mapsizeX][mapsizeY];

void drawmap();
void initmap();
void clearmap();


int handle_tile(int x, int y)
{
	map[x][y] = '#';
}


int main(int argc, char** argv)
{
	//if (argc < 5) return 0;

	initmap();

	int x1, y1;
	int x2, y2;

	x1 = x2 = mapsizeX/2;
	y1 = y2 = mapsizeY/2;

	char quit = 0;
	while(!quit)
	{
		drawmap();

		switch (getchar())
		{
			case 'q':
				quit = 1;
				break;

			case 'w':
				if (y1 < mapsizeY-1) y1++;
				break;

			case 's':
				if (y1 >= 1) y1--;
				break;

			case 'a':
				if (x1 >= 1) x1--;
				break;

			case 'd':
				if (x1 < mapsizeX-1) x1++;
				break;

			case '8':
				if (y2 < mapsizeY-1) y2++;
				break;

			case '2':
				if (y2 >= 1) y2--;
				break;

			case '4':
				if (x2 >= 1) x2--;
				break;

			case '6':
				if (x2 < mapsizeX-1) x2++;
		}

		clearmap();
		handleline(x1,y1, x2,y2, &handle_tile);
	}

	return 0;
}


void initmap()
{
	for (int x = 0; x < mapsizeX; ++x)
		for (int y = 0; y < mapsizeY; ++y)
			map[x][y] = '.';
}


void drawmap()
{
	for (int y = 0; y < mapsizeY; ++y)
	{
		for (int x = 0; x < mapsizeX; ++x)
			putchar(map[x][mapsizeY - y - 1]);
		putchar('\n');
	}
}


void clearmap()
{
	for (int x = 0; x < mapsizeX; ++x)
		for (int y = 0; y < mapsizeY; ++y)
			map[x][y] = '.';
}