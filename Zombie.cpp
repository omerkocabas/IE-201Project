#pragma once
#include "ShootingGame.h"
#include "Zombie.h"
#include "Hero.h"


Zombie::Zombie(double x, double y, double speed, double damage, double hpMax, double hpCurrent, double attackCD, double attackRate) : MovingObject(x, y, speed, damage), hpMax(hpMax), hpCurrent(hpCurrent), attackCD(attackCD), attackRate(attackRate) {};
void Zombie::move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object) {
	double dirX = Object->directionX(x);
	double dirY = Object->directionY(y);
	double dist = sqrt((dirX * dirX) + (dirY * dirY));
	x += dirX / dist * speed * fElapsedTime;
	y += dirY / dist * speed * fElapsedTime;
}
void Zombie::getHit(double x) {
	hpCurrent -= x;
}
void Zombie::decreaseAttackCD(float fElapsedTime) {
	attackCD -= fElapsedTime;
}
void Zombie::refreshAttackCD() {
	attackCD = attackRate;
}
void Zombie::collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime) {
	decreaseAttackCD(fElapsedTime);
	if (Object->distance(x,y) < 10) {
		Object->isCollide(this);
	}
}

bool Zombie::isDead(ShootingGame* Game) {
	if (hpCurrent <= 0) {
		if (rand() % 5 < 1)
			Game->createbonus(x, y);
		return true;
	}
	else
		return false;
}