#include "olcSimpleEngine.h"
#include "olcPGEX_Graphics2D.h"
#include "vector"
#include "ShootingGame.h"
using namespace std;


int main()
{
    ShootingGame demo;
    if (demo.Construct(240, 240, 3, 3))
        demo.Start();

    return 0;
}