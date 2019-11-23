extern "C"{
#include "gfx.h"
}
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
