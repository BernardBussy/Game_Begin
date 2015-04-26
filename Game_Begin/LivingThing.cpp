#include "LivingThing.h"
//Constructors and Destructors
LivingThing::LivingThing()
{
}
LivingThing::~LivingThing()
{
}
//Get and Set
int LivingThing::getXpos()
{
	return x_pos;
}
void LivingThing::setXpos(int x)
{
	x_pos = x;
}
int LivingThing::getYpos()
{
	return y_pos;
}
void LivingThing::setYpos(int y)
{
	y_pos = y;
}
int LivingThing::getLife()
{
	return life;
}
void LivingThing::setLife(int lfe)
{
	life = lfe;
}
int LivingThing::getSpeed()
{
	return speed;
}
void LivingThing::setSpeed(int spd)
{
	speed = spd;
}
int LivingThing::getMaxXPos()
{
	return maxXPos;

}
void LivingThing::setMaxXPos(int max)
{
	maxXPos = max;
}
int LivingThing::getMaxYPos()
{
	return maxYPos;
}
void LivingThing::setMaxYPos(int max)
{
	maxYPos = max;
}
void LivingThing::setFrameWidth(int width)
{
	frameWidth = width;
}
int LivingThing::getFrameWidth()
{
	return frameWidth;
}
void LivingThing::setFrameHeight(int height)
{
	frameHeight = height;
}
int LivingThing::getFrameHeight()
{
	return frameHeight;
}

//Functions
void LivingThing::Update(int Horizontal_Move, int Verticle_Move, int damaged)
{
	UpdatePosition(Horizontal_Move, Verticle_Move);

}

void LivingThing::UpdatePosition(int &Horizontal, int &Vertical)
{
	if ((!(x_pos + speed*Horizontal >= (maxXPos - frameWidth))) && (!(x_pos + speed*Horizontal <= (frameWidth/2))))
	{
		x_pos += speed*Horizontal;
	}
	if ((!(y_pos + speed*Vertical >= (maxYPos - frameHeight))) && (!(y_pos + speed*Vertical <= (frameHeight/2))))
	{
		y_pos += speed*Vertical;
	}
	
}

void LivingThing::draw()
{
}