#pragma once
#include "LivingThing.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
class Player :
	public LivingThing
{
public:
	Player(int x, int y, int lfe, int spd, int maxH, int maxW);
	~Player();
	//Get and Set Functions
	void setScore(int = 0);
	int getScore();
	
	int getDirection();
	void setDirection(int);

	//General Functions
	void draw();
	void updateanimation(int);
private:
	int score;


	//Animation Variables
	const int maxFrame = 8;
	int direction;
	int curFrame;
	int frameDelay;
	int frameCount;
	ALLEGRO_BITMAP *playerSpriteSheet;
};

