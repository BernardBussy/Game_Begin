#pragma once
#include "LivingThing.h"
class Bullet :
	public LivingThing
{
public:
	Bullet();
	~Bullet();
private:
	bool live;
};

