#pragma once
#include "olcPGEX_Graphics2D.h"
#include "algorithm"
#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <memory>
#include "Bonus.h"
#include "Hero.h"
#include "ArmorBonus.h"
#include "HealthBonus.h"
#include "Bullet.h"
#include "RegularZombie.h"
#include "PoisonZombie.h"
#include "Background.h"
#include <vector>

using namespace std;

class ShootingGame : public olc::PixelGameEngine
{
protected:
	bool gameEnd;
	double spawnCD;
	double spawnRate;
	shared_ptr<Hero> pHero;
	shared_ptr<Background> pBackground;
	vector<shared_ptr<Bonus>> bonuses;
	vector<shared_ptr<MovingObject>> movingobjects;
public:
	void createzombies();
	void createbullets(double x, double y, double dirX, double dirY, double dist);
	void createbonus(double x, double y);
	bool OnUserCreate();
	bool OnUserUpdate(float fElapsedTime);
}; 
