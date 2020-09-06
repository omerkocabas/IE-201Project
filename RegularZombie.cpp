#include "ShootingGame.h"
#include "RegularZombie.h"
#include "Hero.h"

RegularZombie::RegularZombie(double x, double y, double speed, double damage, double hpMax, double hpCurrent, double attackCD, double attackRate) : Zombie(x, y, speed, damage, hpMax, hpCurrent, attackCD, attackRate) {};
void RegularZombie::isCollide(Hero* pHero) {
	if (attackCD <= 0) {
		pHero->getHit(damage);
		refreshAttackCD();
	}
}

void RegularZombie::draw(ShootingGame* Game) {
	Game->DrawSprite(x - 12, y - 12, regularSprite, 1);
	double ratio = hpCurrent / hpMax;
	for (int i = x - 5; i < 5 + x; ++i)
		if (i < x - 5 + ratio * 10)
			Game->DrawRect(i, y + 14, 1, 1, olc::GREEN);
		else
			Game->DrawRect(i, y + 14, 1, 1, olc::RED);
}