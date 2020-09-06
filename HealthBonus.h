#pragma once
#include "Bonus.h"
#include "olcSimpleEngine.h"
#include <memory>
using namespace std;
class ShootingGame;
class Hero;
class Bonus;
class HealthBonus : public Bonus
{
private:
	double healAmount;
	shared_ptr<olc::Sprite> healthSprite = make_shared<olc::Sprite>("Sprites/firstaid.png");
public:
	HealthBonus(double x, double y, ShootingGame* Game, double healAmount);
	void draw();
	bool isCollideBonus(shared_ptr<Hero> pHero);
};