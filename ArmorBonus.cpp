#include "ShootingGame.h"
#include "ArmorBonus.h"

ArmorBonus::ArmorBonus(double x, double y, ShootingGame* Game, double armorTime) : Bonus(x, y, Game), armorTime(armorTime) {};
void ArmorBonus::draw() {
	Game->DrawSprite(x - 10, y - 10, armorSprite, 1);
}
bool ArmorBonus::isCollideBonus(shared_ptr<Hero> pHero) {
	if (pHero->distance(x, y) < 10) {
		pHero->getArmor(armorTime);
		return true;
	}
	else
		return false;
}