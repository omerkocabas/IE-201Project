#pragma once
#include "Bonus.h"
#include "olcSimpleEngine.h"
#include <memory>
using namespace std;
class ShootingGame;
class Hero;
class Bonus;
class ArmorBonus : public Bonus
{
private:
	double armorTime;
	shared_ptr<olc::Sprite> armorSprite = make_shared<olc::Sprite>("Sprites/armor.png");
public:
	ArmorBonus(double x, double y, ShootingGame* Game, double armorTime);
	void draw();
	bool isCollideBonus(shared_ptr<Hero> pHero);
};