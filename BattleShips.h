extern "C"{
#include "gfx.h"
}
#include <unistd.h>
#include <vector>
#include <iostream>

class bullet
{
protected:
	int x_pos;
	int y_pos;
	int speed;
	bool up;

public:
	bullet(int x, int y, bool up = true, int speed = 4)
	{
		x_pos = x;
		y_pos = y;
		up = up;
		speed = speed;
		std::cout << "Bullet Made" << std::endl;
	}
	int getY()
	{
		return y_pos;
	}
	void draw()
	{
		gfx_color(255, 255, 255);
		gfx_line(x_pos, y_pos, x_pos, y_pos - 10);
	}
	void move()
	{
        std::cout << y_pos << std::endl;
		y_pos = y_pos - 5;
        std::cout << y_pos << std::endl;
		draw();
	}
    void update()
    {
        move();
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
        bullet b(x, y-2);
		playerbullets.push_back(b);
	}
};
