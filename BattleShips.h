extern "C"{
#include "gfx.h"
}
#include <unistd.h>
class ship_base
{
	protected:
	int x;
	int y;
	
	public:
	ship_base()
	{
		x = 20;
		y = gfx_ysize() - 30;
	}
	int x_val()
	{
		return x;
	}
	int y_val()
	{
		return y;
	}
	void draw_base()
	{
		gfx_color(255, 0, 255);
		gfx_line(x, y, x - 10, y + 20);
		gfx_line(x - 10, y + 20, x + 10, y + 20);
		gfx_line(x + 10, y + 20, x, y);
	}
	virtual void draw_ship()
	{
		draw_base();
	}
	void move_right()
	{
		if(!(x + 17 > gfx_xsize()))
			x = x + 6;
			draw_ship();
	}
	void move_left()
	{
		if(!(x - 17 <= 0))
			x = x - 6;
			draw_ship();
	}
			
};

class bullet
{
	protected:
	int x_orgin;
	int y_orgin;
	int speed;
	bool up;
	
	public:
	bullet(int x, int y, bool up = true, int speed = 5)
	{
		x_orgin = x;
		y_orgin = y;
		up = up; 
		speed = speed;
	}
	int y_pos()
	{
		return y_orgin;
	}
	void move()
	{
		if(up)
		{
			y_orgin = y_orgin - speed;
			gfx_line(x_orgin, y_orgin, x_orgin, (y_orgin - 10));
		}
		else
		{
			y_orgin = y_orgin + speed;
			gfx_line(x_orgin, y_orgin, x_orgin,(y_orgin + 10));
		}
	}
};
