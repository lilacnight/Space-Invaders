#include <cmath>
#include <unistd.h>
#include "Game.h"
extern "C"{
#include "gfx.h"
}
int main()
{
    Game g(60);
    while(g.running)
    {
        g.run();
    }
    return 0;
}
