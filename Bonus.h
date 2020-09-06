#pragma once
#include "olcSimpleEngine.h"
#include <stdlib.h>
#include <memory>
using namespace std;
class ShootingGame;
class Hero;
class Bonus
{
protected:
	ShootingGame* Game;
	double x;
	double y;
public:
	Bonus(double x, double y, ShootingGame* Game);
	virtual void draw()=0;
	virtual bool isCollideBonus(shared_ptr<Hero> pHero)=0;
};

