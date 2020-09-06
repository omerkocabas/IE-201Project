#pragma once
#include "olcSimpleEngine.h"
using namespace std;
class ShootingGame;
class Background {
private:
	int level;
	double gameTime{ 0 };
	vector<shared_ptr<olc::Sprite>> levelSprites;
	shared_ptr<olc::Sprite> deadSprite = make_shared<olc::Sprite>("Sprites/Dead.png");
public:
	Background();
	void drawEnding(ShootingGame* Game);
	void drawBackground(ShootingGame* Game);
	void changeLevel(float fElapsedTime);
};
