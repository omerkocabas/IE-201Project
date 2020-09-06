#pragma once
#include "Hero.h"
#define PI 3.14159265359
#include "ShootingGame.h"
#include "Bonus.h"
#include "Zombie.h"

Hero::Hero(double x, double y, double speed, double damage, double hpMax, double hpCurrent) : MovingObject(x, y, speed, damage), hpMax(hpMax), hpCurrent(hpCurrent) {};
void Hero::move(float fElapsedTime, ShootingGame* Game, shared_ptr<MovingObject> Object) {
	if (Game->GetKey(olc::W).bHeld) {
		y -= fElapsedTime * speed;
		if (y <= 0) { y = 0; }
		if (y >= Game->ScreenHeight() - 1) { y = Game->ScreenHeight() - 1; }
	}
	if (Game->GetKey(olc::A).bHeld) {
		x -= fElapsedTime * speed;
		if (x <= 0) { x = 0; }
		if (x >= Game->ScreenWidth() - 1) { x = Game->ScreenWidth() - 1; }
	}
	if (Game->GetKey(olc::S).bHeld) {
		y += fElapsedTime * speed;
		if (y <= 0) { y = 0; }
		if (y >= Game->ScreenHeight() - 1) { y = Game->ScreenHeight() - 1; }
	}
	if (Game->GetKey(olc::D).bHeld) {
		x += fElapsedTime * speed;
		if (x <= 0) { x = 0; }
		if (x >= Game->ScreenWidth() - 1) { x = Game->ScreenWidth() - 1; }
	}
}

void Hero::getBonus(double heal) {
	currentPoisonTime = 0;
	if (hpCurrent + heal < hpMax)
	{
		hpCurrent += heal;
	}
	else
	{
		hpCurrent = hpMax;
	}
}
void Hero::getHit(double x) {
	if (currentArmorTime <= 0) {
		hpCurrent -= x;
	}

}

void Hero::getPoisoned(double poisonTime, double totalDamage) {
	currentPoisonTime = poisonTime;
	totalPoisonDamage = totalDamage;
}

void Hero::poisonDamage(float fElapsedTime) {
	currentPoisonTime -= fElapsedTime;
	if (currentArmorTime <= 0) {
		if (currentPoisonTime >= 0) {
			hpCurrent -= totalPoisonDamage * fElapsedTime;
		}
	}
	
}

void Hero::getArmor(double armorTime) {
	maxArmorTime = armorTime;
	currentArmorTime = armorTime;
}

void Hero::decreaseArmorTime(float fElapsedTime) {
	currentArmorTime -= fElapsedTime;
}

void Hero::collisionCheck(shared_ptr<MovingObject> Object, float fElapsedTime) {
	if (Object->distance(x, y) < 10) {
		Object->isCollide(this);
	}
}

void Hero::fire(ShootingGame* Game) {
	if (Game->GetKey(olc::SPACE).bPressed) {
		double dirX = Game->GetMouseX() - x;
		double dirY = Game->GetMouseY() - y;
		double dist = sqrt((dirX * dirX) + (dirY * dirY));
		Game->createbullets(x, y, dirX, dirY, dist);
	}
}

bool Hero::isDead(ShootingGame* Game) {
	if (hpCurrent <= 0 || Game->GetKey(olc::E).bReleased) {
		return true;
	}
	else
		return false;
}
void Hero::draw(ShootingGame* Game) {
	olc::GFX2D::Transform2D t;
	t.Translate(-manSprite->width / 2, -manSprite->height / 2);
	t.Rotate(atan2((Game->GetMouseX() - x), (Game->GetMouseY() - y)) - PI / 2);
	t.Translate(x, y);
	olc::GFX2D::DrawSprite(manSprite.get(), t);
	double ratio = hpCurrent / hpMax;

	for (int i = x - 5; i < 5 + x; ++i)
		if (i < x - 5 + ratio * 10)
			Game->DrawRect(i, y + 14, 1, 1, olc::GREEN);
		else
			Game->DrawRect(i, y + 14, 1, 1, olc::RED);

	double ratio2 = currentArmorTime / maxArmorTime;
	for (int i = x - 5; i < (5 + x); ++i)
		if (i < x - 5 + ratio2 * 10)
			Game->DrawRect(i, y + 19, 1, 1, olc::YELLOW);
		else
			Game->DrawRect(i, y + 19, 1, 1, olc::WHITE);


	Game->DrawLine(Game->GetMouseX() - 5, Game->GetMouseY(), Game->GetMouseX() + 5, Game->GetMouseY(), olc::RED);
	Game->DrawLine(Game->GetMouseX(), Game->GetMouseY() - 5, Game->GetMouseX(), Game->GetMouseY() + 5, olc::RED);
}