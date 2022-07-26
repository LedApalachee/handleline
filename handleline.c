#include "handleline.h"

#define HL_ABS(a) ((a) < 0 ? -(a) : (a))

void handleline(int x1, int y1, int x2, int y2, int (*handle_tile)(int, int))
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xsign = dx > 0 ? 1 : -1;
	int ysign = dy > 0 ? 1 : -1;
	dx = HL_ABS(dx);
	dy = HL_ABS(dy);

	int xx, xy, yx, yy;

	if (dx > dy)
	{
		xx = xsign;
		xy = 0;
		yx = 0;
		yy = ysign;
	}
	else
	{
		int t = dx;
		dx = dy;
		dy = t;
		xx = 0;
		xy = ysign;
		yx = xsign;
		yy = 0;
	}

	int D = 2*dy - dx;
	int y = 0;
	int rcode = 0;

	for (int x = 0; x <= dx && rcode != BREAK_HANDLELINE; ++x)
	{
		rcode = handle_tile(x1 + x*xx + y*yx, y1 + x*xy + y*yy);
		if (D >= 0)
		{
			y += 1;
			D -= 2*dx;
		}
		D += 2*dy;
	}
}
