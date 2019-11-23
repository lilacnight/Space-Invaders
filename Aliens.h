#include "gfx.h"
#include <iostream>
class AlienBase
{

	protected:
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
	void move_right()
	{
//		gfx_clear();
		x = x + 20;
		draw_base();
	}	
};

class GreenAlien : public AlienBase
{
	public:
	GreenAlien(int xi, int yi) : AlienBase(xi, yi)
	{
	}
	void draw_alien()
	{
		gfx_color(0, 255, 0);
		draw_base();
	}
	void move_right()
	{
//		gfx_clear();
		x = x + 20;
		draw_alien();
	}

};
class RedAlien : public AlienBase
{
	public:
	RedAlien(int xi, int yi) : AlienBase(xi, yi)
	{
	}
	void draw_alien()
	{
		gfx_color(255, 0, 0);
		draw_base();
	}
	void move_right()
	{
//		gfx_clear();
		x = x + 20;
		draw_alien();
	}

};

class BlueAlien : public AlienBase
{
	public:
	BlueAlien(int xi, int yi) : AlienBase(xi, yi)
	{
	}
	void draw_alien()
	{
		gfx_color(0, 0, 255);
		draw_base();
	}
	void move_right()
	{
//		gfx_clear();
		x = x + 20;
		draw_alien();
	}
};
