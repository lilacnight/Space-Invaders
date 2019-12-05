extern "C"{
#include "gfx.h"
}
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>

std::vector<int> cycleColors(int r, int g, int b)
{
	std::vector<int> rgb = {255, 0, 0};
	if ((rgb[0] == 255) && (rgb[1] < 255) && (rgb[2] == 0))
        rgb[1] += 1;
    if ((rgb[0] > 0) && (rgb[1] == 255) && (rgb[2] == 0))
        rgb[0] -= 1;
    if ((rgb[0] == 0) && (rgb[1] == 255) && (rgb[2] < 255))
        rgb[2] += 1;
    if ((rgb[0] == 0) && (rgb[1] > 0) && (rgb[2] == 255))
        rgb[1] -= 1;
    if ((rgb[0] < 255) && (rgb[1] == 0) && (rgb[2] == 255))
        rgb[0] += 1;
    if ((rgb[0] == 255) && (rgb[1] == 0) && (rgb[2] > 0))
        rgb[2] -= 1;
    return rgb;
}

class AlienBase
{
	protected:
	int x;
	int y;

	public:
	bool move_right;
	bool isDead;
    std::vector<std::vector<int>> bounds;
	AlienBase(int xi, int yi)
	{
		x = xi;
		y = yi;
		move_right = true;
       	bounds = {{0}, {0}, {0}, {0}, {0}, {0}};
       	isDead = false;
	}
	const int& x_val() const
	{
		return x;
	}
	const int& y_val() const
	{
		return y;
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

	virtual void move()
	{
		if(!isDead)
		{	
			if(move_right)
			{
				x = x + 1;
			}
			
			else
				x = x -1;

		    draw_alien();
			make_bounds();
		}
	}
	
	void move_down()
	{
		y = y + 20;
		switchDir();
		move();
	}
	
	void switchDir()
	{
		move_right = !move_right;
	}
	
	bool hit_side()
	{
		return((x > gfx_xsize()) || (x < 0));
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

	void remove_bounds()
	{
		bounds.clear();
	}
	friend bool operator==(const AlienBase&, const AlienBase&);

};

bool operator==(const AlienBase& a, const AlienBase& b)
{
	return a.x==b.x && a.y==b.y && a.move_right == b.move_right;
}

class Mother : public AlienBase
{
	private:
	float yPos;
	float xPos;
	public:
	std::vector<int> color;
	Mother(int xi, int yi) : AlienBase(xi, yi)
	{
		color = {255, 0, 0};
		yPos = y;
	}
	
	void cycleColors()
	{
		if ((color[0] == 255) && (color[1] < 255) && (color[2] == 0))
			color[1] += 15;
		if ((color[0] > 0) && (color[1] == 255) && (color[2] == 0))
			color[0] -= 15;
		if ((color[0] == 0) && (color[1] == 255) && (color[2] < 255))
			color[2] += 15;
		if ((color[0] == 0) && (color[1] > 0) && (color[2] == 255))
			color[1] -= 15;
		if ((color[0] < 255) && (color[1] == 0) && (color[2] == 255))
			color[0] += 15;
		if ((color[0] == 255) && (color[1] == 0) && (color[2] > 0))
			color[2] -= 15;
	}
	
	void draw_alien() override
	{
		cycleColors();
		gfx_color(color[0], color[1], color[2]);
		draw_base();
	}
	
	void move() override
	{
		if(!isDead)
		{	
			if(x < gfx_xsize())
			{
				xPos = xPos + 2.5f;
				yPos = yPos+std::sin(x/10) * 3.5f;
				y = (int)yPos;
				x = (int)xPos;
				draw_alien();
				make_bounds();
			}
		}
	}
	void kill()
	{
		isDead = true;
		remove_bounds();
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

class BasicAlien : public AlienBase
{

	public:
	int color;
	BasicAlien(int xi, int yi, const int& c) : AlienBase(xi, yi)
	{
		color = c;
	}
	void draw_alien() override
	{
//		std::cout << color << std::endl;
		if(color == 0)
		{
			gfx_color(255, 0 , 0);
//			std::cout << "red" << std::endl;
		}
		else if(color == 1)
		{
			gfx_color(0, 0, 255);
//			std::cout << "blue" << std::endl;
		}
		else if(color == 2)
		{
			gfx_color(0, 255, 0);
//			std::cout << "green" << std::endl;
		}
		else if(color == 3)
		{
			gfx_color(0, 0, 0);
		}
		draw_base();
	}
};


class AlienArmy
{
	private:
	int rows;
	int columns;
	std::vector<std::vector<BasicAlien*>> alien_array;
	public:
	AlienArmy(int r, int c)
	{
		rows = r;
		columns = c;
		build_army();
	}
	
	size_t size()
	{
		return alien_array.size();
	}

	void build_army()
	{

		int col_inc = gfx_xsize() / columns;
		srand(time(0));
		for(int i = 0; i < rows; i++)
		{
			std::vector<BasicAlien*> alien_row;
			for(int z = 0; z < columns; z-=-1)
			{
				unsigned int color = rand() % 3;
				/*BasicAlien alien(((col_inc / 2) + col_inc*z),
						(i*50 + 25), color);*/
				//alien.draw_alien();
				alien_row.push_back(new BasicAlien (((col_inc / 2) + col_inc*z),(i*50 + 25), color));
			}
			alien_array.push_back(alien_row);
		}
	}
	
	void move_army()
	{
		bool side_hit = false;
		for(auto rows: alien_array)
		{
			for(auto alien: rows)
			{
				alien->move();
				if(alien->hit_side())
				{
					side_hit = true;
					break;
				}
			}
			if(side_hit)
				break;
		}
		
		if(side_hit)
		{
			for(auto rows: alien_array)
			{
				for(auto alien:rows)
					alien->move_down();
			}
			side_hit = false;
		}
	}

	void pop_alien(BasicAlien* alien)
	{
		for(auto row: alien_array)
		{
			for(int i = 0; i < row.size(); i++)
			{
				if(row[i] == alien)
				{
					row[i]->color = 3;
					if(alien->isDead == false)
						alien->remove_bounds();
					alien->isDead = true;
					//row.erase(row.begin() + i);
					//std::cout << row.size();
					return;
				}
			}
		}
	}
	
	std::vector<BasicAlien*> operator[](size_t index)
	{
		return alien_array.at(index);
	}
};
