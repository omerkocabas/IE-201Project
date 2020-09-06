#pragma once
#include "MovingObject.h"
#include "olcSimpleEngine.h"
#include <iostream>
#include <memory>

class Hero;
class Zombie : public MovingObject
{
protected:
	double hpMax;
	double hpCurrent;
	double attackCD;
	double attackRate;
public:
	Zombie(double x, double y, double speed, double damage, double hpMax, double hpCurrent, double attackCD, double attackRate);
	void collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime);
	virtual void isCollide(Hero* pHero)=0;
	virtual void isCollide(Bullet* pBullet)=0;
	virtual void isCollide(Zombie* pZombie)=0;
	virtual void draw(ShootingGame* Game) {};
	void move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object);
	void getHit(double x);
	void decreaseAttackCD(float fElapsedTime);
	void refreshAttackCD();
	bool isDead(ShootingGame* Game);
}; 
