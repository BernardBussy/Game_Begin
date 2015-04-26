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

void LivingThing::Update(int Horizontal_Move, int Verticle_Move, int damaged)
{
	UpdatePosition(Horizontal_Move, Verticle_Move);

}

void LivingThing::UpdatePosition(int &Horizontal, int &Vertical)
{
	x_pos += speed*Horizontal;
	y_pos += speed*Vertical;
}

void LivingThing::draw()
{
}