extern "C"{
#include "gfx.h"
}
#include <unistd.h>
#include <vector>
#include <iostream>

class bullet
{
protected:
	bool fromPlayer;
	int x_origin;
	int y_origin;
	int speed;
	bool up;

public:
	bullet(int x, int y, bool up = true, int speed = 5, bool fromPlayer = true)
	{
		x_origin = x;
		y_origin = y;
		up = up;
		speed = speed;
		std::cout << "Bullet Made" << std::endl;
	}
	int y_pos()
	{
		return y_origin;
	}
	void draw_bullet(int x, int y)
	{
		std::cout << "Drawing Bullet..." << std::endl;
		gfx_color(255, 255, 255);
		gfx_line(x, y, x, (y - 50));
	}
	void move()
	{
		if(up)
		{
			y_origin = y_origin - speed * 0.5;
		}
		else
		{
			y_origin = y_origin + speed * 0.5;
		}
		draw_bullet(x_origin, y_origin);
	}
};

class ship_base
{
	protected:
	int x;
	int y;

	public:
	std::vector<bullet> playerbullets;
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

	void fire()
	{
		bullet b(x, y);
		playerbullets.push_back(b);
	}
};
