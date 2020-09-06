#pragma once
#include "MovingObject.h"
#include "olcSimpleEngine.h"
#include <memory>
class Bonus;
class Zombie;
class Hero : public MovingObject
{
private:
	double hpMax;
	double hpCurrent;
	double currentPoisonTime;
	double totalPoisonDamage;
	double currentArmorTime=0;
	double maxArmorTime=5;
	shared_ptr<olc::Sprite> manSprite = make_shared<olc::Sprite>("Sprites/ManTrans.png");
public:
	Hero(double x, double y, double speed, double damage, double hpMax, double hpCurrent);
	void collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime);
	void isCollide(Hero* pHero) {};
	void isCollide(Bullet* pBullet) {};
	void isCollide(Zombie* pZombie) {};
	void draw(ShootingGame* Game);
	void move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object);
	void getHit(double x);
	void getPoisoned(double poisonTime, double totalDamage);
	void getArmor(double armorTime);
	void poisonDamage(float fElapsedTime);
	void getBonus(double heal);
	void fire(ShootingGame* Game);
	bool isDead(ShootingGame* Game);
	void decreaseArmorTime(float fElapsedTime);
}; 
