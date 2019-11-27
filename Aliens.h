extern "C"{
#include "gfx.h"
}
#include <iostream>
#include <vector>
class AlienBase
{

	protected:
	int x;
	int y;
	bool move_right;

	public:
    std::vector<std::vector<int>> bounds;
	AlienBase(int xi, int yi)
	{
		x = xi;
		y = yi;
		move_right = true;
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

        bounds[0] = {x, y, (x-10), y};
        bounds[1] = {(x - 10), y, (x - 20), (y + 10)};
		bounds[2] = {(x - 20), (y + 10), x, (y + 20)};
		bounds[3] = {x, (y + 20), (x + 20), (y + 10)};
		bounds[4] = {(x + 20), (y + 10), (x + 10), y};
		bounds[5] = {(x + 10), y, x, y};
	}
	virtual void draw_alien()
	{
	}
	void move()
	{
		if (x > gfx_xsize())
		{
			y = y + 20;
			move_right = false;
		}
		else if (x < 0)
		{
			y = y + 20;
			move_right = true;
		}
		if(move_right)
		{
			x = x + 1;
		}
		else
			x = x -1;
		draw_alien();
	}

};

class GreenAlien : public AlienBase
{
	public:
	GreenAlien(int xi, int yi) : AlienBase(xi, yi)
	{
	}
	void draw_alien() override
	{
		gfx_color(0, 255, 0);
		draw_base();
	}

};
class RedAlien : public AlienBase
{
	public:
	RedAlien(int xi, int yi) : AlienBase(xi, yi)
	{
	}
	void draw_alien() override
	{
		gfx_color(255, 0, 0);
		draw_base();
	}

};

class BlueAlien : public AlienBase
{
	public:
	BlueAlien(int xi, int yi) : AlienBase(xi, yi)
	{
	}
	void draw_alien() override
	{
		gfx_color(0, 0, 255);
		draw_base();
	}
};
