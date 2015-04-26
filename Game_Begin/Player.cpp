#include "Player.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

//Allegro Initialisations



Player::Player(int x, int y, int lfe, int spd, int maxH, int maxW)
{
	setLife(lfe);
	setSpeed(spd);
	setXpos(x);
	setYpos(y);
	setScore();
	setMaxXPos(maxW);
	setMaxYPos(maxH);


	//Animation Initialisation
	setFrameHeight(32);
	setFrameWidth(32);
	curFrame = 0;
	frameCount = 12;
	frameDelay = 5;
	al_init();
	al_init_image_addon();
	playerSpriteSheet = al_load_bitmap("player_sprite.png");

}

Player::~Player()
{
}

//Get and Set Functions
void Player::setScore(int scr)
{
	score = scr;
}
int Player::getScore()
{
	return score;
}

void Player::setDirection(int dir)
{
	direction = dir;
}
int Player::getDirection()
{
	return direction;
}

//General Functions
void Player::draw()
{
	al_draw_bitmap_region(playerSpriteSheet, curFrame*getFrameWidth(), direction*getFrameHeight(), getFrameWidth(), getFrameHeight(), getXpos(), getYpos(), 0);
}
void Player::updateanimation(int dir)
{
	setDirection(dir);
	if (++frameCount >= frameDelay)
	{
		if (++curFrame >= maxFrame)
			curFrame = 0;
		frameCount = 0;
	}
}
