#include <cmath>
#include <unistd.h>
#include <iostream>
extern "C"{
#include "gfx.h"
}
#include "Aliens.h"
#include "BattleShips.h"
#include <vector>
int main()
{
	gfx_open(500, 500, "Space Potaters");

	int x[] = {30, 50, 23, 17, 120};
	int y[] = {12, 55, 52, 19, 100};

	//gfx_color(255, 0, 0);
	//draw_polygon(x, y, 5);
	gfx_color(0, 255, 0);
	//draw_circle(250, 250, 50);

	GreenAlien alien1(250, 250);
	alien1.print();
	alien1.draw_alien();
	RedAlien alien2(100, 50);
	alien2.draw_alien();
	BlueAlien alien3(200, 50);
	alien3.draw_alien();
	ship_base ship;
	ship.draw_base();

	std::vector<bullet> bullet_list;


	while(true)
	{
		if(gfx_event_waiting())
		{
			int button = gfx_wait();
			// left arrow
			if (button == 81 || button == 65430 || button == 65361)
			{
			//	gfx_clear();
				ship.move_left();
			}
			// right arrow
			if (button == 83 || button == 65432 || button == 65363)
			{
			//	gfx_clear();
				ship.move_right();
			}
			if (button == 82 || button == 65431 || button == 65362)
			{
				ship.fire();
			}
			std::cout << "got event: " << button << std::endl;
			if(button == 27)
				break;
		}
		else
		{
			usleep(16667);
			gfx_clear();
			alien1.move();
			alien2.move();
			alien3.move();
			ship.draw_base();
			for(int i = 0; i < ship.playerbullets.size(); i++)
			{
				ship.playerbullets[i].move();
                if(ship.playerbullets[i].getY() < 0)
                {
                    ship.playerbullets.erase(ship.playerbullets.begin() + i);
                    std::cout << "Bullet deleted" << std::endl;
                }
			}
		}


	}
}
