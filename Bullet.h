#pragma once
#include "MovingObject.h"
#include "Zombie.h"
#include <memory>

class Bullet : public MovingObject
{
private:
	double dirX;
	double dirY;
	bool dead = false;
public:
	Bullet(double x, double y, double speed, double damage, double dirX, double dirY);
	void collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime);
	void isCollide(Hero* pHero) {} ;
	void isCollide(Bullet* pBullet) {};
	void isCollide(Zombie* pZombie);
	void draw(ShootingGame* Game);
	void move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object);
	bool isDead(ShootingGame* Game);
	void getHit(double x) {};
}; 
