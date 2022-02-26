#include "handleline.h"


void handleline(int x1, int y1, int x2, int y2, long long int (*handle_tile)(int, int))
{
	if (x1 == x2 && y1 == y2) goto nodir;
	if (x1 == x2)
	{
		if (y1 < y2) goto N;
		else goto S;
	}
	if (y1 == y2)
	{
		if (x1 < x2) goto E;
		else goto W;
	}
	if (x1 < x2)
	{
		if (y1 < y2)
		{
			if (x2-x1 == y2-y1) goto NE;
			if (x2-x1 > y2-y1) goto NEE;
			else goto NNE;
		}
		else
		{
			if (x2-x1 == y1-y2) goto SE;
			if (x2-x1 > y1-y2) goto SEE;
			else goto SSE;
		}
	}
	else
	{
		if (y1 < y2)
		{
			if (x1-x2 == y2-y1) goto NW;
			if (x1-x2 > y2-y1) goto NWW;
			else goto NNW;
		}
		else
		{
			if (x1-x2 == y1-y2) goto SW;
			if (x1-x2 > y1-y2) goto SWW;
			else goto SSW;
		}
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
	for (int x = x1, y = y1; x >= x2; --x)
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
	for (int x = x1, y = y1; y <= y2; ++y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			x--;
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

W:
	for (int x = x1; x >= x2; --x)
	{
		returning_value = handle_tile(x,y1);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

SWW:
	dx = x1 - x2;
	dy = y1 - y2;
	D = dy * 2 - dx;
	for (int x = x1, y = y1; x >= x2; --x)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			y--;
			D -= dx * 2;
		}
		D += dy * 2;
	}
	return;

SW:
	for (int x = x1, y = y1; x >= x2; --x, --y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

SSW:
	dx = x1 - x2;
	dy = y1 - y2;
	D = dx * 2 - dy;
	for (int x = x1, y = y1; y >= y2; --y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			x--;
			D -= dy * 2;
		}
		D += dx * 2;
	}
	return;

S:
	for (int y = y1; y >= y2; --y)
	{
		returning_value = handle_tile(x1,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

SSE:
	dx = x2 - x1;
	dy = y1 - y2;
	D = dx * 2 - dy;
	for (int x = x1, y = y1; y >= y2; --y)
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

SE:
	for (int x = x1, y = y1; x <= x2; ++x, --y)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
	}
	return;

SEE:
	dx = x2 - x1;
	dy = y1 - y2;
	D = dy * 2 - dx;
	for (int x = x1, y = y1; x <= x2; ++x)
	{
		returning_value = handle_tile(x,y);
		if (returning_value == BREAK_HANDLING_LINE) break;
		if (D > 0)
		{
			y--;
			D -= dx * 2;
		}
		D += dy * 2;
	}
	return;
}