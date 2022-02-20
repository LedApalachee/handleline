#include "handleline.h"

void swap(int* n1, int* n2)
{
	int t = *n1;
	*n1 = *n2;
	*n2 = t;
}


void handleline(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, long long int (*handle_tile)(int, int))
{
	if (x1 == x2 && y1 == y2) goto nodir;
	else if (y1 > y2 || (y1 == y2 && x1 > x2))
	{
		swap(&x1, &x2);
		swap(&y1, &y2);
	}
	if (y1 == y2) goto E;
	else if (x1 == x2) goto N;
	else if (x1 < x2)
	{
		if ((y2-y1)/(x2-x1) < 1) goto NEE;
		else if (y2-y1 == x2-x1) goto NE;
		else goto NNE;
	}
	else
	{
		if ((y2-y1)/(x1-x2) < 1) goto NWW;
		else if (y2-y1 == x1-x2) goto NW;
		else goto NNW;
	}


int dx, dy, D;
char returning_value;

nodir:
	returning_value = handle_tile(x1,y1);
	return;


NWW:
	dx = x1 - x2;
	dy = y2 - y1;
	D = dy * 2 - dx;
	for (int x = x2, y = y1; x <= x1; ++x)
	{
		returning_value = handle_tile(x1-x+x2, y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			y++;
			D -= dx * 2;
		}
		D += dy * 2;
	}
	return;

NW:
	for (int x = x1, y = y1; x >= x2 && x >= 0; --x, ++y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

NNW:
	dx = x1 - x2;
	dy = y2 - y1;
	D = dx * 2 - dy;
	for (int x = x2, y = y1; y <= y2; ++y)
	{
		returning_value = handle_tile(x1-x+x2, y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			x++;
			D -= dy * 2;
		}
		D += dx * 2;
	}
	return;

N:
	for (int y = y1; y <= y2; ++y)
	{
		returning_value = handle_tile(x1,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

NNE:
	dx = x2 - x1;
	dy = y2 - y1;
	D = dx * 2 - dy;
	for (int x = x1, y = y1; y <= y2; ++y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			x++;
			D -= dy * 2;
		}
		D += dx * 2;
	}
	return;

NE:
	for (int x = x1, y = y1; x <= x2; ++x, ++y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

NEE:
	dx = x2 - x1;
	dy = y2 - y1;
	D = dy * 2 - dx;
	for (int x = x1, y = y1; x <= x2; ++x)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			y++;
			D -= dx * 2;
		}
		D += dy * 2;
	}
	return;


E:
	for (int x = x1; x <= x2; ++x)
	{
		returning_value = handle_tile(x,y1);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;
}