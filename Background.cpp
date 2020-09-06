#pragma once
#include "Background.h"
#include "olcSimpleEngine.h"
#include "ShootingGame.h"
Background::Background() {
	for (int i = 0; i < 7; ++i)
		levelSprites.push_back(make_shared<olc::Sprite>("Sprites/Level" + to_string(i + 1) + ".png"));
}

void Background::drawEnding(ShootingGame* Game) {
	Game->DrawSprite(0, 0, deadSprite, 1);
	Game->DrawString(Game->ScreenWidth() / 2 - 38, Game->ScreenHeight() / 2 - 10, "GAME OVER", olc::DARK_RED);
	Game->DrawString(Game->ScreenWidth() / 2 - 38, Game->ScreenHeight() / 2, "Try again?", olc::BLACK);
	Game->DrawString(Game->ScreenWidth() / 2 - 35, Game->ScreenHeight() / 2 + 10, "Press Y", olc::BLACK);
	Game->DrawString(Game->ScreenWidth() / 2 - 55, Game->ScreenHeight() / 2 + 20, "Press N to exit", olc::BLACK);
}
void Background::drawBackground(ShootingGame* Game) {
	Game->Clear(olc::BLACK);
	Game->DrawSprite(0, 0, levelSprites[level - 1], 1);
	Game->SetPixelMode(olc::Pixel::ALPHA);
}
void Background::changeLevel(float fElapsedTime) {
	gameTime += fElapsedTime;
	level = int(gameTime / 10) % 7 + 1;
}


