#include "ShootingGame.h"
#include "PoisonZombie.h"
#include "Hero.h"

PoisonZombie::PoisonZombie(double x, double y, double speed, double damage, double hpMax, double hpCurrent, double attackCD, double attackRate, double poisonTime) : Zombie(x, y, speed, damage, hpMax, hpCurrent, attackCD, attackRate), poisonTime(poisonTime) {};


void PoisonZombie::isCollide(Hero* pHero) {
	if (attackCD <= 0) {
		refreshAttackCD();
		pHero->getPoisoned(poisonTime, damage);
	}
}

void PoisonZombie::draw(ShootingGame* Game) {
	Game->DrawSprite(x - 12, y - 12, poisonSprite, 1);
	double ratio = hpCurrent / hpMax;
	for (int i = x - 5; i < 5 + x; ++i)
		if (i < x - 5 + ratio * 10)
			Game->DrawRect(i, y + 14, 1, 1, olc::GREEN);
		else
			Game->DrawRect(i, y + 14, 1, 1, olc::RED);
}