extern "C"{
#include "gfx.h"
}
#include <unistd.h>
#include <vector>
#include <iostream>
#include <string>

class bullet
{
protected:
	int x_pos;
	double y_pos;
	int y_vel;
	bool up;
	int enabled;

public:


    std::vector<int> bounds;
	bullet(int x, int y, bool up = true, int speed = 30)
	{
		x_pos = x;
		y_pos = y;
		up = up;
		y_vel = speed;
        	bounds = {0};
		enabled = 1;
	}
	int getY()
	{
		return y_pos;
	}
	void draw()
	{
	//	std::cout << enabled << " , ";
		gfx_color(255, 255, 255);
		gfx_line(x_pos, y_pos, x_pos, y_pos - 10);
		bounds.clear();
       		bounds.push_back(x_pos);
     		bounds.push_back((int)y_pos);
    		bounds.push_back(x_pos);
		bounds.push_back((int)(y_pos-10));
	}
	void move(double dt)
	{
		y_pos -= y_vel * dt;
		draw();
	}
    void update(float dt)
    {
        move(dt);
    }
};

class ship_base
{
	protected:
	int x;
	int y;

	public:
	float dt;
	float acc;
    	float vel;
	std::vector<bullet> playerbullets;
    	std::vector<std::vector<int>> bounds;
	
	ship_base()
	{
		x = 20;
		y = gfx_ysize() - 30;
		vel = 60.0f;
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

        	std::vector<int> bound = {x, y, x - 10, y + 20};
        	bounds.push_back(bound);
        	bound.clear();
        	bound = {x - 10, y + 20, x + 10, y + 20};
        	bounds.push_back(bound);
        	bound.clear();
        	bound = {x + 10, y + 20, x, y};
        	bounds.push_back(bound);
        	bound.clear();

	}

	virtual void draw_ship()
	{
		draw_base();
	}

	void move(std::string dir, double dt)
	{
        	if(dir == "R")
        	{
		    	if(!(x + 17 > gfx_xsize()))
			    	x += (vel * dt) + 3;
        	}
        	else if(dir == "L")
        	{
            		if(!(x - 17 <= 0))
    				x -= (vel * dt) + 3;
        	}

		draw_ship();        
	}

	void coll()
	{
		bullet b(x,y*-1);
		playerbullets[0] = b;
	}

	void fire()
	{
        	bullet b(x, y-2);
		playerbullets.push_back(b);
	}
};
