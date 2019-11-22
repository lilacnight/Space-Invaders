#include <cmath>
#include <iostream>
extern "C"{
#include "gfx.h"
}

void draw_polygon(int *x, int *y, int n, bool closed = false)
{
	for(int i = 0; i < n-1; i++)
	{
		gfx_line(x[i], y[i], x[i+1], y[i+1]);
	}
	if(closed)
	{
		gfx_line(x[0], y[0], x[n-1], y[n-1]);
	}
}

void draw_circle(int xc, int yc, int radius)
{
	int x[18];
	int y[18];
	for(int i = 0; i < 18; i++)
	{
		double angle = i*20.0*3.141592654/180;
		x[i] = xc + cos(angle)*radius;
		y[i] = yc + sin(angle)*radius;
	}

	draw_polygon(x, y, 18, true);
}

int main()
{
	gfx_open(500, 500, "Space Potaters");

	int x[] = {30, 50, 23, 17, 120};
	int y[] = {12, 55, 52, 19, 100};

	gfx_color(255, 0, 0);
	draw_polygon(x, y, 5);
	gfx_color(0, 255, 0);
	draw_circle(250, 250, 50);

	while(true)
	{
		if(gfx_event_waiting())
		{
			int button = gfx_wait();
			std::cout << "got event: " << button << std::endl;
			if(button == 'x')
				break;
		}
		else
		{
			//Keep drawing
			//sleep(100);
			std::cout << "Drawing..." << std::endl;
		}
	}
}
