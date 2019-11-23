#include "gfx.h"
#include <iostream>
class AlienBase
{
	private:
	int x;
	int y;

	public:
	AlienBase(int xi, int yi)
	{
		x = xi;
		y = yi;
	}
	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	void draw_base()
	{
		gfx_line(x, y, (x - 10), y);
		gfx_line((x - 10), y, (x - 20), (y + 10));
		gfx_line((x - 20), (y + 10), x, (y + 20));
		gfx_line(x, (y + 20), (x + 20), (y + 10));
		gfx_line((x + 20), (y + 10), (x + 10), y);
		gfx_line((x + 10), y, x, y);
	}	
};
