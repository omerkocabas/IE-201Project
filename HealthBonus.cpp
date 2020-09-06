#include "ShootingGame.h"
#include "HealthBonus.h"

HealthBonus::HealthBonus(double x, double y, ShootingGame* Game, double healAmount) : Bonus(x, y, Game), healAmount(healAmount) {};
void HealthBonus::draw() {
	Game->DrawSprite(x - 10, y - 10, healthSprite, 1);
}
bool HealthBonus::isCollideBonus(shared_ptr<Hero> pHero) {
	if (pHero->distance(x, y) < 10) {
		pHero->getBonus(healAmount);
		return true;
	}
	else
		return false;
}