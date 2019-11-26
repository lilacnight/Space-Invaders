#include <iostream>
#include <vector>
#include "BattleShips.h"
#include "Aliens.h"
extern "C"{
#include "gfx.h"
}

using namespace std;
class Game
{
    public:
        int FPS;
        int refreshRate;
        bool running;
        vector <AlienBase> aliens;
        GreenAlien alien1 = GreenAlien (250, 250);

    Game(int fps)
    {
        gfx_open(500, 500, "Space Potaters");
        FPS = fps;
        refreshRate = (1/FPS) * 100000;
        running = true;
    }

    Game()
    {
        gfx_open(500, 500, "Space Potaters");
        FPS = 60;
        refreshRate = (1/FPS) * 1000000;
        running = true;
    }

    void run()
    {
            usleep(16667);
            gfx_clear();
            update();
            draw();
    }

    void update()
    {
        alien1.move();
    }

    void draw()
    {
        alien1.draw_alien();
    }
};
