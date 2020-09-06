#pragma once
#include "Bullet.h"
#include "ShootingGame.h"


Bullet::Bullet(double x, double y, double speed, double damage, double dirX, double dirY) : MovingObject(x, y, speed, damage), dirX(dirX), dirY(dirY) {};
void Bullet::move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object) {
	x += dirX * speed * fElapsedTime;
	y += dirY * speed * fElapsedTime;
}
void Bullet::draw(ShootingGame* Game) {
	Game->DrawCircle(x, y, 1, olc::YELLOW);
}
void Bullet::isCollide(Zombie* pZombie) {
	pZombie->getHit(damage);
	dead = true;
};
bool Bullet::isDead(ShootingGame* Game) {
	if (x < 0 || x > Game->ScreenWidth() || y < 0 || y > Game->ScreenHeight() || dead) {
		return true;
	}
	else
		return false;
}
void Bullet::collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime) {
	if (Object->distance(x, y) < 10) {
		Object->isCollide(this);
	}
}