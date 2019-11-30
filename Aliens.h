extern "C"{
#include "gfx.h"
}
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
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
       	bounds = {{0}, {0}, {0}, {0}, {0}, {0}};
	}
	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	void printCoords()
	{
		for(auto bound: bounds)
            std::cout << bound[0] << " " << bound[1] << " " << bound[2] << " " << bound[3] << std::endl;
		std::cout << std::endl;
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
        make_bounds();
    }

    void make_bounds()
    {
        bounds[0] = {getX(), getY(), (getX() - 10), getY()};
        bounds[1] = {(getX() - 10), getY(), (getX() - 20), (getY() + 10)};
        bounds[2] = {(getX() - 20), (getY() + 10), getX(), (getY() + 20)};
        bounds[3] = {getX(), (getY() + 20), (getX() + 20), (getY() + 10)};
        bounds[4] = {(getX() + 20), (getY() + 10), (getX() + 10), getY()};
        bounds[5] = {(getX() + 10), getY(), getX(), getY()};
	}

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

	friend bool operator==(const AlienBase&, const AlienBase&);

};

bool operator==(const AlienBase& a, const AlienBase& b)
{
	return a.x==b.x && a.y==b.y && a.move_right == b.move_right;
}

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

class AlienArmy
{
	private:
	int rows;
	int columns;
	public:
	AlienArmy(int r, int c)
	{
		rows = r;
		columns = c;
		build_army();
	}

	void build_army()
	{

		srand(time(0));
		for(int i = 0; i < rows; i++)
		{
			int color = rand() % 3;
			std::cout << color << std::endl;
			add_row(i, color);
		}
	}
	void add_row(int row, int color)
	{
		
		int col_inc = gfx_xsize() / columns;
		if(color == 0)
		{
			std::vector<RedAlien> alien_row;
			for(int i = 0; i < columns; i++)
			{
				RedAlien alien(((col_inc / 2) + col_inc*i),
						row*50 + 25);
				alien.draw_alien();
				alien_row.push_back(alien);
			}
		}
		else if(color == 1)
		{
			std::vector<BlueAlien> alien_row;
			for(int i = 0; i < columns; i++)
			{
				BlueAlien alien(((col_inc / 2) + col_inc*i),
                                                row*50 + 25);
				alien.draw_alien();
				alien_row.push_back(alien);
			}
		}

		else if(color == 2)
		{
			std::vector<GreenAlien> alien_row;
			for(int i = 0; i < columns; i++)
			{
				GreenAlien alien(((col_inc / 2) + col_inc*i),
                                                row*50 + 25);
				alien.draw_alien();
				alien_row.push_back(alien);
			}
		}
	}
};
