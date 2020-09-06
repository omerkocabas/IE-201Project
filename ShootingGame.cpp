#pragma once
#include "ShootingGame.h"

void ShootingGame::createzombies() {
	if (spawnCD <= 0) {
		double degree = rand() * 360;
		if (rand() % 2 == 1) {
			shared_ptr<PoisonZombie> pZ = make_shared<PoisonZombie>((cos(degree) * ScreenWidth()) + (ScreenWidth() / 2), (sin(degree) * ScreenHeight()) + (ScreenHeight() / 2), 50, 1, 10, 10, 0, 2, 10);
			movingobjects.push_back(pZ);
		}
		else {
			shared_ptr<RegularZombie> pZ = make_shared<RegularZombie>((cos(degree) * ScreenWidth()) + (ScreenWidth() / 2), (sin(degree) * ScreenHeight()) + (ScreenHeight() / 2), 50, 10, 10, 10, 0, 2);
			movingobjects.push_back(pZ);
		}
		spawnCD = spawnRate;
	}
}
void ShootingGame::createbullets(double x, double y, double dirX, double dirY, double dist) {
	shared_ptr<Bullet> pB = make_shared<Bullet>(x, y, 200, 1, dirX / dist, dirY / dist);
	movingobjects.push_back(pB);
}
void ShootingGame::createbonus(double x, double y) {
	if (rand() % 2 == 1) {
		shared_ptr<HealthBonus> pB = make_shared<HealthBonus>(x, y, this, 20);
		bonuses.push_back(pB);
	}
	else {
		shared_ptr<ArmorBonus> pB = make_shared<ArmorBonus>(x, y, this, 5);
		bonuses.push_back(pB);
	}
}

bool ShootingGame::OnUserCreate() {
	pHero = make_shared<Hero>(ScreenWidth() / 2, ScreenHeight() / 2, 100, 1, 100, 50);
	movingobjects.push_back(pHero);
	pBackground = make_shared<Background>();
	gameEnd = false;
	spawnRate = 5;
	spawnCD = 0;
	srand(NULL);
	return true;
}
bool ShootingGame::OnUserUpdate(float fElapsedTime) {
	if (gameEnd) {
		pBackground->drawEnding(this);
		if (GetKey(olc::Key::Y).bPressed)
		{
			OnUserCreate();
		}
		if (GetKey(olc::Key::N).bPressed)
			return false;
		return true;
	}
	pBackground->changeLevel(fElapsedTime);
	spawnCD -= fElapsedTime;
	createzombies();
	pHero->fire(this);
	for (auto a : movingobjects) {
		a->move(fElapsedTime, this, pHero);
	}
	for (int i = 0; i < movingobjects.size(); i++) {
		for (int j = 0; j < movingobjects.size(); j++) {
			if (i == j) j++;
			if (j == movingobjects.size()) break;
			movingobjects[i]->collisionCheck(movingobjects[j], fElapsedTime);
			if (movingobjects[i]->isDead(this)) {
				movingobjects.erase(movingobjects.begin() + i);
				i--;
				break;
			}
			if (movingobjects[j]->isDead(this)) {
				movingobjects.erase(movingobjects.begin() + j);
				j--;
			}
		}
	}
	pHero->poisonDamage(fElapsedTime);
	pHero->decreaseArmorTime(fElapsedTime);
	if (pHero->isDead(this)) {
		for (int i = 0; i < movingobjects.size(); i++) {
			movingobjects.erase(movingobjects.begin() + i);
			i--;
		}
		for (int i = 0; i < bonuses.size(); i++) {
			bonuses.erase(bonuses.begin() + i);
			i--;
		}
		gameEnd = true;
	}
	for (int i = 0; i < bonuses.size(); i++) {
		if (bonuses[i]->isCollideBonus(pHero)) {
			bonuses.erase(bonuses.begin() + i);
		}
	}
	pBackground->drawBackground(this);
	for (auto a : movingobjects) {
		a->draw(this);
	}
	for (int i = 0; i < bonuses.size(); i++) {
		bonuses[i]->draw();
	}
	return true;
}
