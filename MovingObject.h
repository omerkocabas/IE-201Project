#pragma once
#include <stdlib.h>
#include <memory>
using namespace std;
class ShootingGame;
class Hero;
class Bullet;
class Zombie;
class MovingObject
{
protected:
	double x;
	double y;
	double speed;
	double damage;
public:
	MovingObject(double x, double y, double speed, double damage);
	virtual void collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime) {};
	virtual void isCollide(Hero* pHero) = 0;
	virtual void isCollide(Bullet* pBullet) = 0;
	virtual void isCollide(Zombie* pZombie) = 0;
	virtual void draw(ShootingGame* Game) {};
	virtual void move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object) {};
	virtual void getHit(double x) {};
	double distance(double x1, double y1);
	double directionX(double x1);
	double directionY(double y1);
	virtual bool isDead(ShootingGame* Game) { return false; };
};

