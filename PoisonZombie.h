#pragma once
#include "Zombie.h"

class PoisonZombie : public Zombie {
private:
	double poisonTime;
	shared_ptr<olc::Sprite> poisonSprite = make_shared<olc::Sprite>("Sprites/poison.png");
public:
	PoisonZombie(double x, double y, double speed, double damage, double hpMax, double hpCurrent, double attackCD, double attackRate, double poisonTime);
	void isCollide(Hero* pHero);
	void isCollide(Bullet* pBullet) {};
	void isCollide(Zombie* pZombie) {};
	void draw(ShootingGame* Game);
};
