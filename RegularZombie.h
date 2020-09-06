#pragma once
#include "Zombie.h"
class Hero;
class Bullet;
class ShootingGame;
class RegularZombie : public Zombie {
private:
	shared_ptr<olc::Sprite> regularSprite = make_shared<olc::Sprite>("Sprites/zombie.png");
public:
	RegularZombie(double x, double y, double speed, double damage, double hpMax, double hpCurrent, double attackCD, double attackRate);
	void isCollide(Hero* pHero);
	void isCollide(Bullet* pBullet) {};
	void isCollide(Zombie* pZombie) {};
	void draw(ShootingGame* Game);
};